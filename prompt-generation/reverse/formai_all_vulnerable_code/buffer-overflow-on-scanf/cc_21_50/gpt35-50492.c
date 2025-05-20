//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

// This program demonstrates various matrix operations in C language.

int main() {
    int A[3][3], B[3][3], C[3][3], i, j, k;

    // Taking input for matrix A
    printf("Enter the elements of matrix A:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Taking input for matrix B
    printf("Enter the elements of matrix B:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Displaying input matrices
    printf("\nMatrix A:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix B:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Matrix addition
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Displaying addition of matrices
    printf("\nAddition of matrices A and B:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Matrix subtraction
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    // Displaying subtraction of matrices
    printf("\nSubtraction of matrices A and B:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Matrix multiplication
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            C[i][j] = 0;
            for(k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Displaying multiplication of matrices
    printf("\nMultiplication of matrices A and B:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Matrix transpose
    printf("\nTranspose of matrix A:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }

    return 0;
}