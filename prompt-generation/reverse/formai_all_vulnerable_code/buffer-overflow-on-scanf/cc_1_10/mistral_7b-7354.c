//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>
#define SIZE 3

typedef struct {
    float data[SIZE][SIZE];
} matrix;

void print_matrix(const char *name, const matrix *m) {
    printf("%s:\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf(" %.2f", m->data[i][j]);
        printf("\n");
    }
}

matrix add_matrices(const matrix *a, const matrix *b) {
    matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            result.data[i][j] = a->data[i][j] + b->data[i][j];
    }
    return result;
}

matrix multiply_matrices(const matrix *a, const matrix *b) {
    matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
                result.data[i][j] += a->data[i][k] * b->data[k][j];
        }
    }
    return result;
}

int main() {
    matrix a, b, sum, product;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%f", &a.data[i][j]);
            scanf("%f", &b.data[i][j]);
        }
    }

    print_matrix("Matrix A:", &a);
    print_matrix("Matrix B:", &b);

    sum = add_matrices(&a, &b);
    print_matrix("Sum:", &sum);

    product = multiply_matrices(&a, &b);
    print_matrix("Product:", &product);

    return 0;
}