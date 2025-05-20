//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 2

typedef struct Matrix {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix* createMatrix(int r, int c) {
    Matrix* m = malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * c * sizeof(int));
    return m;
}

void printMatrix(Matrix* m) {
    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* addMatrix(Matrix* a, Matrix* b) {
    if(a->rows != b->rows || a->cols != b->cols) {
        return NULL;
    }

    Matrix* c = createMatrix(a->rows, a->cols);

    for(int i = 0; i < a->rows; i++) {
        for(int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return c;
}

int main() {
    Matrix* a = createMatrix(3, 3);
    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[0][2] = 3;
    a->data[1][0] = 4;
    a->data[1][1] = 5;
    a->data[1][2] = 6;
    a->data[2][0] = 7;
    a->data[2][1] = 8;
    a->data[2][2] = 9;

    Matrix* b = createMatrix(3, 3);
    b->data[0][0] = 2;
    b->data[0][1] = 3;
    b->data[0][2] = 4;
    b->data[1][0] = 5;
    b->data[1][1] = 6;
    b->data[1][2] = 7;
    b->data[2][0] = 8;
    b->data[2][1] = 9;
    b->data[2][2] = 10;

    Matrix* c = addMatrix(a, b);

    printMatrix(c);

    return 0;
}