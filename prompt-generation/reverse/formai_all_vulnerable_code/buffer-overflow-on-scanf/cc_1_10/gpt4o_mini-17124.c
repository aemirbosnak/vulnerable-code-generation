//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

void initializeMatrix(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            m->data[i][j] = rand() % 10; // Random values between 0 to 9
        }
    }
}

void printMatrix(const Matrix *m) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix addMatrices(const Matrix *m1, const Matrix *m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        fprintf(stderr, "Matrix dimensions do not match for addition.\n");
        exit(EXIT_FAILURE);
    }
    
    Matrix result;
    result.rows = m1->rows;
    result.cols = m1->cols;

    for (int i = 0; i < result.rows; ++i) {
        for (int j = 0; j < result.cols; ++j) {
            result.data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
    
    return result;
}

Matrix multiplyMatrices(const Matrix *m1, const Matrix *m2) {
    if (m1->cols != m2->rows) {
        fprintf(stderr, "Matrix dimensions are not suitable for multiplication.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result;
    result.rows = m1->rows;
    result.cols = m2->cols;

    for (int i = 0; i < result.rows; ++i) {
        for (int j = 0; j < result.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < m1->cols; ++k) {
                result.data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    
    return result;
}

int main() {
    Matrix matrixA, matrixB, addResult, multResult;

    int rowsA, colsA, rowsB, colsB;

    // Input dimensions for matrix A
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    initializeMatrix(&matrixA, rowsA, colsA);

    // Input dimensions for matrix B
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    initializeMatrix(&matrixB, rowsB, colsB);

    printf("\nMatrix A:\n");
    printMatrix(&matrixA);

    printf("\nMatrix B:\n");
    printMatrix(&matrixB);

    // Matrix Addition
    printf("\nAdding matrices...\n");
    if (rowsA == rowsB && colsA == colsB) {
        addResult = addMatrices(&matrixA, &matrixB);
        printf("\nA + B:\n");
        printMatrix(&addResult);
    } else {
        printf("Cannot add matrices with different dimensions.\n");
    }

    // Matrix Multiplication
    printf("\nMultiplying matrices...\n");
    if (colsA == rowsB) {
        multResult = multiplyMatrices(&matrixA, &matrixB);
        printf("\nA * B:\n");
        printMatrix(&multResult);
    } else {
        printf("Cannot multiply matrices with incompatible dimensions.\n");
    }

    return 0;
}