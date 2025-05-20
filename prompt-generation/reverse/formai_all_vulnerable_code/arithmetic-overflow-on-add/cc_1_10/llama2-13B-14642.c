//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 5
#define COL_SIZE 10

// Function to print a matrix
void print_matrix(int matrix[ROW_SIZE][COL_SIZE]) {
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int add_matrices(int matrix1[ROW_SIZE][COL_SIZE], int matrix2[ROW_SIZE][COL_SIZE]) {
    int i, j, k;
    int result[ROW_SIZE][COL_SIZE];

    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            for (k = 0; k < COL_SIZE; k++) {
                result[i][j] += matrix1[i][k] + matrix2[k][j];
            }
        }
    }

    return result;
}

// Function to multiply a matrix by a scalar
int matrix_multiply(int matrix[ROW_SIZE][COL_SIZE], int scalar) {
    int i, j;
    int result[ROW_SIZE][COL_SIZE];

    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }

    return result;
}

int main() {
    int matrix1[ROW_SIZE][COL_SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int matrix2[ROW_SIZE][COL_SIZE] = {
        {25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34},
        {35, 36, 37, 38, 39},
        {40, 41, 42, 43, 44},
        {45, 46, 47, 48, 49}
    };

    int result = add_matrices(matrix1, matrix2);
    print_matrix(result);

    result = matrix_multiply(matrix1, 2);
    print_matrix(result);

    return 0;
}