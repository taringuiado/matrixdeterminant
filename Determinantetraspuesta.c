#include <stdio.h>
#include <math.h>
#define MAX 20
 
void mostrar_matriz(int matriz[][MAX], int f,int c);
int determinante(int matriz[][MAX], int orden);
int cofactor(int matriz[][MAX], int orden, int fila, int columna);
void traspuesta(int matriz[][MAX],int c, int f);
 
int main()
{
   int matriz[MAX][MAX];
   int f, c, i, j, orden;
   
   printf("Ingresa el orden de la matriz (maximo %d):\nFilas: ", MAX);
   scanf("%d",&f);
   printf("Columnas: ");
   scanf("%d",&c);
   while (f < 0 || f > MAX || c < 0 || c > MAX) {
   	printf("Salio de los parametros establecidos\nIngrese nuevamente el orden de la matriz:\nFilas: ");
    scanf("%d",&f);
   printf("Columnas: ");
   scanf("%d",&c);
   }
   
   printf("\nIngrese los elementos de la matriz:\n\n");
   for (i = 0; i < f; i++) {
      for (j = 0; j < c; j++) {
      	printf("(%d,%d)",i+1,j+1);
         scanf("%d", &matriz[i][j]);
      }
   }
 
   printf("\nMostrando la matriz ingresada:\n");
   mostrar_matriz(matriz, f,c);
   if (f=c) {
   orden=f;
   printf("\nEl determinante es: %d\n", determinante(matriz, orden));
   traspuesta(matriz,f,c);
   } else {
   printf ("La matriz no es cuadrar por lo tanto no se puede calcular el determinanate\n");
   traspuesta(matriz,f,c);
   }
   getchar();
   getchar();
   return 0;
}
 
void mostrar_matriz(int matriz[][MAX], int f,int c)
{
	int i, j;
	
	printf("Orden: (%d,%d)\n", f,c);
   for (i = 0; i < f; i++) {
      for (j = 0; j < c; j++) {
      	printf("\t%d", matriz[i][j]);
      }
      printf("\n");
   }
}
void traspuesta(int matriz[][MAX],int f, int c)
{
	int i, j;
	printf("La traspuesta es de orden (%d,%d)\n",c,f);
	for (i=0; i < f; i++) {
		for (j=0; j < c; j++){
			printf("\t%d",matriz[j][i]);
		}
		printf("\n");
	}
}
 
 
int determinante(int matriz[][MAX], int orden)
{
   int det = 0.0, j;
   
   if (orden == 1) {
      det = matriz[0][0];
   } else {
      for (j = 0; j < orden; j++) {
         det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
      }
   }
   
   return det;
}
 
 
int cofactor(int matriz[][MAX], int orden, int fila, int columna)
{
   int submatriz[MAX][MAX];
   int n = orden - 1;
   int i, j;
   
   int x = 0;
   int y = 0;
   for (i = 0; i < orden; i++) {
      for (j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   
   return pow(-1.0, fila + columna) * determinante(submatriz, n);
}
