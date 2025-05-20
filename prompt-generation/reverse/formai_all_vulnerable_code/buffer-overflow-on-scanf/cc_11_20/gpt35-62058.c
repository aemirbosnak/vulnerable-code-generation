//FormAI DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
   int m1[10][10], m2[10][10], sum[10][10];
   int row, col, i, j;

   printf("Enter number of rows and columns of matrix (max 10): ");
   scanf("%d %d", &row, &col);

   printf("Enter elements of matrix 1:\n");
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         scanf("%d", &m1[i][j]);
      }
   }

   printf("Enter elements of matrix 2:\n");
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         scanf("%d", &m2[i][j]);
      }
   }

   //Matrix Addition
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         sum[i][j] = m1[i][j] + m2[i][j];
      }
   }
   
   //Matrix Subtraction
   int sub[10][10];
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         sub[i][j] = m1[i][j] - m2[i][j];
      }
   }

   //Matrix Multiplication
   int k;
   int mult[10][10];
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         mult[i][j] = 0;
         for (k = 0; k < col; k++) {
            mult[i][j] += m1[i][k] * m2[k][j];
         }
      }
   }

   //Display Result
   printf("\nSum of matrices:\n");
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         printf("%d\t", sum[i][j]);
      }
      printf("\n");
   }

   printf("\nSubtraction of matrices:\n");
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         printf("%d\t", sub[i][j]);
      }
      printf("\n");
   }

   printf("\nMultiplication of matrices:\n");
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         printf("%d\t", mult[i][j]);
      }
      printf("\n");
   }

   return 0;
}