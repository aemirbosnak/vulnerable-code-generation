//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

// Function to print a matrix
void print_matrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transpose_matrix(int matrix[ROWS][COLS], int result[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to find the determinant of a matrix
int determinant(int matrix[ROWS][COLS]) {
    int det = 0;
    if (ROWS != COLS) {
        return 0;  // Determinant is undefined for non-square matrices
    }
    if (ROWS == 2) {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        for (int i = 0; i < COLS; i++) {
            int submatrix[ROWS - 1][COLS - 1];
            for (int j = 1; j < ROWS; j++) {
                for (int k = 0; k < COLS; k++) {
                    if (k == i) {
                        continue;
                    }
                    submatrix[j - 1][k - (k >= i)] = matrix[j][k];
                }
            }
            det += matrix[0][i] * determinant(submatrix) * (i % 2 == 0 ? 1 : -1);
        }
    }
    return det;
}

// Function to find the inverse of a matrix
void inverse_matrix(int matrix[ROWS][COLS], int inverse[ROWS][COLS]) {
    int det = determinant(matrix);
    if (det == 0) {
        return;  // Inverse is undefined for non-invertible matrices
    }
    int adjoint[ROWS][COLS];
    transpose_matrix(matrix, adjoint);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            inverse[i][j] = adjoint[i][j] / det;
        }
    }
}

// Function to test the matrix operations
int main() {
    int matrix1[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int matrix2[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int result[ROWS][COLS];

    // Print the original matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1);

    printf("Matrix 2:\n");
    print_matrix(matrix2);

    // Add the matrices
    add_matrices(matrix1, matrix2, result);

    // Print the result
    printf("Sum of the matrices:\n");
    print_matrix(result);

    // Subtract the matrices
    subtract_matrices(matrix1, matrix2, result);

    // Print the result
    printf("Difference of the matrices:\n");
    print_matrix(result);

    // Multiply the matrices
    multiply_matrices(matrix1, matrix2, result);

    // Print the result
    printf("Product of the matrices:\n");
    print_matrix(result);

    // Transpose matrix 1
    int transposed[COLS][ROWS];
    transpose_matrix(matrix1, transposed);

    // Print the result
    printf("Transpose of matrix 1:\n");
    print_matrix(transposed);

    // Find the determinant of matrix 1
    int det = determinant(matrix1);

    // Print the result
    printf("Determinant of matrix 1: %d\n", det);

    // Find the inverse of matrix 1
    int inv[ROWS][COLS];
    inverse_matrix(matrix1, inv);

    // Print the result
    printf("Inverse of matrix 1:\n");
    print_matrix(inv);

    return EXIT_SUCCESS;
}