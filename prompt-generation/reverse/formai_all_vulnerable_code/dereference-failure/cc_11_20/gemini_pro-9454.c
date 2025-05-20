//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n, i, j, k, l, m;

  srand((unsigned int)time(NULL));  // Initialize random number generator

  printf("Enter the number of rows and columns: ");
  scanf("%d", &n);

  int **matrix = (int **)malloc(n * sizeof(int *));  // Allocate memory for the matrix
  for (i = 0; i < n; i++) {
    matrix[i] = (int *)malloc(n * sizeof(int));
  }

  // Initialize the matrix with random numbers
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrix[i][j] = rand() % 100;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Find the maximum element in each row
  int max_row[n];
  for (i = 0; i < n; i++) {
    max_row[i] = matrix[i][0];
    for (j = 1; j < n; j++) {
      if (matrix[i][j] > max_row[i]) {
        max_row[i] = matrix[i][j];
      }
    }
  }

  // Find the minimum element in each column
  int min_col[n];
  for (i = 0; i < n; i++) {
    min_col[i] = matrix[0][i];
    for (j = 1; j < n; j++) {
      if (matrix[j][i] < min_col[i]) {
        min_col[i] = matrix[j][i];
      }
    }
  }

  // Print the maximum elements in each row and minimum elements in each column
  printf("\nMaximum elements in each row:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", max_row[i]);
  }
  printf("\n\nMinimum elements in each column:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", min_col[i]);
  }
  printf("\n");

  // Free the memory allocated for the matrix
  for (i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}