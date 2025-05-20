//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 4   // size of the matrix
#define N 4   // size of the matrix

// Function to print the matrix
void print_matrix(int mat[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int mat1[M][N], int mat2[M][N], int result[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                result[i][j] += mat1[i][k] + mat2[k][j];
            }
        }
    }
}

// Function to multiply a matrix by a scalar
void scalar_mult(int mat[M][N], int scalar, int result[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat[i][j] * scalar;
        }
    }
}

// Function to transpose a matrix
void transpose(int mat[M][N], int result[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat[j][i];
        }
    }
}

// Function to randomize a matrix
void randomize(int mat[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = (rand() % 10) + 1;
        }
    }
}

int main() {
    int mat1[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[M][N] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int result[M][N];

    // Add two matrices
    add_matrices(mat1, mat2, result);
    print_matrix(result);

    // Multiply a matrix by a scalar
    scalar_mult(mat1, 2, result);
    print_matrix(result);

    // Transpose a matrix
    transpose(mat1, result);
    print_matrix(result);

    // Randomize a matrix
    randomize(mat1);
    print_matrix(mat1);

    return 0;
}