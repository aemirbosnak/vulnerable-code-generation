//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
/*
 * A simple C program to demonstrate matrix operations in a synchronous style
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAT_SIZE 3

typedef struct {
    int rows;
    int cols;
    double** data;
} Matrix;

void print_matrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%lf ", mat->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* create_matrix(int rows, int cols) {
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (double*)malloc(cols * sizeof(double));
    }
    return mat;
}

void free_matrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

Matrix* matrix_add(Matrix* mat1, Matrix* mat2) {
    Matrix* result = create_matrix(mat1->rows, mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

Matrix* matrix_multiply(Matrix* mat1, Matrix* mat2) {
    Matrix* result = create_matrix(mat1->rows, mat2->cols);
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

int main() {
    Matrix* mat1 = create_matrix(MAT_SIZE, MAT_SIZE);
    Matrix* mat2 = create_matrix(MAT_SIZE, MAT_SIZE);

    for (int i = 0; i < MAT_SIZE; i++) {
        for (int j = 0; j < MAT_SIZE; j++) {
            mat1->data[i][j] = (double)rand() / RAND_MAX;
            mat2->data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    printf("Matrix 1:\n");
    print_matrix(mat1);
    printf("Matrix 2:\n");
    print_matrix(mat2);

    Matrix* result = matrix_add(mat1, mat2);
    printf("Matrix Addition:\n");
    print_matrix(result);

    result = matrix_multiply(mat1, mat2);
    printf("Matrix Multiplication:\n");
    print_matrix(result);

    free_matrix(mat1);
    free_matrix(mat2);
    free_matrix(result);

    return 0;
}