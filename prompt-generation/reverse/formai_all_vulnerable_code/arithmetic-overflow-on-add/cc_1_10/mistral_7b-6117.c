//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATRIX_SIZE 10
#define PARANOID_CHECKS 1

typedef struct Matrix {
    int rows;
    int cols;
    int *data;
} Matrix;

void die(const char *msg) {
#if PARANOID_CHECKS
    fprintf(stderr, "[%s] %s\n", __FUNCTION__, msg);
    exit(EXIT_FAILURE);
#else
    (void)msg;
#endif
}

Matrix create_matrix(int rows, int cols) {
    Matrix matrix;
    int i, size;

    if (rows <= 0 || cols <= 0) {
        die("Invalid matrix size.");
    }

    size = rows * cols;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = malloc(size * sizeof(int));
    if (matrix.data == NULL) {
        die("Out of memory.");
    }

    for (i = 0; i < size; i++) {
        matrix.data[i] = 0;
    }

    return matrix;
}

void destroy_matrix(Matrix *matrix) {
    free(matrix->data);
}

void print_matrix(const Matrix *matrix) {
    int i, j;

    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

Matrix add_matrices(const Matrix *a, const Matrix *b) {
    Matrix result;

    if (a->rows != b->rows || a->cols != b->cols) {
        die("Matrices have different sizes.");
    }

    result = create_matrix(a->rows, a->cols);

    for (int i = 0; i < a->rows * a->cols; i++) {
        result.data[i] = a->data[i] + b->data[i];
    }

    return result;
}

int main() {
    Matrix A, B, C;
    int i, j;

    A = create_matrix(3, 3);
    B = create_matrix(3, 3);

    for (i = 0; i < 3 * 3; i++) {
        scanf("%d", &A.data[i]);
    }

    for (i = 0; i < 3 * 3; i++) {
        scanf("%d", &B.data[i]);
    }

    C = add_matrices(&A, &B);

    printf("Matrix A:\n");
    print_matrix(&A);

    printf("Matrix B:\n");
    print_matrix(&B);

    printf("Sum of matrices A and B:\n");
    print_matrix(&C);

    destroy_matrix(&A);
    destroy_matrix(&B);
    destroy_matrix(&C);

    return 0;
}