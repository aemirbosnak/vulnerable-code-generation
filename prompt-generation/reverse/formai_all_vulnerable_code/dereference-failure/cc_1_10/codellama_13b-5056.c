//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: portable
// Matrix operations example program in a portable style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

// Define a structure for a matrix
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

// Define a function to create a matrix
Matrix* create_matrix(int rows, int cols) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

// Define a function to print a matrix
void print_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Define a function to add two matrices
Matrix* add_matrices(Matrix* matrix1, Matrix* matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        return NULL;
    }
    Matrix* result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Define a function to multiply two matrices
Matrix* multiply_matrices(Matrix* matrix1, Matrix* matrix2) {
    if (matrix1->cols != matrix2->rows) {
        return NULL;
    }
    Matrix* result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                sum += matrix1->data[i][k] * matrix2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

// Define a function to transpose a matrix
Matrix* transpose_matrix(Matrix* matrix) {
    Matrix* result = create_matrix(matrix->cols, matrix->rows);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }
    return result;
}

// Define a function to free a matrix
void free_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

int main() {
    // Create two matrices
    Matrix* matrix1 = create_matrix(2, 2);
    Matrix* matrix2 = create_matrix(2, 2);

    // Initialize the matrices with some values
    matrix1->data[0][0] = 1;
    matrix1->data[0][1] = 2;
    matrix1->data[1][0] = 3;
    matrix1->data[1][1] = 4;

    matrix2->data[0][0] = 5;
    matrix2->data[0][1] = 6;
    matrix2->data[1][0] = 7;
    matrix2->data[1][1] = 8;

    // Add the matrices
    Matrix* result = add_matrices(matrix1, matrix2);
    printf("Addition of matrices:\n");
    print_matrix(result);
    free_matrix(result);

    // Multiply the matrices
    result = multiply_matrices(matrix1, matrix2);
    printf("Multiplication of matrices:\n");
    print_matrix(result);
    free_matrix(result);

    // Transpose the matrices
    result = transpose_matrix(matrix1);
    printf("Transpose of matrix 1:\n");
    print_matrix(result);
    free_matrix(result);

    result = transpose_matrix(matrix2);
    printf("Transpose of matrix 2:\n");
    print_matrix(result);
    free_matrix(result);

    // Free the matrices
    free_matrix(matrix1);
    free_matrix(matrix2);

    return 0;
}