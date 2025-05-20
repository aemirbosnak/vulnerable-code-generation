//FormAI DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void matrixAddition(int **matrix1, int **matrix2, int **result, int rows, int columns);
void matrixSubtraction(int **matrix1, int **matrix2, int **result, int rows, int columns);
void matrixMultiplication(int **matrix1, int **matrix2, int **result, int rows1, int columns1, int rows2, int columns2);
void matrixTranspose(int **matrix, int **result, int rows, int columns);

int main() {
    int rows1, columns1, rows2, columns2;
    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &columns1);
    printf("Enter number of rows for matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &columns2);
    if (columns1 != rows2) {
        printf("Matrix dimensions do not match for multiplication!\n");
        return 0;
    }
    // Dynamically allocating memory for matrices
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++)
        matrix1[i] = (int *)malloc(columns1 * sizeof(int));
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++)
        matrix2[i] = (int *)malloc(columns2 * sizeof(int));
    // Populating matrices
    printf("Enter elements for matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter elements for matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    // Dynamically allocating memory for result matrices
    int **additionResult = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++)
        additionResult[i] = (int *)malloc(columns1 * sizeof(int));
    int **subtractionResult = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++)
        subtractionResult[i] = (int *)malloc(columns1 * sizeof(int));
    int **multiplicationResult = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++)
        multiplicationResult[i] = (int *)malloc(columns2 * sizeof(int));
    int **transposeResult1 = (int **)malloc(columns1 * sizeof(int *));
    for (int i = 0; i < columns1; i++)
        transposeResult1[i] = (int *)malloc(rows1 * sizeof(int));
    int **transposeResult2 = (int **)malloc(columns2 * sizeof(int *));
    for (int i = 0; i < columns2; i++)
        transposeResult2[i] = (int *)malloc(rows2 * sizeof(int));
    // Performing operations
    matrixAddition(matrix1, matrix2, additionResult, rows1, columns1);
    matrixSubtraction(matrix1, matrix2, subtractionResult, rows1, columns1);
    matrixMultiplication(matrix1, matrix2, multiplicationResult, rows1, columns1, rows2, columns2);
    matrixTranspose(matrix1, transposeResult1, rows1, columns1);
    matrixTranspose(matrix2, transposeResult2, rows2, columns2);
    // Outputting results
    printf("Matrix Addition Result:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            printf("%d ", additionResult[i][j]);
        }
        printf("\n");
    }
    printf("Matrix Subtraction Result:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            printf("%d ", subtractionResult[i][j]);
        }
        printf("\n");
    }
    printf("Matrix Multiplication Result:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            printf("%d ", multiplicationResult[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 1 Transpose Result:\n");
    for (int i = 0; i < columns1; i++) {
        for (int j = 0; j < rows1; j++) {
            printf("%d ", transposeResult1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2 Transpose Result:\n");
    for (int i = 0; i < columns2; i++) {
        for (int j = 0; j < rows2; j++) {
            printf("%d ", transposeResult2[i][j]);
        }
        printf("\n");
    }
    // Freeing allocated memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(additionResult[i]);
        free(subtractionResult[i]);
        free(multiplicationResult[i]);
        free(transposeResult1[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
        free(transposeResult2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(additionResult);
    free(subtractionResult);
    free(multiplicationResult);
    free(transposeResult1);
    free(transposeResult2);
    return 0;
}

void matrixAddition(int **matrix1, int **matrix2, int **result, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int **matrix1, int **matrix2, int **result, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrixMultiplication(int **matrix1, int **matrix2, int **result, int rows1, int columns1, int rows2, int columns2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < rows2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void matrixTranspose(int **matrix, int **result, int rows, int columns) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}