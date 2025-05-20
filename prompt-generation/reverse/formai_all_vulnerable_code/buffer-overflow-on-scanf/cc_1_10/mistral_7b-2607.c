//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_MATRIX_SIZE 10

typedef struct {
    int rows, cols;
    int data[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
} Matrix;

void initMatrix(Matrix *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
}

void inputMatrix(Matrix *mat) {
    int i, j;

    for (i = 0; i < mat->rows; i++)
        for (j = 0; j < mat->cols; j++)
            scanf("%d", &mat->data[i][j]);
}

void printMatrix(const Matrix *mat) {
    int i, j;

    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++)
            printf("%4d", mat->data[i][j]);
        printf("\n");
    }
}

void transpose(const Matrix *mat, Matrix *transposeMat) {
    int i, j;

    initMatrix(transposeMat, mat->cols, mat->rows);

    for (i = 0; i < mat->rows; i++)
        for (j = 0; j < mat->cols; j++)
            transposeMat->data[j][i] = mat->data[i][j];
}

void multiplyMatrices(const Matrix *mat1, const Matrix *mat2, Matrix *result) {
    int i, j, k;

    initMatrix(result, mat1->rows, mat2->cols);

    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            for (k = 0; k < mat1->cols; k++)
                result->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
        }
    }
}

int main() {
    Matrix mat1, mat2, result, transposeMat1;
    int rows1, cols1, rows2, cols2;

    printf("Enter dimensions of first matrix (rows columns): ");
    scanf("%d%d", &rows1, &cols1);
    initMatrix(&mat1, rows1, cols1);
    printf("Enter elements of first matrix:\n");
    inputMatrix(&mat1);

    printf("Enter dimensions of second matrix (rows columns): ");
    scanf("%d%d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix dimensions are not compatible for multiplication.\n");
        return 1;
    }

    initMatrix(&mat2, rows2, cols2);
    printf("Enter elements of second matrix:\n");
    inputMatrix(&mat2);

    transpose(&mat1, &transposeMat1);
    printf("Transpose of first matrix:\n");
    printMatrix(&transposeMat1);

    multiplyMatrices(&mat1, &mat2, &result);
    printf("Product of first and second matrices:\n");
    printMatrix(&result);

    return 0;
}