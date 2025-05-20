//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>

// Global variable for matrix size
#define N 3

// Function to perform matrix addition
void matrix_add(int mat1[][N], int mat2[][N], int res[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to perform matrix subtraction
void matrix_sub(int mat1[][N], int mat2[][N], int res[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to perform matrix multiplication
void matrix_mul(int mat1[][N], int mat2[][N], int res[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;

            for (int k = 0; k < N; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[N][N], mat2[N][N], result[N][N];

    // Initializing matrices with user input
    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Printing the user provided matrices
    printf("\nMatrix 1:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    // Performing matrix addition
    matrix_add(mat1, mat2, result);
    printf("\nAddition of matrices:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Performing matrix subtraction
    matrix_sub(mat1, mat2, result);
    printf("\nSubtraction of matrices:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Performing matrix multiplication
    matrix_mul(mat1, mat2, result);
    printf("\nMultiplication of matrices:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}