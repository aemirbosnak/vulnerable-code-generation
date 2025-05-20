//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the matrices
#define MAX_SIZE 100

// Define the data type of the matrices
typedef double matrix[MAX_SIZE][MAX_SIZE];

// Function to read a matrix from a file
int read_matrix(matrix m, int *n, int *p) {
  FILE *fp;
  int i, j;

  // Open the file
  fp = fopen("matrix.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return -1;
  }

  // Read the number of rows and columns
  fscanf(fp, "%d %d", n, p);

  // Read the matrix elements
  for (i = 0; i < *n; i++) {
    for (j = 0; j < *p; j++) {
      fscanf(fp, "%lf", &m[i][j]);
    }
  }

  // Close the file
  fclose(fp);

  return 0;
}

// Function to print a matrix
void print_matrix(matrix m, int n, int p) {
  int i, j;

  // Print the matrix elements
  for (i = 0; i < n; i++) {
    for (j = 0; j < p; j++) {
      printf("%lf ", m[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void add_matrices(matrix m1, matrix m2, matrix result, int n, int p) {
  int i, j;

  // Add the corresponding elements of the two matrices
  for (i = 0; i < n; i++) {
    for (j = 0; j < p; j++) {
      result[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

// Function to subtract two matrices
void subtract_matrices(matrix m1, matrix m2, matrix result, int n, int p) {
  int i, j;

  // Subtract the corresponding elements of the two matrices
  for (i = 0; i < n; i++) {
    for (j = 0; j < p; j++) {
      result[i][j] = m1[i][j] - m2[i][j];
    }
  }
}

// Function to multiply two matrices
void multiply_matrices(matrix m1, matrix m2, matrix result, int n, int p, int q) {
  int i, j, k;

  // Multiply the corresponding elements of the two matrices
  for (i = 0; i < n; i++) {
    for (j = 0; j < q; j++) {
      result[i][j] = 0;
      for (k = 0; k < p; k++) {
        result[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}

// Main function
int main() {
  int n, p, q;
  matrix m1, m2, result;

  // Read the first matrix from a file
  if (read_matrix(m1, &n, &p) != 0) {
    printf("Error reading matrix.\n");
    return -1;
  }

  // Print the first matrix
  printf("First matrix:\n");
  print_matrix(m1, n, p);

  // Read the second matrix from a file
  if (read_matrix(m2, &n, &p) != 0) {
    printf("Error reading matrix.\n");
    return -1;
  }

  // Print the second matrix
  printf("Second matrix:\n");
  print_matrix(m2, n, p);

  // Add the two matrices
  add_matrices(m1, m2, result, n, p);

  // Print the result of the addition
  printf("Result of addition:\n");
  print_matrix(result, n, p);

  // Subtract the two matrices
  subtract_matrices(m1, m2, result, n, p);

  // Print the result of the subtraction
  printf("Result of subtraction:\n");
  print_matrix(result, n, p);

  // Multiply the two matrices
  multiply_matrices(m1, m2, result, n, p, q);

  // Print the result of the multiplication
  printf("Result of multiplication:\n");
  print_matrix(result, n, q);

  return 0;
}