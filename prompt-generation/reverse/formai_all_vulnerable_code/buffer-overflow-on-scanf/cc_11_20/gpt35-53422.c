//FormAI DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  
   int rows, columns, i, j;
   printf("Oh my goodness, I can't believe you're running my Matrix program!\n");

   printf("How many rows do you want in the matrix? (Please enter an integer value)\n");
   scanf("%d", &rows);

   printf("How many columns do you want in the matrix? (Please enter an integer value)\n");
   scanf("%d", &columns);

   int **matrix;  
   matrix = (int **)malloc(rows * sizeof(int *));
   
   if (matrix == NULL) {
      printf("Oh no, there was an error allocating memory for the matrix!\n");
      return 1;
   }
   
   for (i = 0; i < rows; i++) {
      matrix[i] = (int *)malloc(columns * sizeof(int));
      if (matrix[i] == NULL) {
         printf("Oh dear, there was an error allocating memory for row %d of the matrix!\n", i);
         return 1;
      }
   }
   
   printf("Great job! Now let's fill the matrix with some numbers!\n");
   
   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++) {
         printf("Please enter a value for element (%d,%d): ", i, j);
         scanf("%d", &matrix[i][j]);
      }
   }
   
   printf("Fantastic! Here is your matrix:\n");
   
   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
   
   int scalar;
   printf("WOW, let's add a scalar to the matrix! Please enter an integer value for the scalar:\n");
   scanf("%d", &scalar);
   
   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++) {
         matrix[i][j] += scalar;
      }
   }
   
   printf("Incredible! Here is your new matrix after adding the scalar:\n");
   
   for (i = 0; i < rows; i++) {
      for (j = 0; j < columns; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
   
   for (i = 0; i < rows; i++) {
      free(matrix[i]);
   }
   free(matrix);

   printf("Amazing, we're all done! Have a great day!\n");
   
   return 0;
}