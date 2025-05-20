//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

void create_matrix(Matrix *m) {
    m->data = (int **)malloc(m->rows * sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->data[i] = (int *)malloc(m->cols * sizeof(int));
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = 0;
        }
    }
}

void destroy_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

void print_matrix(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(Matrix *a, const Matrix *b, Matrix *result) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void subtract_matrices(Matrix *a, const Matrix *b, Matrix *result) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
}

void multiply_matrices(const Matrix *a, const Matrix *b, Matrix *result) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < ROWS; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            result->data[i][j] = sum;
            sum = 0;
        }
    }
}

int main() {
    Matrix A, B, C;
    create_matrix(&A);
    create_matrix(&B);
    create_matrix(&C);

    printf("Matrix A:\n");
    print_matrix(&A);

    printf("Matrix B:\n");
    print_matrix(&B);

    add_matrices(&A, &B, &C);
    printf("Matrix C (A + B):\n");
    print_matrix(&C);

    subtract_matrices(&A, &B, &C);
    printf("Matrix C (A - B):\n");
    print_matrix(&C);

    multiply_matrices(&A, &B, &C);
    printf("Matrix C (A * B):\n");
    print_matrix(&C);

    destroy_matrix(&A);
    destroy_matrix(&B);
    destroy_matrix(&C);

    return 0;
}