//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct matrix {
    int data[SIZE][SIZE];
} matrix;

matrix create_matrix(const char *name) {
    matrix m;
    int i, j;

    printf("Enter %s matrix elements:\n", name);

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &m.data[i][j]);
        }
    }

    return m;
}

void print_matrix(const char *name, const matrix m) {
    int i, j;

    printf("\n%s Matrix:\n", name);

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%5d", m.data[i][j]);
        }
        printf("\n");
    }
}

matrix multiply_matrices(const matrix a, const matrix b) {
    matrix result;
    int i, j, k;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return result;
}

int main() {
    matrix a = {0}, b = {0}, product = {0};

    a = create_matrix("First matrix");
    b = create_matrix("Second matrix");

    printf("Multiplying %s and %s...\n", "First", "Second");

    product = multiply_matrices(a, b);

    print_matrix("Product", product);

    return 0;
}