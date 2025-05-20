//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix_t;

void init_matrix(matrix_t *m, int r, int c) {
    m->rows = r;
    m->cols = c;
    m->data = (double *)calloc(r * c, sizeof(double));
}

void print_matrix(matrix_t *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

matrix_t *add_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *c = (matrix_t *)calloc(a->rows, a->cols + b->rows);
    int i, j, k;

    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            c->data[i * (a->rows + b->rows) + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }

    return c;
}

matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *c = (matrix_t *)calloc(a->rows, b->cols);
    int i, j, k;

    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            double sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            c->data[i * b->cols + j] = sum;
        }
    }

    return c;
}

int main() {
    matrix_t *a, *b, *c;

    init_matrix(&a, 3, 3);
    init_matrix(&b, 3, 2);
    init_matrix(&c, 3, 4);

    // Add matrices
    c = add_matrices(a, b);
    print_matrix(c);

    // Multiply matrices
    c = multiply_matrices(a, b);
    print_matrix(c);

    return 0;
}