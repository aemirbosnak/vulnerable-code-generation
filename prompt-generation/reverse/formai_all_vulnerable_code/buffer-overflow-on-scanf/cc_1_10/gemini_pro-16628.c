//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum size of the matrices
#define MAX_SIZE 100

// Define the data type of the matrices
typedef double matrix[MAX_SIZE][MAX_SIZE];

// Function to read a matrix from the user
void read_matrix(matrix A, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%lf", &A[i][j]);
    }
  }
}

// Function to print a matrix
void print_matrix(matrix A, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%lf ", A[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void add_matrices(matrix A, matrix B, matrix C, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

// Function to subtract two matrices
void subtract_matrices(matrix A, matrix B, matrix C, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
}

// Function to multiply two matrices
void multiply_matrices(matrix A, matrix B, matrix C, int n, int m, int p) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      C[i][j] = 0;
      for (int k = 0; k < m; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

// Function to transpose a matrix
void transpose_matrix(matrix A, matrix B, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      B[i][j] = A[j][i];
    }
  }
}

// Function to find the determinant of a matrix
double determinant(matrix A, int n) {
  if (n == 1) {
    return A[0][0];
  } else if (n == 2) {
    return A[0][0] * A[1][1] - A[0][1] * A[1][0];
  } else {
    double det = 0;
    for (int i = 0; i < n; i++) {
      matrix submatrix;
      for (int j = 1; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (k < i) {
            submatrix[j - 1][k] = A[j][k];
          } else if (k > i) {
            submatrix[j - 1][k - 1] = A[j][k];
          }
        }
      }
      det += pow(-1, i) * A[0][i] * determinant(submatrix, n - 1);
    }
    return det;
  }
}

// Function to find the inverse of a matrix
void inverse_matrix(matrix A, matrix B, int n) {
  double det = determinant(A, n);
  if (det == 0) {
    printf("The matrix is not invertible.\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      B[i][j] = pow(-1, i + j) * determinant(A, n) / det;
    }
  }
}

// Function to check if two matrices are equal
int are_equal(matrix A, matrix B, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] != B[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  // Declare the matrices and the variables to store the size of the matrices
  matrix A, B, C;
  int n, m, p;

  // Read the size of the matrices
  printf("Enter the number of rows and columns of matrix A: ");
  scanf("%d %d", &n, &m);
  printf("Enter the number of rows and columns of matrix B: ");
  scanf("%d %d", &p, &m);

  // Read the matrices
  printf("Enter the elements of matrix A:\n");
  read_matrix(A, n, m);
  printf("Enter the elements of matrix B:\n");
  read_matrix(B, p, m);

  // Add the matrices
  add_matrices(A, B, C, n, m);
  printf("The sum of the two matrices is:\n");
  print_matrix(C, n, m);

  // Subtract the matrices
  subtract_matrices(A, B, C, n, m);
  printf("The difference of the two matrices is:\n");
  print_matrix(C, n, m);

  // Multiply the matrices
  multiply_matrices(A, B, C, n, m, p);
  printf("The product of the two matrices is:\n");
  print_matrix(C, n, p);

  // Transpose the matrices
  transpose_matrix(A, C, n, m);
  printf("The transpose of matrix A is:\n");
  print_matrix(C, m, n);
  transpose_matrix(B, C, p, m);
  printf("The transpose of matrix B is:\n");
  print_matrix(C, m, p);

  // Find the determinant of the matrices
  double detA = determinant(A, n);
  printf("The determinant of matrix A is: %lf\n", detA);
  double detB = determinant(B, p);
  printf("The determinant of matrix B is: %lf\n", detB);

  // Find the inverse of the matrices
  inverse_matrix(A, C, n);
  printf("The inverse of matrix A is:\n");
  print_matrix(C, n, n);
  inverse_matrix(B, C, p);
  printf("The inverse of matrix B is:\n");
  print_matrix(C, p, p);

  // Check if the matrices are equal
  int equal = are_equal(A, B, n, m);
  if (equal) {
    printf("The two matrices are equal.\n");
  } else {
    printf("The two matrices are not equal.\n");
  }

  return 0;
}