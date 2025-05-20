//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_DIM 5

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)calloc(rows * cols, sizeof(int));
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    int i, j, k;
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
matrix_t *scale_matrix(matrix_t *mat, int factor) {
    matrix_t *result = create_matrix(mat->rows, mat->cols);
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = factor * mat->data[i * mat->cols + j];
        }
    }
    return result;
}

// Function to transpose a matrix
matrix_t *transpose_matrix(matrix_t *mat) {
    matrix_t *result = create_matrix(mat->cols, mat->rows);
    int i, j, k;
    for (i = 0; i < mat->cols; i++) {
        for (j = 0; j < mat->rows; j++) {
            result->data[i * result->rows + j] = mat->data[j * mat->cols + i];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(3, 4);
    matrix_t *mat2 = create_matrix(4, 3);
    matrix_t *result1 = add_matrices(mat1, mat2);
    matrix_t *result2 = scale_matrix(mat1, 2);
    matrix_t *result3 = transpose_matrix(mat1);

    print_matrix(mat1);
    print_matrix(mat2);
    print_matrix(result1);
    print_matrix(result2);
    print_matrix(result3);

    return 0;
}