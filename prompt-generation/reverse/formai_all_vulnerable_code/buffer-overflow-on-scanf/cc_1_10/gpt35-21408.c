//FormAI DATASET v1.0 Category: Matrix operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void matrixTranspose(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = i + 1; j < columns; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

void matrixMultiplication(int matrixA[MAX_SIZE][MAX_SIZE], int rowsA, int columnsA, int matrixB[MAX_SIZE][MAX_SIZE], int rowsB, int columnsB, int result[MAX_SIZE][MAX_SIZE]) {
    if(columnsA != rowsB) {
        printf("Matrices cannot be multiplied!\n");
        return;
    }

    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < columnsB; j++) {
            int sum = 0;
            for(int k = 0; k < columnsA; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    int rowsA, columnsA, rowsB, columnsB;

    printf("Please enter the number of rows for matrix A (max %d): ", MAX_SIZE);
    scanf("%d", &rowsA);

    printf("Please enter the number of columns for matrix A (max %d): ", MAX_SIZE);
    scanf("%d", &columnsA);

    printf("Please enter the number of rows for matrix B (max %d): ", MAX_SIZE);
    scanf("%d", &rowsB);

    printf("Please enter the number of columns for matrix B (max %d): ", MAX_SIZE);
    scanf("%d", &columnsB);

    printf("Please enter the elements of matrix A:\n");
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < columnsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Please enter the elements of matrix B:\n");
    for(int i = 0; i < rowsB; i++) {
        for(int j = 0; j < columnsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("Matrix A:\n");
    printMatrix(matrixA, rowsA, columnsA);

    printf("Matrix B:\n");
    printMatrix(matrixB, rowsB, columnsB);

    printf("Transposing matrix A...\n");
    matrixTranspose(matrixA, rowsA, columnsA);
    printf("Transposed matrix A:\n");
    printMatrix(matrixA, columnsA, rowsA);

    printf("Multiplying matrix A and B...\n");
    matrixMultiplication(matrixA, columnsA, rowsA, matrixB, rowsB, columnsB, result);
    printf("Result:\n");
    printMatrix(result, rowsA, columnsB);

    return 0;
}