//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>

int main() {

   int rows, columns, i, j;
   int firstMatrix[10][10], secondMatrix[10][10], sumMatrix[10][10];

   printf("Enter the number of rows and columns for the matrices: ");
   scanf("%d %d", &rows, &columns);

   printf("\nEnter the elements of the first matrix:\n");
   for (i = 0; i < rows; i++)
      for (j = 0; j < columns; j++)
         scanf("%d", &firstMatrix[i][j]);

   printf("\nEnter the elements of the second matrix:\n");
   for (i = 0; i < rows; i++)
      for (j = 0; j < columns; j++)
         scanf("%d", &secondMatrix[i][j]);

   // Addition
   for (i = 0; i < rows; i++)
      for (j = 0; j < columns; j++)
         sumMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];

   printf("\nResult of addition of matrices:\n");
   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++)
         printf("%d ", sumMatrix[i][j]);
      printf("\n");
   }

   // Multiplication
   int productMatrix[10][10];
   int k;

   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++) {
         productMatrix[i][j] = 0;
         for (k = 0; k < columns; k++) {
            productMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
         }
      }
   }

   printf("\nResult of multiplication of matrices:\n");
   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++)
         printf("%d ", productMatrix[i][j]);
      printf("\n");
   }

   // Transpose
   int transposeMatrix[10][10];

   for (i = 0; i < rows; i++)
      for (j = 0; j < columns; j++)
         transposeMatrix[j][i] = firstMatrix[i][j];

   printf("\nTranspose of the first matrix:\n");
   for (i = 0; i < columns; i++) {
      for (j = 0; j < rows; j++)
         printf("%d ", transposeMatrix[i][j]);
      printf("\n");
   }

   return 0;
}