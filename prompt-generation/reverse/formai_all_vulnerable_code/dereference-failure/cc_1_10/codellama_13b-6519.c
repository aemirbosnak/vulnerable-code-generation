//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

void printMatrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* newMatrix(int rows, int cols) {
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = 0;
        }
    }
    return m;
}

void deleteMatrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

Matrix* addMatrix(Matrix* a, Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return NULL;
    }
    Matrix* c = newMatrix(a->rows, a->cols);
    for (int i = 0; i < c->rows; i++) {
        for (int j = 0; j < c->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

Matrix* multiplyMatrix(Matrix* a, Matrix* b) {
    if (a->cols != b->rows) {
        return NULL;
    }
    Matrix* c = newMatrix(a->rows, b->cols);
    for (int i = 0; i < c->rows; i++) {
        for (int j = 0; j < c->cols; j++) {
            c->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return c;
}

int main() {
    Matrix* m1 = newMatrix(2, 3);
    Matrix* m2 = newMatrix(2, 3);
    m1->data[0][0] = 1;
    m1->data[0][1] = 2;
    m1->data[0][2] = 3;
    m1->data[1][0] = 4;
    m1->data[1][1] = 5;
    m1->data[1][2] = 6;

    m2->data[0][0] = 7;
    m2->data[0][1] = 8;
    m2->data[0][2] = 9;
    m2->data[1][0] = 10;
    m2->data[1][1] = 11;
    m2->data[1][2] = 12;

    Matrix* m3 = addMatrix(m1, m2);
    printMatrix(m3);
    deleteMatrix(m3);

    Matrix* m4 = multiplyMatrix(m1, m2);
    printMatrix(m4);
    deleteMatrix(m4);

    deleteMatrix(m1);
    deleteMatrix(m2);

    return 0;
}