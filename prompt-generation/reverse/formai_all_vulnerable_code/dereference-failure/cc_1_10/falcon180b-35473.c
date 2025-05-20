//Falcon-180B DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int row;
    int col;
    int value;
} Cell;

typedef struct {
    int rows;
    int cols;
    Cell data[MAX_ROWS][MAX_COLS];
} Matrix;

Matrix* create_matrix(int rows, int cols) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix->data[i][j].row = i;
            matrix->data[i][j].col = j;
            matrix->data[i][j].value = 0;
        }
    }

    return matrix;
}

void add_value(Matrix* matrix, int row, int col, int value) {
    matrix->data[row][col].value += value;
}

void print_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j].value);
        }
        printf("\n");
    }
}

int main() {
    Matrix* matrix = create_matrix(10, 10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            add_value(matrix, i, j, i + j);
        }
    }

    print_matrix(matrix);

    return 0;
}