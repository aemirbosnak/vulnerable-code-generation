//FormAI DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {

   int matrix_A[10][10], matrix_B[10][10], matrix_Result[10][10];
   int i, j, k, rows_A, columns_A, rows_B, columns_B;

   printf("Enter number of rows for matrix A: ");
   scanf("%d", &rows_A);
   printf("Enter number of columns for matrix A: ");
   scanf("%d", &columns_A);

   for (i=0; i<rows_A; i++) {
      for (j=0; j<columns_A; j++) {
         printf("Enter matrix A[%d][%d]: ", i+1, j+1);
         scanf("%d", &matrix_A[i][j]);
      }
   }

   printf("\nEnter number of rows for matrix B: ");
   scanf("%d", &rows_B);
   printf("Enter number of columns for matrix B: ");
   scanf("%d", &columns_B);

   for (i=0; i<rows_B; i++) {
      for (j=0; j<columns_B; j++) {
         printf("Enter matrix B[%d][%d]: ", i+1, j+1);
         scanf("%d", &matrix_B[i][j]);
      }
   }

   // Matrix Addition
   if (rows_A == rows_B && columns_A == columns_B) {
      for (i=0; i<rows_A; i++) {
         for (j=0; j<columns_A; j++) {
            matrix_Result[i][j] = matrix_A[i][j] + matrix_B[i][j];
         }
      }

      printf("\nMatrix Addition: (A + B)\n");
      for (i=0; i<rows_A; i++) {
         for (j=0; j<columns_A; j++) {
            printf("%d\t", matrix_Result[i][j]);
         }
         printf("\n");
      }
   }
   else {
      printf("\nMatrix Addition is not possible! (Rows and Columns of A and B must be same)\n");
   }

   // Matrix Multiplication
   if (columns_A == rows_B) {
      for (i=0; i<rows_A; i++) {
         for (j=0; j<columns_B; j++) {
            matrix_Result[i][j] = 0;
            for (k=0; k<columns_A; k++) {
               matrix_Result[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
         }
      }

      printf("\nMatrix Multiplication: (A * B)\n");
      for (i=0; i<rows_A; i++) {
         for (j=0; j<columns_B; j++) {
            printf("%d\t", matrix_Result[i][j]);
         }
         printf("\n");
      }
   }
   else {
      printf("\nMatrix Multiplication is not possible! (Columns of A must be equal to Rows of B)\n");
   }

   return 0;
}