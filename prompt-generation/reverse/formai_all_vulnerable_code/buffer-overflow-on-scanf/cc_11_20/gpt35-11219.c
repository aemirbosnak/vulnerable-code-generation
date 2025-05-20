//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
// Welcome to my exciting Matrix Operations program!
// I am thrilled to share my love for C and matrices with you!
#include <stdio.h>

// Let's start by declaring a constant to define the matrix size
#define MATRIX_SIZE 3

// Now, let's declare our two matrices
int matrix_a[MATRIX_SIZE][MATRIX_SIZE];
int matrix_b[MATRIX_SIZE][MATRIX_SIZE];

// We will also need a matrix to store the result of our operations
int result_matrix[MATRIX_SIZE][MATRIX_SIZE];

int main() {
    // Let's fill our matrices with some values
    printf("Enter the values for Matrix A:\n");
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }

    printf("Enter the values for Matrix B:\n");
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            scanf("%d", &matrix_b[i][j]);
        }
    }

    // Now, let's perform some matrix operations!

    // Addition
    printf("Result of Matrix Addition:\n");
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            result_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    // Subtraction
    printf("Result of Matrix Subtraction:\n");
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            result_matrix[i][j] = matrix_a[i][j] - matrix_b[i][j];
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    // Multiplication
    printf("Result of Matrix Multiplication:\n");
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            result_matrix[i][j] = 0;
            for(int k = 0; k < MATRIX_SIZE; k++) {
                result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    // That's it! We did it! Thank you for joining me on this exciting journey of matrix operations!

    return 0;
}