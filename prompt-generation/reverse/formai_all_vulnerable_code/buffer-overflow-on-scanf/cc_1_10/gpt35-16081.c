//FormAI DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>

#define SIZE 3

void scan_matrix(int A[][SIZE]) {
    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

void print_matrix(int A[][SIZE]) {
    printf("\nThe matrix is:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int A[][SIZE], int B[][SIZE], int C[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiply_matrices(int A[][SIZE], int B[][SIZE], int C[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

    printf("\nEnter matrix A:\n");
    scan_matrix(A);

    printf("\nEnter matrix B:\n");
    scan_matrix(B);

    add_matrices(A, B, C);
    printf("\nAddition of matrices A and B:\n");
    print_matrix(C);

    multiply_matrices(A, B, C);
    printf("\nMultiplication of matrices A and B:\n");
    print_matrix(C);

    return 0;
}