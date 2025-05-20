//FormAI DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
   int arr[5][5], i, j, rows, cols, min, max, sum = 0;

   printf("Enter the number of rows (maximum 5): ");
   scanf("%d", &rows);

   printf("Enter the number of columns (maximum 5): ");
   scanf("%d", &cols);

   if (rows > 5) {
      printf("Maximum number of rows exceeded.\n");
      return 0;
   }

   if (cols > 5) {
      printf("Maximum number of columns exceeded.\n");
      return 0;
   }

   for (i = 0; i < rows; i++) {    // read the matrix from user input
      for (j = 0; j < cols; j++) {
         printf("Enter element (%d,%d): ", i+1, j+1);
         scanf("%d", &arr[i][j]);
      }
   }

   printf("\n");

   // display original matrix
   printf("Original Matrix:\n");
   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         printf("%d ", arr[i][j]);
      }
      printf("\n");
   }

   // find the minimum and maximum element from the matrix
   min = max = arr[0][0];

   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         if (arr[i][j] > max) {
            max = arr[i][j];
         } 

         if (arr[i][j] < min) {
            min = arr[i][j];
         }

         sum += arr[i][j]; // calculate sum of elements
      }
   }

   // display minimum and maximum elements
   printf("\nMinimum element in matrix: %d\n", min);
   printf("Maximum element in matrix: %d\n", max);
   
   float avg = (float)sum / (rows * cols); // calculate average
   printf("Average of elements in matrix: %.2f\n", avg);

   return 0;
}