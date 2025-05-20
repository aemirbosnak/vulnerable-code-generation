//FormAI DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows, cols, i, j;
  
  // Get the number of rows and columns for the matrix
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  // Allocate memory dynamically for the matrix
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the matrix with random values from 0 to 9
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix[i][j] = rand() % 10;
    }
  }

  // Print the matrix
  printf("\nOriginal Matrix:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }

  // Transpose the matrix
  for (i = 0; i < rows; i++) {
    for (j = i+1; j < cols; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }

  // Print the transposed matrix
  printf("\nTransposed Matrix:\n");
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf("%d\t", matrix[j][i]);
    }
    printf("\n");
  }

  // Find the sum of each row in the matrix
  int sum[rows];
  for (i = 0; i < rows; i++) {
    sum[i] = 0;
    for (j = 0; j < cols; j++) {
      sum[i] += matrix[i][j];
    }
  }

  // Print the sum of each row in the matrix
  printf("\nRow Sum:\n");
  for (i = 0; i < rows; i++) {
    printf("%d\n", sum[i]);
  }

  // Free the dynamically allocated memory
  for (i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}