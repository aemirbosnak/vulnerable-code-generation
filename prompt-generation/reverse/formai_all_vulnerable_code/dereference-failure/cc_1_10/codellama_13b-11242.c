//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
// Matrix Operations Example Program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a matrix structure
typedef struct {
  int rows;
  int cols;
  double *data;
} Matrix;

// Function to initialize a matrix
Matrix initMatrix(int rows, int cols) {
  Matrix mat;
  mat.rows = rows;
  mat.cols = cols;
  mat.data = (double *)malloc(rows * cols * sizeof(double));
  return mat;
}

// Function to print a matrix
void printMatrix(Matrix mat) {
  for (int i = 0; i < mat.rows; i++) {
    for (int j = 0; j < mat.cols; j++) {
      printf("%lf ", mat.data[i * mat.cols + j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
Matrix addMatrices(Matrix mat1, Matrix mat2) {
  Matrix result = initMatrix(mat1.rows, mat1.cols);
  for (int i = 0; i < mat1.rows; i++) {
    for (int j = 0; j < mat1.cols; j++) {
      result.data[i * mat1.cols + j] = mat1.data[i * mat1.cols + j] + mat2.data[i * mat2.cols + j];
    }
  }
  return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(Matrix mat1, Matrix mat2) {
  Matrix result = initMatrix(mat1.rows, mat2.cols);
  for (int i = 0; i < mat1.rows; i++) {
    for (int j = 0; j < mat2.cols; j++) {
      double sum = 0;
      for (int k = 0; k < mat1.cols; k++) {
        sum += mat1.data[i * mat1.cols + k] * mat2.data[k * mat2.cols + j];
      }
      result.data[i * mat2.cols + j] = sum;
    }
  }
  return result;
}

// Function to transpose a matrix
Matrix transposeMatrix(Matrix mat) {
  Matrix result = initMatrix(mat.cols, mat.rows);
  for (int i = 0; i < mat.rows; i++) {
    for (int j = 0; j < mat.cols; j++) {
      result.data[j * mat.rows + i] = mat.data[i * mat.cols + j];
    }
  }
  return result;
}

int main() {
  // Initialize two matrices
  Matrix mat1 = initMatrix(2, 3);
  Matrix mat2 = initMatrix(2, 3);

  // Fill the matrices with values
  mat1.data[0] = 1;
  mat1.data[1] = 2;
  mat1.data[2] = 3;
  mat1.data[3] = 4;
  mat1.data[4] = 5;
  mat1.data[5] = 6;

  mat2.data[0] = 7;
  mat2.data[1] = 8;
  mat2.data[2] = 9;
  mat2.data[3] = 10;
  mat2.data[4] = 11;
  mat2.data[5] = 12;

  // Print the matrices
  printf("Matrix 1:\n");
  printMatrix(mat1);
  printf("\n");

  printf("Matrix 2:\n");
  printMatrix(mat2);
  printf("\n");

  // Add the matrices
  Matrix mat3 = addMatrices(mat1, mat2);
  printf("Matrix 1 + Matrix 2:\n");
  printMatrix(mat3);
  printf("\n");

  // Multiply the matrices
  Matrix mat4 = multiplyMatrices(mat1, mat2);
  printf("Matrix 1 x Matrix 2:\n");
  printMatrix(mat4);
  printf("\n");

  // Transpose the matrices
  Matrix mat5 = transposeMatrix(mat1);
  Matrix mat6 = transposeMatrix(mat2);
  printf("Transpose Matrix 1:\n");
  printMatrix(mat5);
  printf("\n");

  printf("Transpose Matrix 2:\n");
  printMatrix(mat6);
  printf("\n");

  return 0;
}