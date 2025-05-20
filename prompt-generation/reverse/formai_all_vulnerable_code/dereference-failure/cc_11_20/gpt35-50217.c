//FormAI DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m;

  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &n, &m);

  int** matrix = (int**)malloc(n * sizeof(int*)); // Allocate memory for array of pointers to rows

  for (int i = 0; i < n; i++) {
    matrix[i] = (int*)malloc(m * sizeof(int)); // Allocate memory for each row (array of integers)
  }

  printf("Enter matrix elements row by row:\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &matrix[i][j]); // Read matrix element
    }
  }

  printf("Matrix elements are:\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]); // Print matrix element
    }
    printf("\n");
  }

  int* row_sum = (int*)calloc(n, sizeof(int)); // Allocate memory for array of row sums
  int* col_sum = (int*)calloc(m, sizeof(int)); // Allocate memory for array of column sums

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      row_sum[i] += matrix[i][j]; // Calculate sum of each row
      col_sum[j] += matrix[i][j]; // Calculate sum of each column
    }
  }

  printf("Sum of each row is:\n");

  for (int i = 0; i < n; i++) {
    printf("%d ", row_sum[i]); // Print sum of each row
  }
  printf("\n");

  printf("Sum of each column is:\n");

  for (int j = 0; j < m; j++) {
    printf("%d ", col_sum[j]); // Print sum of each column
  }
  printf("\n");

  for (int i = 0; i < n; i++) {
    free(matrix[i]); // Free memory allocated for each row
  }

  free(matrix); // Free memory allocated for array of pointers to rows
  free(row_sum); // Free memory allocated for array of row sums
  free(col_sum); // Free memory allocated for array of column sums

  return 0;
}