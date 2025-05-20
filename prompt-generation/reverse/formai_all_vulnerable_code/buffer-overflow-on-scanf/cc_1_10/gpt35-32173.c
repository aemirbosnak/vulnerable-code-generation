//FormAI DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows, cols;
  printf("Enter number of rows of the matrix: ");
  scanf("%d", &rows);
  printf("Enter number of columns of the matrix: ");
  scanf("%d", &cols);

  // Allocate memory for the matrix
  int **matrix = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int*)malloc(cols * sizeof(int));
  }

  // Initialize the matrix with user input
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter value at (%d, %d): ", i+1, j+1);
      scanf("%d", &matrix[i][j]);
    }
  }

  // Calculate the sum of each row
  int *row_sum = (int*)malloc(rows * sizeof(int));
  for (int i = 0; i < rows; i++) {
    row_sum[i] = 0;
    for (int j = 0; j < cols; j++) {
      row_sum[i] += matrix[i][j];
    }
  }

  // Print the matrix and row sums
  printf("\nMatrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("Row sums: ");
  for (int i = 0; i < rows; i++) {
    printf("%d ", row_sum[i]);
  }
  printf("\n");

  // Free allocated memory
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
  free(row_sum);

  return 0;
}