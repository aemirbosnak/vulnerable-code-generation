//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    double* data;
} Matrix;

Matrix* create_matrix(int rows, int cols) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double*)calloc(rows * cols, sizeof(double));
    return matrix;
}

void destroy_matrix(Matrix* matrix) {
    free(matrix->data);
    free(matrix);
}

void print_matrix(Matrix* matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%f ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

Matrix* transpose_matrix(Matrix* matrix) {
    Matrix* transposed = create_matrix(matrix->cols, matrix->rows);
    for (int i = 0; i < matrix->cols; i++) {
        for (int j = 0; j < matrix->rows; j++) {
            transposed->data[i * matrix->rows + j] = matrix->data[j * matrix->cols + i];
        }
    }
    return transposed;
}

Matrix* multiply_matrices(Matrix* matrix1, Matrix* matrix2) {
    Matrix* result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < matrix1->cols; k++) {
                sum += matrix1->data[i * matrix1->cols + k] * matrix2->data[k * matrix2->cols + j];
            }
            result->data[i * matrix2->cols + j] = sum;
        }
    }
    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d%d", &rows1, &cols1);
    Matrix* matrix1 = create_matrix(rows1, cols1);
    printf("Enter the elements of matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%lf", &matrix1->data[i * cols1 + j]);
        }
    }
    printf("\n");
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d%d", &rows2, &cols2);
    Matrix* matrix2 = create_matrix(rows2, cols2);
    printf("Enter the elements of matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%lf", &matrix2->data[i * cols2 + j]);
        }
    }
    printf("\n");
    Matrix* transposed1 = transpose_matrix(matrix1);
    printf("Transposed matrix 1:\n");
    print_matrix(transposed1);
    printf("\n");
    Matrix* transposed2 = transpose_matrix(matrix2);
    printf("Transposed matrix 2:\n");
    print_matrix(transposed2);
    printf("\n");
    Matrix* result = multiply_matrices(transposed1, matrix2);
    printf("Result of matrix multiplication:\n");
    print_matrix(result);
    printf("\n");
    destroy_matrix(transposed1);
    destroy_matrix(transposed2);
    destroy_matrix(matrix1);
    destroy_matrix(matrix2);
    destroy_matrix(result);
    return 0;
}