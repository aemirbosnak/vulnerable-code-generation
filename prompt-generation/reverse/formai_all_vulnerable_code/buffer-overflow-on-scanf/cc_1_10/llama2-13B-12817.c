//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
  int rows, cols;
  printf("Enter the number of rows and columns: ");
  scanf("%dx%d", &rows, &cols);

  int **matrix;
  matrix = calloc(rows, sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = calloc(cols, sizeof(int));
  }

  int i, j, k;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix[i][j] = i * j + MAGIC_NUMBER;
    }
  }

  // Surprise! 😱
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (matrix[i][j] > 100) {
        matrix[i][j] = matrix[i][j] / 2;
      }
    }
  }

  // Now let's see what we've got... 🤔
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // And finally, let's free the memory! 💥
  for (i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}