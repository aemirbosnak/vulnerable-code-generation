//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROCKS 1

// Structure to represent a matrix
typedef struct matrix {
    int rows;
    int cols;
    double* data;
} matrix_t;

// Function to create a matrix
matrix_t* create_matrix(int rows, int cols) {
    matrix_t* mat = (matrix_t*) malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double*) malloc(rows * cols * sizeof(double));
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t* mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t* add_matrices(matrix_t* mat1, matrix_t* mat2) {
    int i, j, k;
    matrix_t* result = create_matrix(mat1->rows, mat2->cols);
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            for (k = 0; k < mat1->cols; k++) {
                result->data[i * result->cols + j] += mat1->data[i * mat1->cols + k] + mat2->data[k * mat2->cols + j];
            }
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t* scalar_multiply(matrix_t* mat, double scalar) {
    int i, j;
    matrix_t* result = create_matrix(mat->rows, mat->cols);
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = mat->data[i * mat->cols + j] * scalar;
        }
    }
    return result;
}

int main() {
    matrix_t* mat1 = create_matrix(3, 4);
    matrix_t* mat2 = create_matrix(3, 3);
    matrix_t* result = add_matrices(mat1, mat2);
    print_matrix(result);
    result = scalar_multiply(result, 2.0);
    print_matrix(result);
    return 0;
}