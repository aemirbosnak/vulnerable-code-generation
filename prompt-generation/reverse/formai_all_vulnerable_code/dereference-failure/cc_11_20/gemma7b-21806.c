//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Variables
  int **a = NULL, **b = NULL, **c = NULL;
  int rows = 3, cols = 3;

  // Allocate memory
  a = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    a[i] = (int*)malloc(cols * sizeof(int));
  }

  // Initialize the matrix
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      a[r][c] = r + c;
    }
  }

  // Transpose the matrix
  b = (int**)malloc(cols * sizeof(int*));
  for (int i = 0; i < cols; i++) {
    b[i] = (int*)malloc(rows * sizeof(int));
  }

  for (int r = 0; r < cols; r++) {
    for (int c = 0; c < rows; c++) {
      b[r][c] = a[c][r];
    }
  }

  // Print the transposed matrix
  for (int r = 0; r < cols; r++) {
    for (int c = 0; c < rows; c++) {
      printf("%d ", b[r][c]);
    }
    printf("\n");
  }

  // Free memory
  for (int r = 0; r < rows; r++) {
    free(a[r]);
  }
  free(a);

  for (int r = 0; r < cols; r++) {
    free(b[r]);
  }
  free(b);

  return 0;
}