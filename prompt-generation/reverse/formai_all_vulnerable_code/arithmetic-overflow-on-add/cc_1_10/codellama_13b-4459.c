//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: introspective
// Matrix operations example program
#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
int **addMatrices(int **matrix1, int **matrix2, int rows, int cols) {
  int **result = malloc(sizeof(int *) * rows);
  for (int i = 0; i < rows; i++) {
    result[i] = malloc(sizeof(int) * cols);
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  return result;
}

// Function to multiply two matrices
int **multiplyMatrices(int **matrix1, int **matrix2, int rows, int cols) {
  int **result = malloc(sizeof(int *) * rows);
  for (int i = 0; i < rows; i++) {
    result[i] = malloc(sizeof(int) * cols);
    for (int j = 0; j < cols; j++) {
      result[i][j] = 0;
      for (int k = 0; k < cols; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return result;
}

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Driver function
int main() {
  int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

  // Add matrices
  int **result1 = addMatrices(matrix1, matrix2, 3, 3);
  printf("Addition of matrices:\n");
  displayMatrix(result1, 3, 3);

  // Multiply matrices
  int **result2 = multiplyMatrices(matrix1, matrix2, 3, 3);
  printf("Multiplication of matrices:\n");
  displayMatrix(result2, 3, 3);

  return 0;
}