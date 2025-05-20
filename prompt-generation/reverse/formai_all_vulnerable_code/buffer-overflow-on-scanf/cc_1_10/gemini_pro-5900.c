//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the matrices
#define MAX_SIZE 100

// Define the data type for the matrices
typedef double matrix[MAX_SIZE][MAX_SIZE];

// Function to read a matrix from the user
void read_matrix(matrix a, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%lf", &a[i][j]);
    }
  }
}

// Function to print a matrix
void print_matrix(matrix a, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%lf ", a[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void add_matrices(matrix a, matrix b, matrix c, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
}

// Function to subtract two matrices
void subtract_matrices(matrix a, matrix b, matrix c, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i][j] = a[i][j] - b[i][j];
    }
  }
}

// Function to multiply two matrices
void multiply_matrices(matrix a, matrix b, matrix c, int n, int m, int p) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      c[i][j] = 0;
      for (int k = 0; k < m; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

// Function to find the transpose of a matrix
void transpose_matrix(matrix a, matrix b, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[j][i] = a[i][j];
    }
  }
}

// Function to find the determinant of a matrix
double determinant(matrix a, int n) {
  if (n == 1) {
    return a[0][0];
  } else if (n == 2) {
    return a[0][0] * a[1][1] - a[0][1] * a[1][0];
  } else {
    double det = 0;
    for (int i = 0; i < n; i++) {
      matrix sub_matrix;
      for (int j = 1; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (k == i) {
            continue;
          }
          sub_matrix[j - 1][k] = a[j][k];
        }
      }
      det += pow(-1, i) * a[0][i] * determinant(sub_matrix, n - 1);
    }
    return det;
  }
}

// Function to find the inverse of a matrix
int inverse_matrix(matrix a, matrix b, int n) {
  if (determinant(a, n) == 0) {
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix sub_matrix;
      int ii = (i + 1) % n;
      int jj = (j + 1) % n;
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          if (k == i || l == j) {
            continue;
          }
          sub_matrix[k - (k >= i)][l - (l >= j)] = a[k][l];
        }
      }
      b[i][j] = pow(-1, ii + jj) * determinant(sub_matrix, n - 1) / determinant(a, n);
    }
  }
  return 1;
}

// Function to find the eigenvalues of a matrix
void eigenvalues(matrix a, int n) {
  for (int i = 0; i < n; i++) {
    double lambda;
    printf("Eigenvalue %d: ", i + 1);
    for (int j = 0; j < n; j++) {
      lambda += a[i][j] * a[j][i];
    }
    printf("%lf\n", lambda);
  }
}

// Function to find the eigenvectors of a matrix
void eigenvectors(matrix a, int n) {
  for (int i = 0; i < n; i++) {
    double lambda;
    printf("Eigenvector %d: ", i + 1);
    for (int j = 0; j < n; j++) {
      lambda += a[i][j] * a[j][i];
    }
    for (int j = 0; j < n; j++) {
      a[j][i] -= lambda * a[j][i];
    }
    for (int j = 0; j < n; j++) {
      printf("%lf ", a[j][i]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Declare the matrices
  matrix a, b, c;
  int n, m, p;

  // Read the size of the matrices
  printf("Enter the number of rows and columns of matrix A: ");
  scanf("%d %d", &n, &m);
  printf("Enter the number of rows and columns of matrix B: ");
  scanf("%d %d", &p, &m);

  // Read the matrices
  printf("Enter the elements of matrix A:\n");
  read_matrix(a, n, m);
  printf("Enter the elements of matrix B:\n");
  read_matrix(b, p, m);

  // Add the matrices
  add_matrices(a, b, c, n, m);
  printf("The sum of the matrices is:\n");
  print_matrix(c, n, m);

  // Subtract the matrices
  subtract_matrices(a, b, c, n, m);
  printf("The difference of the matrices is:\n");
  print_matrix(c, n, m);

  // Multiply the matrices
  multiply_matrices(a, b, c, n, m, p);
  printf("The product of the matrices is:\n");
  print_matrix(c, n, p);

  // Find the transpose of matrix A
  transpose_matrix(a, c, n, m);
  printf("The transpose of matrix A is:\n");
  print_matrix(c, m, n);

  // Find the determinant of matrix A
  double det = determinant(a, n);
  printf("The determinant of matrix A is: %lf\n", det);

  // Find the inverse of matrix A
  if (inverse_matrix(a, c, n)) {
    printf("The inverse of matrix A is:\n");
    print_matrix(c, n, n);
  } else {
    printf("Matrix A is not invertible.\n");
  }

  // Find the eigenvalues of matrix A
  eigenvalues(a, n);

  // Find the eigenvectors of matrix A
  eigenvectors(a, n);

  return 0;
}