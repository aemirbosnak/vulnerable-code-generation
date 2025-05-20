//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 4
#define N 5

typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *mat = (Matrix *)calloc(1, sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double *)calloc(rows * cols, sizeof(double));
    return mat;
}

void print_matrix(Matrix *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(Matrix *mat1, Matrix *mat2) {
    Matrix *result = create_matrix(mat1->rows, mat2->cols);
    int i, j;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            result->data[i * result->cols + j] = mat1->data[i * mat1->cols + j] + mat2->data[j];
        }
    }
    return result;
}

Matrix *multiply_matrices(Matrix *mat1, Matrix *mat2) {
    Matrix *result = create_matrix(mat1->rows, mat2->cols * mat1->cols);
    int i, j, k;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            for (k = 0; k < mat1->cols; k++) {
                result->data[i * result->cols + j * result->cols + k] =
                        mat1->data[i * mat1->cols + k] * mat2->data[j * mat2->cols + k];
            }
        }
    }
    return result;
}

int main() {
    Matrix *mat1 = create_matrix(M, N);
    Matrix *mat2 = create_matrix(M, N);
    Matrix *result1 = add_matrices(mat1, mat2);
    Matrix *result2 = multiply_matrices(mat1, mat2);
    print_matrix(result1);
    print_matrix(result2);
    return 0;
}