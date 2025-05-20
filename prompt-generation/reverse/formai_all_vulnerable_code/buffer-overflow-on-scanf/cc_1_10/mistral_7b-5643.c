//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

typedef struct {
    int data[ROWS][COLS];
} Matrix;

void print_matrix(const Matrix *m) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d ", m->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix add_matrices(const Matrix *m1, const Matrix *m2) {
    Matrix result;
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result.data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    return result;
}

Matrix multiply_matrix_by_scalar(const Matrix *m, int scalar) {
    Matrix result;
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result.data[i][j] = m->data[i][j] * scalar;
        }
    }

    return result;
}

int main() {
    Matrix m1, m2, sum, product;
    int i, j, scalar = 5;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Enter element m1[%d][%d]: ", i, j);
            scanf("%d", &m1.data[i][j]);
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Enter element m2[%d][%d]: ", i, j);
            scanf("%d", &m2.data[i][j]);
        }
    }

    sum = add_matrices(&m1, &m2);
    printf("Sum of matrices:\n");
    print_matrix(&sum);

    product = multiply_matrix_by_scalar(&sum, scalar);
    printf("Product of sum and scalar(%d):\n", scalar);
    print_matrix(&product);

    return 0;
}