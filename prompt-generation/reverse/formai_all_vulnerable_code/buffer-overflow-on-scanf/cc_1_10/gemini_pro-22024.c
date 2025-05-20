//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the matrices
#define MAX_SIZE 100

// Define the data type of the matrices
typedef int matrix[MAX_SIZE][MAX_SIZE];

// Function to read a matrix from the user
void read_matrix(matrix m, int n) {
  int i, j;
  printf("Enter the elements of the matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &m[i][j]);
    }
  }
}

// Function to print a matrix
void print_matrix(matrix m, int n) {
  int i, j;
  printf("The matrix is:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void add_matrices(matrix m1, matrix m2, matrix result, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      result[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

// Function to subtract two matrices
void subtract_matrices(matrix m1, matrix m2, matrix result, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      result[i][j] = m1[i][j] - m2[i][j];
    }
  }
}

// Function to multiply two matrices
void multiply_matrices(matrix m1, matrix m2, matrix result, int n) {
  int i, j, k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      result[i][j] = 0;
      for (k = 0; k < n; k++) {
        result[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}

// Main function
int main() {
  int n;
  matrix m1, m2, result;

  // Read the size of the matrices
  printf("Enter the size of the matrices:\n");
  scanf("%d", &n);

  // Read the first matrix
  printf("Enter the elements of the first matrix:\n");
  read_matrix(m1, n);

  // Read the second matrix
  printf("Enter the elements of the second matrix:\n");
  read_matrix(m2, n);

  // Add the two matrices
  add_matrices(m1, m2, result, n);

  // Print the result of the addition
  printf("The sum of the two matrices is:\n");
  print_matrix(result, n);

  // Subtract the two matrices
  subtract_matrices(m1, m2, result, n);

  // Print the result of the subtraction
  printf("The difference of the two matrices is:\n");
  print_matrix(result, n);

  // Multiply the two matrices
  multiply_matrices(m1, m2, result, n);

  // Print the result of the multiplication
  printf("The product of the two matrices is:\n");
  print_matrix(result, n);

  return 0;
}