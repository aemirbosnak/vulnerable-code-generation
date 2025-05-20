//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

int main() {
  // Declare and initialize the matrix
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  // Print the original matrix
  printf("Original matrix:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Transpose the matrix
  int transpose[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      transpose[j][i] = matrix[i][j];
    }
  }

  // Print the transposed matrix
  printf("Transposed matrix:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", transpose[i][j]);
    }
    printf("\n");
  }

  // Multiply the original matrix by itself
  int result[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        result[i][j] += matrix[i][k] * matrix[k][j];
      }
    }
  }

  // Print the resulting matrix
  printf("Resulting matrix:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}