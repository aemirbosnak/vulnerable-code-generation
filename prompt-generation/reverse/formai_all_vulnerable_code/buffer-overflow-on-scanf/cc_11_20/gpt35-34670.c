//FormAI DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
  int rows, cols, i, j;
 
  // Read rows and columns from user
  printf("Enter number of rows and columns separated by space (e.g. 3 3): ");
  scanf("%d %d", &rows, &cols);
 
  // Allocate memory for matrix
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }
 
  // Read values for each element
  printf("Enter values for each element of the matrix:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
 
  // Display the matrix
  printf("The input matrix is:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
 
  // Transpose the matrix
  for (i = 0; i < rows; i++) {
    for (j = i + 1; j < cols; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
 
  // Display the transposed matrix
  printf("The transposed matrix is:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
 
  // Free the memory
  for (i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
 
  return 0;
}