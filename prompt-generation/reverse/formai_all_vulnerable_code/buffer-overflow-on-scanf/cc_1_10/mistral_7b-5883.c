//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>
#define SIZE 3

typedef struct { float elements[SIZE][SIZE]; } matrix;

void print_matrix(const matrix *m) {
    int i, j;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            printf("%.1f ", m->elements[i][j]);
        }
        printf("\n");
    }
}

matrix multiply(const matrix *a, const matrix *b) {
    matrix result;
    int i, j, k;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            result.elements[i][j] = 0;
            for (k = 0; k < SIZE; ++k) {
                result.elements[i][j] += a->elements[i][k] * b->elements[k][j];
            }
        }
    }
    return result;
}

int main() {
    matrix a, b, c;
    int i, j;

    printf("Enter elements of first matrix A:\n");
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            scanf("%f", &a.elements[i][j]);
        }
    }

    printf("Enter elements of second matrix B:\n");
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            scanf("%f", &b.elements[i][j]);
        }
    }

    c = multiply(&a, &b);
    printf("Product of matrix A and B:\n");
    print_matrix(&c);

    return 0;
}