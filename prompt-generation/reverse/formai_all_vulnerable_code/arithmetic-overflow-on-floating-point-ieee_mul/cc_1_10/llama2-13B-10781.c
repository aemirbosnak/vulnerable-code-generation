//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_MATRIX_SIZE (MAX_ROWS * MAX_COLS)

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)calloc(1, sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double *)calloc(rows * cols, sizeof(double));
    return matrix;
}

void free_matrix(matrix_t *matrix) {
    free(matrix->data);
    free(matrix);
}

void print_matrix(matrix_t *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%.2f ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

matrix_t *add_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    matrix_t *result = create_matrix(matrix1->rows, matrix2->cols);
    int i, j, k;
    for (i = 0; i < matrix1->rows; i++) {
        for (j = 0; j < matrix2->cols; j++) {
            for (k = 0; k < matrix1->cols; k++) {
                result->data[i * result->cols + j] += matrix1->data[i * matrix1->cols + k] * matrix2->data[k * matrix2->cols + j];
            }
        }
    }
    return result;
}

matrix_t *multiply_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    matrix_t *result = create_matrix(matrix1->rows, matrix2->cols * matrix1->cols);
    int i, j, k, l;
    for (i = 0; i < matrix1->rows; i++) {
        for (j = 0; j < matrix2->cols; j++) {
            for (k = 0; k < matrix1->cols; k++) {
                for (l = 0; l < matrix2->rows; l++) {
                    result->data[i * result->cols + j * matrix1->cols + k] += matrix1->data[i * matrix1->cols + k] * matrix2->data[l * matrix2->cols + j];
                }
            }
        }
    }
    return result;
}

int main() {
    matrix_t *matrix1 = create_matrix(5, 3);
    matrix_t *matrix2 = create_matrix(4, 3);
    matrix_t *result = add_matrices(matrix1, matrix2);
    print_matrix(result);
    free_matrix(result);

    matrix1 = create_matrix(5, 3);
    matrix2 = create_matrix(4, 4);
    result = multiply_matrices(matrix1, matrix2);
    print_matrix(result);
    free_matrix(result);

    return 0;
}