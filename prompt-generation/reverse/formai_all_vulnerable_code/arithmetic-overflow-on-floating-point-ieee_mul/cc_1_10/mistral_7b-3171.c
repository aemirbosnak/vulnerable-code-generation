//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    float data[SIZE][SIZE];
} Matrix;

void print_matrix(const Matrix *m) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%.2f ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix add_matrices(const Matrix *m1, const Matrix *m2) {
    Matrix result;
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result.data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }

    return result;
}

Matrix multiply_matrices(const Matrix *m1, const Matrix *m2) {
    Matrix result;
    int i, j, k;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                result.data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }

    return result;
}

int main() {
    Matrix m1, m2, sum, prod;
    int i, j;

    m1.data[0][0] = 1.0; m1.data[0][1] = 2.0; m1.data[0][2] = 3.0;
    m1.data[1][0] = 4.0; m1.data[1][1] = 5.0; m1.data[1][2] = 6.0;
    m1.data[2][0] = 7.0; m1.data[2][1] = 8.0; m1.data[2][2] = 9.0;

    m2.data[0][0] = 1.0; m2.data[0][1] = 3.0; m2.data[0][2] = 5.0;
    m2.data[1][0] = 4.0; m2.data[1][1] = 5.0; m2.data[1][2] = 6.0;
    m2.data[2][0] = 7.0; m2.data[2][1] = 8.0; m2.data[2][2] = 9.0;

    printf("First Matrix:\n");
    print_matrix(&m1);

    printf("Second Matrix:\n");
    print_matrix(&m2);

    sum = add_matrices(&m1, &m2);

    printf("Sum of Matrices:\n");
    print_matrix(&sum);

    prod = multiply_matrices(&m1, &m2);

    printf("Product of Matrices:\n");
    print_matrix(&prod);

    return 0;
}