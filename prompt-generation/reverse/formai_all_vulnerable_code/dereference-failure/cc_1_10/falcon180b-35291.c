//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define our matrix dimensions
#define DIM 1000

// Define our function prototypes
void generate_matrix(double* A, double* B);
void multiply_matrices(double* A, double* B, double* C);
void print_matrix(double* A, int rows, int cols);

int main() {
    double* A;
    double* B;
    double* C;

    // Allocate memory for our matrices
    A = (double*)malloc(DIM * DIM * sizeof(double));
    B = (double*)malloc(DIM * DIM * sizeof(double));
    C = (double*)malloc(DIM * DIM * sizeof(double));

    // Generate random matrices A and B
    generate_matrix(A, B);

    // Print our matrices
    printf("Matrix A:\n");
    print_matrix(A, DIM, DIM);
    printf("\nMatrix B:\n");
    print_matrix(B, DIM, DIM);

    // Multiply matrices A and B
    multiply_matrices(A, B, C);

    // Print the result
    printf("\nResult:\n");
    print_matrix(C, DIM, DIM);

    // Free our memory
    free(A);
    free(B);
    free(C);

    return 0;
}

// Function to generate random matrices A and B
void generate_matrix(double* A, double* B) {
    int i, j;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            A[i * DIM + j] = rand() % 10;
            B[i * DIM + j] = rand() % 10;
        }
    }
}

// Function to multiply matrices A and B and store the result in C
void multiply_matrices(double* A, double* B, double* C) {
    int i, j, k;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            C[i * DIM + j] = 0;
            for (k = 0; k < DIM; k++) {
                C[i * DIM + j] += A[i * DIM + k] * B[k * DIM + j];
            }
        }
    }
}

// Function to print a matrix
void print_matrix(double* A, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4.2f ", A[i * cols + j]);
        }
        printf("\n");
    }
}