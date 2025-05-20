//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#define ROWS 3
#define COLS 3

typedef struct {
    float data[ROWS][COLS];
} Matrix;

void printMatrix(const Matrix *m) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%.2f ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix multiplyMatrices(const Matrix *a, const Matrix *b) {
    Matrix result;
    int i, j, k;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result.data[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}

int main() {
    Matrix a, b, c;
    int i, j;

    printf("Enter elements of first matrix A:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%f", &a.data[i][j]);
        }
    }

    printf("Enter elements of second matrix B:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%f", &b.data[i][j]);
        }
    }

    c = multiplyMatrices(&a, &b);

    printf("\nMatrix A:\n");
    printMatrix(&a);

    printf("\nMatrix B:\n");
    printMatrix(&b);

    printf("\nProduct of A and B:\n");
    printMatrix(&c);

    return 0;
}