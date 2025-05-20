//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: thoughtful
/*
 * Matrix Operations Example Program
 *
 * This program demonstrates some common matrix operations in C.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to multiply two matrices
int **matrix_multiply(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
  int **result = (int **)malloc(rows1 * sizeof(int *));
  for (int i = 0; i < rows1; i++) {
    result[i] = (int *)malloc(cols2 * sizeof(int));
    for (int j = 0; j < cols2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < cols1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return result;
}

// Function to transpose a matrix
int **matrix_transpose(int **matrix, int rows, int cols) {
  int **result = (int **)malloc(cols * sizeof(int *));
  for (int i = 0; i < cols; i++) {
    result[i] = (int *)malloc(rows * sizeof(int));
    for (int j = 0; j < rows; j++) {
      result[i][j] = matrix[j][i];
    }
  }
  return result;
}

int main() {
  int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

  // Print the original matrices
  printf("Matrix 1:\n");
  print_matrix(matrix1, 3, 3);
  printf("\nMatrix 2:\n");
  print_matrix(matrix2, 3, 3);

  // Multiply the matrices
  int **result = matrix_multiply(matrix1, matrix2, 3, 3, 3, 3);

  // Print the result matrix
  printf("\nMatrix Multiplication Result:\n");
  print_matrix(result, 3, 3);

  // Transpose matrix1
  int **transpose = matrix_transpose(matrix1, 3, 3);

  // Print the transposed matrix
  printf("\nMatrix 1 Transpose:\n");
  print_matrix(transpose, 3, 3);

  // Free the memory
  for (int i = 0; i < 3; i++) {
    free(result[i]);
    free(transpose[i]);
  }
  free(result);
  free(transpose);

  return 0;
}