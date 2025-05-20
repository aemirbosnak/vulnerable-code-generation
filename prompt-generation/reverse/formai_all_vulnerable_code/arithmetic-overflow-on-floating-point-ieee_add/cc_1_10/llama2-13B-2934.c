//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform matrix multiplication
void mat_mult(double *A, double *B, double *C, int m, int n) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            C[i * n + j] = 0;
            for (k = 0; k < n; k++) {
                C[i * n + j] += A[i * m + k] * B[k * n + j];
            }
        }
    }
}

// Function to perform matrix addition
void mat_add(double *A, double *B, double *C, int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            C[i * n + j] = A[i * m + j] + B[i * m + j];
        }
    }
}

// Function to perform matrix inversion
double mat_inv(double *A, int m, int n) {
    int i, j;
    double det = 1;
    double inv[m][n];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            inv[i][j] = 0;
            for (int k = 0; k < n; k++) {
                inv[i][j] += A[i * n + k] * inv[k][j];
            }
        }
    }
    return det;
}

int main() {
    int m = 3, n = 3;
    double A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    double B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };
    double C[3][3];

    // Perform matrix multiplication
    mat_mult(A, B, C, m, n);

    // Print the result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    mat_add(A, B, C, m, n);

    // Print the result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    // Perform matrix inversion
    double det = mat_inv(A, m, n);
    printf("Determinant of A = %.2f\n", det);

    return 0;
}