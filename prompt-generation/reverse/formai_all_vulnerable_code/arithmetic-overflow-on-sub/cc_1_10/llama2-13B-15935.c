//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define N 10000
#define M 100

struct Complex {
    float real;
    float imag;
};

struct Matrix {
    int rows;
    int cols;
    struct Complex *data;
};

void init_matrix(struct Matrix *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            mat->data[i * mat->cols + j].real = (float)rand() / RAND_MAX;
            mat->data[i * mat->cols + j].imag = (float)rand() / RAND_MAX;
        }
    }
}

void add_matrices(struct Matrix *a, struct Matrix *b, struct Matrix *res) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            for (k = 0; k < b->cols; k++) {
                res->data[i * res->cols + j].real += a->data[i * a->cols + j].real * b->data[k * b->cols + k].real -
                                                     a->data[i * a->cols + j].imag * b->data[k * b->cols + k].imag;
                res->data[i * res->cols + j].imag += a->data[i * a->cols + j].real * b->data[k * b->cols + k].imag +
                                                     a->data[i * a->cols + j].imag * b->data[k * b->cols + k].real;
            }
        }
    }
}

void print_matrix(struct Matrix *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%.2f + %.2fi", mat->data[i * mat->cols + j].real, mat->data[i * mat->cols + j].imag);
            if (j < mat->cols - 1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    struct Matrix a, b, res;
    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&res);

    clock_t start, end;
    double time_elapsed;

    for (int i = 0; i < M; i++) {
        start = clock();
        add_matrices(&a, &b, &res);
        end = clock();
        time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time elapsed: %f seconds\n", time_elapsed);
    }

    print_matrix(&res);

    return 0;
}