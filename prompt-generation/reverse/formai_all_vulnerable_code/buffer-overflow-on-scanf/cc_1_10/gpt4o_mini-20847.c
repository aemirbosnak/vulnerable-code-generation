//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

void allocateMatrix(int ***matrix, int rows, int cols) {
    *matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = malloc(cols * sizeof(int));
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixAdd(int **A, int **B, int ***result, int rows, int cols) {
    allocateMatrix(result, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            (*result)[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrixSubtract(int **A, int **B, int ***result, int rows, int cols) {
    allocateMatrix(result, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            (*result)[i][j] = A[i][j] - B[i][j];
        }
    }
}

void matrixMultiply(int **A, int **B, int ***result, int A_rows, int A_cols, int B_cols) {
    allocateMatrix(result, A_rows, B_cols);
    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            (*result)[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < A_cols; k++) {
                (*result)[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrixTranspose(int **A, int ***result, int rows, int cols) {
    allocateMatrix(result, cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            (*result)[j][i] = A[i][j];
        }
    }
}

int main() {
    int rows, cols;
    
    printf("Enter number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    int **A, **B;
    allocateMatrix(&A, rows, cols);
    allocateMatrix(&B, rows, cols);

    printf("Enter elements of first matrix (A):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of second matrix (B):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int **result;

    // Perform addition
    matrixAdd(A, B, &result, rows, cols);
    printf("Result of A + B:\n");
    printMatrix(result, rows, cols);
    freeMatrix(result, rows);

    // Perform subtraction
    matrixSubtract(A, B, &result, rows, cols);
    printf("Result of A - B:\n");
    printMatrix(result, rows, cols);
    freeMatrix(result, rows);

    // Perform multiplication
    int **C;
    int newCols;
    printf("Enter number of columns in second matrix for multiplication: ");
    scanf("%d", &newCols);
    
    allocateMatrix(&C, cols, newCols);
    printf("Enter elements of second matrix (C) for multiplication:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < newCols; j++) {
            scanf("%d", &C[i][j]);
        }
    }

    matrixMultiply(A, C, &result, rows, cols, newCols);
    printf("Result of A * C:\n");
    printMatrix(result, rows, newCols);
    freeMatrix(result, rows);
    freeMatrix(C, cols);

    // Transpose of A
    matrixTranspose(A, &result, rows, cols);
    printf("Transpose of A:\n");
    printMatrix(result, cols, rows);
    freeMatrix(result, cols);

    freeMatrix(A, rows);
    freeMatrix(B, rows);

    return 0;
}