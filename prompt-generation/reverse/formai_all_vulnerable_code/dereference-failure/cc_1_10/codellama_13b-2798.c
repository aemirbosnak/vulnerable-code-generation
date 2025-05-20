//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: future-proof
/*
 * Matrix operations example program
 *
 * This program demonstrates how to perform various matrix operations in C.
 *
 * Compile with: gcc -Wall -o matrix_operations matrix_operations.c
 *
 * Run with: ./matrix_operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAT_ROWS 3
#define MAT_COLS 3

// Define a structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double **data;
} matrix_t;

// Function to create a matrix with given dimensions
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(cols * sizeof(double));
    }
    return mat;
}

// Function to destroy a matrix
void destroy_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%.2lf ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        printf("Matrices must have the same dimensions to be added.\n");
        return NULL;
    }
    matrix_t *result = create_matrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
matrix_t *multiply_matrices(matrix_t *mat1, matrix_t *mat2) {
    if (mat1->cols != mat2->rows) {
        printf("Matrices must have compatible dimensions to be multiplied.\n");
        return NULL;
    }
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            double sum = 0;
            for (int k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

// Function to transpose a matrix
matrix_t *transpose_matrix(matrix_t *mat) {
    matrix_t *result = create_matrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[j][i] = mat->data[i][j];
        }
    }
    return result;
}

int main() {
    // Create two matrices
    matrix_t *mat1 = create_matrix(MAT_ROWS, MAT_COLS);
    matrix_t *mat2 = create_matrix(MAT_ROWS, MAT_COLS);

    // Initialize the matrices
    for (int i = 0; i < MAT_ROWS; i++) {
        for (int j = 0; j < MAT_COLS; j++) {
            mat1->data[i][j] = i + j;
            mat2->data[i][j] = j - i;
        }
    }

    // Add the matrices
    matrix_t *result = add_matrices(mat1, mat2);
    if (result == NULL) {
        printf("Error adding matrices.\n");
        return 1;
    }
    printf("Addition: \n");
    print_matrix(result);

    // Multiply the matrices
    result = multiply_matrices(mat1, mat2);
    if (result == NULL) {
        printf("Error multiplying matrices.\n");
        return 1;
    }
    printf("Multiplication: \n");
    print_matrix(result);

    // Transpose the matrices
    result = transpose_matrix(mat1);
    if (result == NULL) {
        printf("Error transposing matrix.\n");
        return 1;
    }
    printf("Transposition: \n");
    print_matrix(result);

    // Clean up
    destroy_matrix(mat1);
    destroy_matrix(mat2);
    destroy_matrix(result);

    return 0;
}