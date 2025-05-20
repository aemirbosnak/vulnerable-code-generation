//FormAI DATASET v1.0 Category: Educational ; Style: future-proof
// This program calculates the sum of two matrices using dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>

int main() {
   int row, col, i, j;
   
   printf("Enter the number of rows and columns of the matrices: ");
   scanf("%d %d", &row, &col);

   // allocate memory for matrices a and b
   int **a = (int **) malloc(row * sizeof(int *));
   for (i = 0; i < row; i++) {
      a[i] = (int *) malloc(col * sizeof(int));
   }
   int **b = (int **) malloc(row * sizeof(int *));
   for (i = 0; i < row; i++) {
      b[i] = (int *) malloc(col * sizeof(int));
   }

   // initialize matrix a
   printf("\nEnter elements of first matrix:\n");
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         scanf("%d", &a[i][j]);
      }
   }

   //initialize matrix b
   printf("\nEnter elements of second matrix:\n");
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         scanf("%d", &b[i][j]);
      }
   }

   // add matrices a and b and store result in matrix c
   int **c = (int **) malloc(row * sizeof(int *));
   for (i = 0; i < row; i++) {
      c[i] = (int *) malloc(col * sizeof(int));
   }  
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         c[i][j] = a[i][j] + b[i][j];
      }
   }

   // print the results
   printf("\nResultant matrix: \n");
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         printf("%d ", c[i][j]);
      }
      printf("\n");
   }

   // free memory
   for (i = 0; i < row; i++) {
      free(a[i]);
      free(b[i]);
      free(c[i]);
   }
   free(a);
   free(b);
   free(c);

   return 0;
}