//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MATRIX_DIM 4

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix_t;

void matrix_print(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

matrix_t *matrix_create(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double *)calloc(rows * cols, sizeof(double));
    return mat;
}

matrix_t *matrix_mult(matrix_t *a, matrix_t *b) {
    int i, j, k;
    matrix_t *c = matrix_create(a->rows, b->cols);
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            double sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            c->data[i * c->cols + j] = sum;
        }
    }
    return c;
}

int main() {
    matrix_t *a = matrix_create(3, 2);
    a->data[0 * a->cols + 0] = 1.0; a->data[0 * a->cols + 1] = 2.0;
    a->data[1 * a->cols + 0] = 3.0; a->data[1 * a->cols + 1] = 4.0;
    a->data[2 * a->cols + 0] = 5.0; a->data[2 * a->cols + 1] = 6.0;

    matrix_t *b = matrix_create(2, 2);
    b->data[0 * b->cols + 0] = 7.0; b->data[0 * b->cols + 1] = 8.0;
    b->data[1 * b->cols + 0] = 9.0; b->data[1 * b->cols + 1] = 10.0;

    matrix_t *c = matrix_mult(a, b);
    matrix_print(c);

    return 0;
}