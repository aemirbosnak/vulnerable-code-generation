//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
    int data[SIZE][SIZE];
    int row, col;
} matrix;

void readMatrix(matrix *a) {
    int i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &a->row, &a->col);
    printf("Enter the matrix elements:\n");
    for (i = 0; i < a->row; i++) {
        for (j = 0; j < a->col; j++) {
            scanf("%d", &a->data[i][j]);
        }
    }
}

void displayMatrix(matrix a) {
    int i, j;
    printf("The given matrix is:\n");
    for (i = 0; i < a.row; i++) {
        for (j = 0; j < a.col; j++) {
            printf("%d ", a.data[i][j]);
        }
        printf("\n");
    }
}

matrix addMatrices(matrix a, matrix b) {
    matrix c;
    if (a.row == a.col && b.row == b.col) {
        c.row = a.row;
        c.col = a.col;
        int i, j;
        for (i = 0; i < c.row; i++) {
            for (j = 0; j < c.col; j++) {
                c.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
    } else {
        printf("Error: Matrices can't be added.\n");
        exit(1);
    }
    return c;
}

matrix multiplyMatrices(matrix a, matrix b) {
    matrix c;
    if (a.col == b.row) {
        c.row = a.row;
        c.col = b.col;
        int i, j, k;
        for (i = 0; i < c.row; i++) {
            for (j = 0; j < c.col; j++) {
                c.data[i][j] = 0;
                for (k = 0; k < a.col; k++) {
                    c.data[i][j] += a.data[i][k] * b.data[k][j];
                }
            }
        }
    } else {
        printf("Error: Matrices can't be multiplied.\n");
        exit(1);
    }
    return c;
}

int main() {
    matrix a, b, c, d;
    readMatrix(&a);
    readMatrix(&b);
    displayMatrix(a);
    displayMatrix(b);
    c = addMatrices(a, b);
    displayMatrix(c);
    d = multiplyMatrices(a, b);
    displayMatrix(d);
    return 0;
}