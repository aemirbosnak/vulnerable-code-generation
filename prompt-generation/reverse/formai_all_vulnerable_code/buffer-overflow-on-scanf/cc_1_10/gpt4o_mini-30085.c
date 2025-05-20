//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    int data[MAX_ROWS][MAX_COLS];
} Matrix;

void printMatrix(Matrix *m);
Matrix addMatrices(Matrix *a, Matrix *b);
Matrix subtractMatrices(Matrix *a, Matrix *b);
Matrix multiplyMatrices(Matrix *a, Matrix *b);
Matrix transposeMatrix(Matrix *m);
void inputMatrix(Matrix *m);
void freeMatrix(Matrix *m);

int main() {
    Matrix A, B, result;
    int choice;

    printf("Matrix Operations Program\n");
    printf("=========================\n");

    // Input for first matrix
    printf("Input the first matrix A:\n");
    inputMatrix(&A);
    printMatrix(&A);

    // Input for second matrix
    printf("Input the second matrix B:\n");
    inputMatrix(&B);
    printMatrix(&B);

    while (1) {
        printf("\nSelect operation:\n");
        printf("1. Addition (A + B)\n");
        printf("2. Subtraction (A - B)\n");
        printf("3. Multiplication (A * B)\n");
        printf("4. Transpose of A\n");
        printf("5. Transpose of B\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (A.rows == B.rows && A.cols == B.cols) {
                    result = addMatrices(&A, &B);
                    printf("Result of A + B:\n");
                    printMatrix(&result);
                } else {
                    printf("Matrices dimensions do not match for addition.\n");
                }
                break;

            case 2:
                if (A.rows == B.rows && A.cols == B.cols) {
                    result = subtractMatrices(&A, &B);
                    printf("Result of A - B:\n");
                    printMatrix(&result);
                } else {
                    printf("Matrices dimensions do not match for subtraction.\n");
                }
                break;

            case 3:
                if (A.cols == B.rows) {
                    result = multiplyMatrices(&A, &B);
                    printf("Result of A * B:\n");
                    printMatrix(&result);
                } else {
                    printf("Matrices dimensions do not match for multiplication.\n");
                }
                break;

            case 4:
                result = transposeMatrix(&A);
                printf("Transpose of A:\n");
                printMatrix(&result);
                break;

            case 5:
                result = transposeMatrix(&B);
                printf("Transpose of B:\n");
                printMatrix(&result);
                break;

            case 6:
                printf("Exiting the program.\n");
                freeMatrix(&A);
                freeMatrix(&B);
                return 0;

            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}

void inputMatrix(Matrix *m) {
    printf("Enter number of rows and columns (e.g., 2 3): ");
    scanf("%d %d", &m->rows, &m->cols);
    if (m->rows > MAX_ROWS || m->cols > MAX_COLS || m->rows <= 0 || m->cols <= 0) {
        printf("Invalid matrix size!\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            scanf("%d", &m->data[i][j]);
        }
    }
}

void printMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix addMatrices(Matrix *a, Matrix *b) {
    Matrix result;
    result.rows = a->rows;
    result.cols = a->cols;
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < a->cols; ++j) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

Matrix subtractMatrices(Matrix *a, Matrix *b) {
    Matrix result;
    result.rows = a->rows;
    result.cols = a->cols;
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < a->cols; ++j) {
            result.data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return result;
}

Matrix multiplyMatrices(Matrix *a, Matrix *b) {
    Matrix result;
    result.rows = a->rows;
    result.cols = b->cols;
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < b->cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < a->cols; ++k) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

Matrix transposeMatrix(Matrix *m) {
    Matrix result;
    result.rows = m->cols;
    result.cols = m->rows;
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            result.data[j][i] = m->data[i][j];
        }
    }
    return result;
}

void freeMatrix(Matrix *m) {
    // In this case we do not have dynamic allocations, but this is here for completeness
    m->rows = 0;
    m->cols = 0;
}