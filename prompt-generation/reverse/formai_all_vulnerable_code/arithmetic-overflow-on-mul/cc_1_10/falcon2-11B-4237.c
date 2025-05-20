//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int* data;
} Matrix;

Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (int*) malloc(rows * cols * sizeof(int));
    return matrix;
}

void printMatrix(Matrix matrix) {
    int i, j;
    for (i = 0; i < matrix.rows; i++) {
        for (j = 0; j < matrix.cols; j++) {
            printf("%d ", matrix.data[i * matrix.cols + j]);
        }
        printf("\n");
    }
}

void addMatrices(Matrix matrixA, Matrix matrixB) {
    int i, j;
    Matrix matrixC;

    matrixC.rows = matrixA.rows;
    matrixC.cols = matrixB.cols;
    matrixC.data = (int*) malloc(matrixC.rows * matrixC.cols * sizeof(int));

    for (i = 0; i < matrixC.rows; i++) {
        for (j = 0; j < matrixC.cols; j++) {
            matrixC.data[i * matrixC.cols + j] = matrixA.data[i * matrixA.cols + j] + matrixB.data[i * matrixB.cols + j];
        }
    }

    printMatrix(matrixC);
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    Matrix matrixA = createMatrix(rows, cols);
    Matrix matrixB = createMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter the value of matrixA[%d][%d]: ", i, j);
            scanf("%d", &matrixA.data[i * cols + j]);
            printf("Enter the value of matrixB[%d][%d]: ", i, j);
            scanf("%d", &matrixB.data[i * cols + j]);
        }
    }

    addMatrices(matrixA, matrixB);

    return 0;
}