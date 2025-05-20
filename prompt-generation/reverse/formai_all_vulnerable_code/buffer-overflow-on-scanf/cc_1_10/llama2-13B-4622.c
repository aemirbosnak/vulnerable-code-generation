//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Matrix operations
void matrix_invasion(int **mat, int row, int col) {
  int i, j, k;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      // Invade the matrix with a randomly chosen value
      mat[i][j] = (i + j) % 10;

      // Invade the neighboring cells
      if (i > 0) {
        mat[i - 1][j] = mat[i][j];
      }
      if (i < row - 1) {
        mat[i + 1][j] = mat[i][j];
      }
      if (j > 0) {
        mat[i][j - 1] = mat[i][j];
      }
      if (j < col - 1) {
        mat[i][j + 1] = mat[i][j];
      }
    }
  }
}

int main() {
  int row, col;
  printf("Enter the row and column of the matrix: ");
  scanf("%d%d", &row, &col);

  int **mat = malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++) {
    mat[i] = malloc(col * sizeof(int));
  }

  // Initialize the matrix with some random values
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      mat[i][j] = (i + j) % 10;
    }
  }

  // Invade the matrix
  matrix_invasion(mat, row, col);

  // Print the invaded matrix
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }

  return 0;
}