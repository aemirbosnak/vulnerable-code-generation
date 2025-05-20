//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize matrix with random values
void initMatrix(int n, double **A) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = (double)rand() / RAND_MAX;
    }
  }
}

// Matrix Multiplication
void matrixMultiply(int n, double **A, double **B, double **C) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C[i][j] = 0.0;
      for (int k = 0; k < n; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

// Compute the Frobenius norm of the matrix
double frobeniusNorm(int n, double **A) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum += A[i][j] * A[i][j];
    }
  }
  return sqrt(sum);
}

// Calculate the largest eigenvalue of the matrix
double largestEigenvalue(int n, double **A) {
  double max = 0.0;
  for (int i = 0; i < n; i++) {
    double sum = 0.0;
    for (int j = 0; j < n; j++) {
      sum += A[i][j] * A[i][j];
    }
    max = fmax(max, sum);
  }
  return sqrt(max);
}

// Main function for benchmarking
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <matrix size>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);

  // Allocate memory for the matrices
  double **A = malloc(n * sizeof(double *));
  double **B = malloc(n * sizeof(double *));
  double **C = malloc(n * sizeof(double *));
  for (int i = 0; i < n; i++) {
    A[i] = malloc(n * sizeof(double));
    B[i] = malloc(n * sizeof(double));
    C[i] = malloc(n * sizeof(double));
  }

  // Initialize matrices
  initMatrix(n, A);
  initMatrix(n, B);

  // Start the timer
  clock_t start = clock();

  // Perform matrix multiplication
  matrixMultiply(n, A, B, C);

  // Stop the timer
  clock_t end = clock();

  // Calculate the elapsed time
  double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Calculate the Frobenius norm of the result
  double norm = frobeniusNorm(n, C);

  // Calculate the largest eigenvalue of the result
  double eigenvalue = largestEigenvalue(n, C);

  // Print the results
  printf("Elapsed time: %.6f seconds\n", elapsed);
  printf("Frobenius norm: %.6f\n", norm);
  printf("Largest eigenvalue: %.6f\n", eigenvalue);

  // Free the allocated memory
  for (int i = 0; i < n; i++) {
    free(A[i]);
    free(B[i]);
    free(C[i]);
  }
  free(A);
  free(B);
  free(C);

  return 0;
}