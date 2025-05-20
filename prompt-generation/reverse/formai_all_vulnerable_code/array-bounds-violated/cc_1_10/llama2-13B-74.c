//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5 // matrix size
#define N 3 // number of columns in each matrix

// Function to print a matrix
void print_matrix(int mat[M][N]) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int add_matrices(int mat1[M][N], int mat2[M][N]) {
    int i, j;
    int sum_mat[M][N];
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            sum_mat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return sum_mat;
}

// Function to multiply a matrix by a scalar
int scalar_mult(int mat[M][N], int scalar) {
    int i, j;
    int result[M][N];
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            result[i][j] = scalar * mat[i][j];
        }
    }
    return result;
}

// Function to transpose a matrix
int transpose(int mat[M][N]) {
    int i, j;
    int result[M][N];
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            result[j][i] = mat[i][j];
        }
    }
    return result;
}

int main() {
    int mat1[M][N] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int mat2[M][N] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} };
    int mat3[M][N] = { {100, 200, 300}, {400, 500, 600}, {700, 800, 900} };
    int scalar = 2;

    // Example 1: Add two matrices
    int sum = add_matrices(mat1, mat2);
    print_matrix(sum);

    // Example 2: Multiply a matrix by a scalar
    int result = scalar_mult(mat1, scalar);
    print_matrix(result);

    // Example 3: Transpose a matrix
    int transposed = transpose(mat1);
    print_matrix(transposed);

    return 0;
}