//FormAI DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// Function prototypes
void initialize_matrix(int matrix[][COLS]);
void print_matrix(int matrix[][COLS]);
int determinant(int matrix[][COLS], int size);
void transpose(int matrix[][COLS]);
void multiply(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]);

int main() {
  int matrix1[ROWS][COLS], matrix2[ROWS][COLS];
  int result_matrix[ROWS][COLS], det;

  // Initialize matrices
  initialize_matrix(matrix1);
  initialize_matrix(matrix2);

  // Print matrices
  printf("Matrix 1:\n");
  print_matrix(matrix1);

  printf("\nMatrix 2:\n");
  print_matrix(matrix2);

  // Calculate determinant of matrix1
  det = determinant(matrix1, ROWS);
  printf("\nDeterminant of matrix1 = %d\n", det);

  // Transpose matrix2
  printf("\nTranspose of matrix2:\n");
  transpose(matrix2);
  print_matrix(matrix2);

  // Multiply matrix1 and matrix2
  printf("\nMultiplication of matrix1 and matrix2:\n");
  multiply(matrix1, matrix2, result_matrix);
  print_matrix(result_matrix);

  return 0;
}

// Function to initialize a matrix with random values
void initialize_matrix(int matrix[][COLS]) {
  int i, j;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      // Initialize with random value between 1 and 10
      matrix[i][j] = rand() % 10 + 1;
    }
  }
}

// Function to print a matrix
void print_matrix(int matrix[][COLS]) {
  int i, j;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to calculate determinant of a matrix
int determinant(int matrix[][COLS], int size) {
  int det = 0;
  int sub_matrix[ROWS][COLS];
  int i, j, k, sign = 1;

  if (size == 1) {
    return matrix[0][0];
  } else {
    for (i = 0; i < size; i++) {
      // Construct sub_matrix excluding first row and column of current element
      k = 0;
      for (j = 1; j < size; j++) {
        sub_matrix[j - 1][k] = matrix[j][i];
        k++;
      }
      // Calculate determinant recursively
      det += sign * matrix[0][i] * determinant(sub_matrix, size - 1);
      sign = -sign; // Flip sign for next element
    }
  }
  return det;
}

// Function to transpose a matrix
void transpose(int matrix[][COLS]) {
  int temp;
  int i, j;

  for (i = 0; i < ROWS; i++) {
    for (j = i; j < COLS; j++) {
      // Swap matrix[i][j] with matrix[j][i]
      temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}

// Function to multiply two matrices
void multiply(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS]) {
  int i, j, k;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      result[i][j] = 0;
      for (k = 0; k < COLS; k++) {
        // Calculate dot product of corresponding row and column
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}