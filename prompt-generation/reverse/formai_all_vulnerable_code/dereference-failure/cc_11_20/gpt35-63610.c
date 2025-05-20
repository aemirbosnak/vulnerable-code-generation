//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare variables and initialize
  int rows = 3, cols = 3;
  int i, j, k, sum;

  // Allocate memory for 2D array
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  // Populate array with random values
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix[i][j] = rand() % 10;
    }
  }

  // Print matrix
  printf("Matrix:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Find determinant of matrix
  int det = 0;
  for (i = 0; i < rows; i++) {
    det = det + (matrix[0][i] * (matrix[1][(i+1)%3] * matrix[2][(i+2)%3] - matrix[1][(i+2)%3] * matrix[2][(i+1)%3]));
  }
  printf("Determinant of matrix: %d\n", det);

  // Find inverse of matrix
  int inv[3][3];
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      inv[i][j] = 0;
      for (k = 0; k < rows; k++) {
        sum = matrix[i][k] * matrix[k][j];
        inv[i][j] = inv[i][j] + sum;
      }
    }
  }
  printf("Inverse of matrix:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d ", inv[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}