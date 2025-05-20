//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: complex
// Example program for performing matrix operations in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define a structure for a matrix
typedef struct {
  int rows;
  int cols;
  int *data;
} Matrix;

// Define a function for creating a matrix
Matrix* create_matrix(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = malloc(rows * cols * sizeof(int));
  return matrix;
}

// Define a function for printing a matrix
void print_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->data[i * matrix->cols + j]);
    }
    printf("\n");
  }
}

// Define a function for adding two matrices
Matrix* add_matrices(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
    return NULL;
  }
  Matrix *result = create_matrix(matrix1->rows, matrix1->cols);
  for (int i = 0; i < matrix1->rows; i++) {
    for (int j = 0; j < matrix1->cols; j++) {
      result->data[i * matrix1->cols + j] = matrix1->data[i * matrix1->cols + j] + matrix2->data[i * matrix2->cols + j];
    }
  }
  return result;
}

// Define a function for multiplying two matrices
Matrix* multiply_matrices(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->cols != matrix2->rows) {
    return NULL;
  }
  Matrix *result = create_matrix(matrix1->rows, matrix2->cols);
  for (int i = 0; i < matrix1->rows; i++) {
    for (int j = 0; j < matrix2->cols; j++) {
      result->data[i * matrix2->cols + j] = 0;
      for (int k = 0; k < matrix1->cols; k++) {
        result->data[i * matrix2->cols + j] += matrix1->data[i * matrix1->cols + k] * matrix2->data[k * matrix2->cols + j];
      }
    }
  }
  return result;
}

// Define a function for transposing a matrix
Matrix* transpose_matrix(Matrix *matrix) {
  Matrix *result = create_matrix(matrix->cols, matrix->rows);
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      result->data[j * matrix->rows + i] = matrix->data[i * matrix->cols + j];
    }
  }
  return result;
}

int main() {
  // Create two matrices
  Matrix *matrix1 = create_matrix(3, 2);
  Matrix *matrix2 = create_matrix(2, 3);

  // Set the data for the matrices
  matrix1->data[0] = 1;
  matrix1->data[1] = 2;
  matrix1->data[2] = 3;
  matrix1->data[3] = 4;
  matrix1->data[4] = 5;
  matrix1->data[5] = 6;
  matrix2->data[0] = 7;
  matrix2->data[1] = 8;
  matrix2->data[2] = 9;
  matrix2->data[3] = 10;
  matrix2->data[4] = 11;
  matrix2->data[5] = 12;

  // Print the matrices
  printf("Matrix 1:\n");
  print_matrix(matrix1);
  printf("Matrix 2:\n");
  print_matrix(matrix2);

  // Add the matrices
  Matrix *result1 = add_matrices(matrix1, matrix2);
  printf("Matrix 1 + Matrix 2:\n");
  print_matrix(result1);

  // Multiply the matrices
  Matrix *result2 = multiply_matrices(matrix1, matrix2);
  printf("Matrix 1 x Matrix 2:\n");
  print_matrix(result2);

  // Transpose the matrices
  Matrix *result3 = transpose_matrix(matrix1);
  printf("Matrix 1 transposed:\n");
  print_matrix(result3);

  return 0;
}