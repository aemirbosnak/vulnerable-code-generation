//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: visionary
/*
 * Matrix Operations Example Program
 *
 * This program demonstrates various matrix operations in C.
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to add two matrices
void add_matrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transpose_matrix(int rows, int cols, int mat[rows][cols], int result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// Function to print a matrix
void print_matrix(int rows, int cols, int mat[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declare matrices
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result[3][3];

    // Add matrices
    add_matrices(3, 3, mat1, mat2, result);
    printf("Addition of matrices:\n");
    print_matrix(3, 3, result);

    // Multiply matrices
    multiply_matrices(3, 3, mat1, mat2, result);
    printf("Multiplication of matrices:\n");
    print_matrix(3, 3, result);

    // Transpose a matrix
    transpose_matrix(3, 3, mat1, result);
    printf("Transpose of matrix 1:\n");
    print_matrix(3, 3, result);

    return 0;
}