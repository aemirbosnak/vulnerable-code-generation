//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: real-life
// Example of a C program to perform matrix operations in a real-life style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to print a matrix
void print_matrix(int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transpose_matrix(int n, int m, int matrix[n][m], int result[m][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to inverse a matrix
void inverse_matrix(int n, int m, int matrix[n][m], int result[n][m]) {
    // Calculate the determinant of the matrix
    float det = 0;
    for (int i = 0; i < n; i++) {
        det += matrix[i][i];
    }

    // Calculate the inverse of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = matrix[i][j] / det;
        }
    }
}

// Main function
int main() {
    // Initialize the matrices
    int matrix1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix2[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    int matrix3[3][3];

    // Add the matrices
    add_matrices(3, 3, matrix1, matrix2, matrix3);

    // Print the result
    printf("Addition of matrices:\n");
    print_matrix(3, 3, matrix3);

    // Multiply the matrices
    multiply_matrices(3, 3, matrix1, matrix2, matrix3);

    // Print the result
    printf("Multiplication of matrices:\n");
    print_matrix(3, 3, matrix3);

    // Transpose the matrices
    transpose_matrix(3, 3, matrix1, matrix3);

    // Print the result
    printf("Transpose of matrix 1:\n");
    print_matrix(3, 3, matrix3);

    // Inverse the matrices
    inverse_matrix(3, 3, matrix1, matrix3);

    // Print the result
    printf("Inverse of matrix 1:\n");
    print_matrix(3, 3, matrix3);

    return 0;
}