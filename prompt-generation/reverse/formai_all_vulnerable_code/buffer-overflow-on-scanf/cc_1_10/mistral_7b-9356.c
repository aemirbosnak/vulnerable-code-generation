//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
    double elem[SIZE][SIZE];
} matrix;

void initMatrix(matrix *m) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%lf", &m->elem[i][j]);
        }
    }
}

void printMatrix(const matrix *m) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%12.8f", m->elem[i][j]);
            if (j < SIZE - 1)
                printf("  ");
        }
        printf("\n");
    }
}

matrix multiply(const matrix *a, const matrix *b) {
    matrix c;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double sum = 0;
            for (int k = 0; k < SIZE; k++) {
                sum += a->elem[i][k] * b->elem[k][j];
            }
            c.elem[i][j] = sum;
        }
    }

    return c;
}

int main() {
    matrix a, b, c;

    printf("Enter the elements of matrix A:\n");
    initMatrix(&a);

    printf("Enter the elements of matrix B:\n");
    initMatrix(&b);

    c = multiply(&a, &b);

    printf("\nMatrix A:\n");
    printMatrix(&a);

    printf("\nMatrix B:\n");
    printMatrix(&b);

    printf("\nProduct of Matrix A and Matrix B:\n");
    printMatrix(&c);

    return 0;
}