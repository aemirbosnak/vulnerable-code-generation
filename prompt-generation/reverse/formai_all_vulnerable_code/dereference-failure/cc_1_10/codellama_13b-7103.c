//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: secure
/*
 * C Matrix Operations Example Program
 *
 * This program demonstrates how to perform basic matrix operations in C.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a random matrix
void create_matrix(int **matrix, int rows, int cols) {
  srand(time(NULL));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = rand() % 100;
    }
  }
}

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void add_matrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

// Function to multiply two matrices
void multiply_matrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = 0;
      for (int k = 0; k < cols; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

int main() {
  int rows = 3, cols = 3;

  // Create two matrices
  int **matrix1 = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix1[i] = (int *)malloc(cols * sizeof(int));
  }
  int **matrix2 = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix2[i] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize matrices
  create_matrix(matrix1, rows, cols);
  create_matrix(matrix2, rows, cols);

  // Print matrices
  printf("Matrix 1:\n");
  print_matrix(matrix1, rows, cols);
  printf("\nMatrix 2:\n");
  print_matrix(matrix2, rows, cols);

  // Perform matrix operations
  int **result = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    result[i] = (int *)malloc(cols * sizeof(int));
  }
  add_matrices(matrix1, matrix2, result, rows, cols);
  printf("\nAddition of matrices:\n");
  print_matrix(result, rows, cols);
  multiply_matrices(matrix1, matrix2, result, rows, cols);
  printf("\nMultiplication of matrices:\n");
  print_matrix(result, rows, cols);

  // Free memory
  for (int i = 0; i < rows; i++) {
    free(matrix1[i]);
    free(matrix2[i]);
    free(result[i]);
  }
  free(matrix1);
  free(matrix2);
  free(result);

  return 0;
}