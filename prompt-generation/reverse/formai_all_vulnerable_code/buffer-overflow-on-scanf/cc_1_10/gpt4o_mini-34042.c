//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

void initMatrix(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = 0;
        }
    }
}

void readMatrix(Matrix *m) {
    printf("Enter the elements of the matrix (%d x %d):\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m->data[i][j]);
        }
    }
}

void printMatrix(const Matrix *m) {
    printf("Matrix (%d x %d):\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix addMatrices(const Matrix *a, const Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Error: Matrices must be of the same size to add.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result;
    initMatrix(&result, a->rows, a->cols);

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return result;
}

Matrix multiplyMatrices(const Matrix *a, const Matrix *b) {
    if (a->cols != b->rows) {
        fprintf(stderr, "Error: Incompatible matrix sizes for multiplication.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result;
    initMatrix(&result, a->rows, b->cols);

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    return result;
}

Matrix transposeMatrix(const Matrix *m) {
    Matrix result;
    initMatrix(&result, m->cols, m->rows);

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result.data[j][i] = m->data[i][j];
        }
    }

    return result;
}

void freeMatrix(Matrix *m) {
    // In this specific case, no dynamic memory allocation is used,
    // but a function is added for consistency in case of future modifications.
}

int main() {
    Matrix A, B, C;
    int rowsA, colsA, rowsB, colsB;

    printf("Matrix A:\n");
    printf("Enter number of rows and columns (max %d): ", MAX_SIZE);
    scanf("%d %d", &rowsA, &colsA);

    initMatrix(&A, rowsA, colsA);
    readMatrix(&A);
    printMatrix(&A);

    printf("\nMatrix B:\n");
    printf("Enter number of rows and columns (max %d): ", MAX_SIZE);
    scanf("%d %d", &rowsB, &colsB);

    initMatrix(&B, rowsB, colsB);
    readMatrix(&B);
    printMatrix(&B);

    // Matrix Addition
    if (rowsA == rowsB && colsA == colsB) {
        C = addMatrices(&A, &B);
        printf("\nResult of A + B:\n");
        printMatrix(&C);
    } else {
        printf("Matrices A and B cannot be added.\n");
    }

    // Matrix Multiplication
    if (colsA == rowsB) {
        C = multiplyMatrices(&A, &B);
        printf("\nResult of A * B:\n");
        printMatrix(&C);
    } else {
        printf("Matrices A and B cannot be multiplied.\n");
    }

    // Transpose
    C = transposeMatrix(&A);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(&C);

    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);

    return 0;
}