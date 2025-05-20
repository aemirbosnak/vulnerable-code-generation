//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int row;
    int col;
    int data[SIZE][SIZE];
} Matrix;

Matrix createMatrix(int r, int c) {
    Matrix m;
    m.row = r;
    m.col = c;
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            m.data[i][j] = 0;
        }
    }
    return m;
}

void printMatrix(Matrix m) {
    int i, j;
    printf("\n%d X %d Matrix:\n", m.row, m.col);
    for (i = 0; i < m.row; i++) {
        for (j = 0; j < m.col; j++) {
            printf("%4d", m.data[i][j]);
        }
        printf("\n");
    }
}

Matrix addMatrices(Matrix a, Matrix b) {
    Matrix c;
    c = createMatrix(a.row, a.col);
    int i, j;
    for (i = 0; i < a.row; i++) {
        for (j = 0; j < a.col; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

Matrix multiplyMatrices(Matrix a, Matrix b) {
    Matrix c;
    c = createMatrix(a.row, b.col);
    int i, j, k;
    for (i = 0; i < a.row; i++) {
        for (j = 0; j < b.col; j++) {
            for (k = 0; k < a.col; k++) {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
}

int main() {
    Matrix A, B, C, D;
    A = createMatrix(3, 3);
    B = createMatrix(3, 3);
    printf("Enter the elements of Matrix A:\n");
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &A.data[i][j]);
        }
    }
    printf("Enter the elements of Matrix B:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &B.data[i][j]);
        }
    }
    printMatrix(A);
    printMatrix(B);
    C = addMatrices(A, B);
    printf("\nSum of Matrices A and B:\n");
    printMatrix(C);
    D = multiplyMatrices(A, B);
    printf("\nProduct of Matrices A and B:\n");
    printMatrix(D);
    return 0;
}