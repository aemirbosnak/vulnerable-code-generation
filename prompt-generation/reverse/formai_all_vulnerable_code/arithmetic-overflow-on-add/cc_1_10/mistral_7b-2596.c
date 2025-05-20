//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

typedef struct {
    int data[ROWS][COLS];
} matrix;

void print_matrix(const matrix* m);
matrix add_matrices(const matrix* a, const matrix* b);
matrix multiply_matrices(const matrix* a, const matrix* b);

int main() {
    srand(time(NULL));

    matrix a, b, c;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            a.data[i][j] = rand() % 10 + 1;
            b.data[i][j] = rand() % 10 + 1;
        }
    }

    print_matrix(&a);
    printf(" + ");
    print_matrix(&b);
    printf(" = ");

    c = add_matrices(&a, &b);
    print_matrix(&c);

    printf("\n\n");

    print_matrix(&a);
    printf(" * ");
    print_matrix(&b);
    printf(" = ");

    c = multiply_matrices(&a, &b);
    print_matrix(&c);

    return 0;
}

void print_matrix(const matrix* m) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%3d", m->data[i][j]);
        }
        printf("\n");
    }
}

matrix add_matrices(const matrix* a, const matrix* b) {
    matrix c;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            c.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return c;
}

matrix multiply_matrices(const matrix* a, const matrix* b) {
    matrix c;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            for (int k = 0; k < COLS; ++k) {
                c.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return c;
}