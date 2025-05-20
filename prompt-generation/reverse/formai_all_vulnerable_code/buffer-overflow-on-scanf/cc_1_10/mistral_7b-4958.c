//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 10

typedef struct {
    double data[SIZE][SIZE];
    char name[SIZE][SIZE];
} Matrix;

void print_matrix(const Matrix *matrix) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%.2f ", matrix->data[i][j]);
        }
        printf("\t%s\n", matrix->name[i]);
    }
}

void read_matrix(Matrix *matrix) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%lf", &matrix->data[i][j]);
            scanf("%s", matrix->name[i], SIZE);
        }
    }
}

Matrix add_matrices(const Matrix *a, const Matrix *b) {
    Matrix result;
    int i, j;

    strcpy(result.name[0], "Sum");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return result;
}

Matrix multiply_matrices(const Matrix *a, const Matrix *b) {
    Matrix result;
    int i, j, k;

    strcpy(result.name[0], "Product");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}

int main() {
    Matrix A, B, C;

    read_matrix(&A);
    read_matrix(&B);

    C = add_matrices(&A, &B);
    print_matrix(&C);

    C = multiply_matrices(&A, &B);
    print_matrix(&C);

    return 0;
}