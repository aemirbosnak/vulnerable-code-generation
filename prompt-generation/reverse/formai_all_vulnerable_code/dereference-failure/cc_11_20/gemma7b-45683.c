//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

void main() {
  // Matrix dimensions
  int rows = 3, cols = 4;

  // Allocate memory for the matrix
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = 0;
    }
  }

  // Perform operations
  // (1) Transpose the matrix
  int **transpose = (int **)malloc(cols * sizeof(int *));
  for (int i = 0; i < cols; i++) {
    transpose[i] = (int *)malloc(rows * sizeof(int));
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      transpose[j][i] = matrix[i][j];
    }
  }

  // (2) Add the transpose to the original matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] += transpose[j][i];
    }
  }

  // Print the modified matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Free memory
  free(matrix);
  free(transpose);
}