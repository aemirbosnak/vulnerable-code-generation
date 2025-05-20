//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>

int main() {
   int matrix1[10][10], matrix2[10][10], sum[10][10];
   int i, j, rows, cols;

   printf("Enter the number of rows and columns of the matrices: ");
   scanf("%d %d", &rows, &cols);

   printf("\nEnter elements of matrix 1:\n");
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           scanf("%d", &matrix1[i][j]);
       }
   }

   printf("\nEnter elements of matrix 2:\n");
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           scanf("%d", &matrix2[i][j]);
       }
   }

   printf("\nMatrix 1 + Matrix 2 =\n");
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           sum[i][j] = matrix1[i][j] + matrix2[i][j];
           printf("%d ", sum[i][j]);
       }
       printf("\n");
   }

   printf("\nMatrix 1 - Matrix 2 =\n");
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           printf("%d ", matrix1[i][j] - matrix2[i][j]);
       }
       printf("\n");
   }

   printf("\nTransposed Matrix 1 =\n");
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           printf("%d ", matrix1[j][i]);
       }
       printf("\n");
   }

   printf("\nMatrix 1 x Matrix 2 =\n");
   int k, mult;
   for (i = 0; i < rows; i++) {
       for (j = 0; j < cols; j++) {
           mult = 0;
           for (k = 0; k < cols; k++) {
               mult += matrix1[i][k] * matrix2[k][j];
           }
           printf("%d ", mult);
       }
       printf("\n");
   }

   return 0;
}