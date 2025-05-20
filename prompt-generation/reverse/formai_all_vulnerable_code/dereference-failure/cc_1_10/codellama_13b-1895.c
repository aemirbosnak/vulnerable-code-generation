//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: funny
// Matrix Operations Example Program in a Funny Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

// Function to print a matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiply_matrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2, int** result) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transpose_matrix(int** matrix, int rows, int cols, int** result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}

int main() {
    int rows1 = 3, cols1 = 4, rows2 = 4, cols2 = 3;
    int** matrix1 = (int**)malloc(rows1 * sizeof(int*));
    int** matrix2 = (int**)malloc(rows2 * sizeof(int*));
    int** result = (int**)malloc(rows1 * sizeof(int*));

    // Initialize matrices with random values
    srand(time(NULL));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int*)malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int*)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }

    // Print matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);
    printf("\nMatrix 2:\n");
    print_matrix(matrix2, rows2, cols2);

    // Multiply matrices
    multiply_matrices(matrix1, matrix2, rows1, cols1, rows2, cols2, result);
    printf("\nProduct of matrices:\n");
    print_matrix(result, rows1, cols2);

    // Transpose matrix 1
    transpose_matrix(matrix1, rows1, cols1, result);
    printf("\nTranspose of matrix 1:\n");
    print_matrix(result, cols1, rows1);

    // Transpose matrix 2
    transpose_matrix(matrix2, rows2, cols2, result);
    printf("\nTranspose of matrix 2:\n");
    print_matrix(result, cols2, rows2);

    // Clean up
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}