//FormAI DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#define MAX_SIZE 10

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int i, int j);
void addMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols, int i, int j);
void subtractMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols, int i, int j);
void multiplyMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB, int i, int j, int k);


int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB, i, j, k;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("\nMatrix A:\n");
    printMatrix(matrixA, rowsA, colsA, 0, 0);

    printf("\nMatrix B:\n");
    printMatrix(matrixB, rowsB, colsB, 0, 0);

    if (rowsA == rowsB && colsA == colsB) {
        printf("\nAdding A and B:\n");
        addMatrix(matrixA, matrixB, result, rowsA, colsA, 0, 0);
        printMatrix(result, rowsA, colsA, 0, 0);

        printf("\nSubtracting A and B:\n");
        subtractMatrix(matrixA, matrixB, result, rowsA, colsA, 0, 0);
        printMatrix(result, rowsA, colsA, 0, 0);
    } else {
        printf("\nCannot add or subtract matrix A and B because they are not of the same size.\n");
    }

    if (colsA == rowsB) {
        printf("\nMultiplying A and B:\n");
        multiplyMatrix(matrixA, matrixB, result, rowsA, colsA, rowsB, colsB, 0, 0, 0);
        printMatrix(result, rowsA, colsB, 0, 0);
    } else {
        printf("\nCannot multiply matrix A and B because their dimensions are not compatible.\n");
    }

    return 0;
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int i, int j) {
    printf("%d ", matrix[i][j]);
    
    if (j == cols - 1) {
        printf("\n");
        i++;
        j = 0;
    } else {
        j++;
    }

    if (i < rows) {
        printMatrix(matrix, rows, cols, i, j);
    }
}

void addMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols, int i, int j) {
    result[i][j] = matrixA[i][j] + matrixB[i][j];

    if (j == cols - 1) {
        i++;
        j = 0;
    } else {
        j++;
    }

    if (i < rows) {
        addMatrix(matrixA, matrixB, result, rows, cols, i, j);
    }
}

void subtractMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols, int i, int j) {
    result[i][j] = matrixA[i][j] - matrixB[i][j];

    if (j == cols - 1) {
        i++;
        j = 0;
    } else {
        j++;
    }

    if (i < rows) {
        subtractMatrix(matrixA, matrixB, result, rows, cols, i, j);
    }
}

void multiplyMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB, int i, int j, int k) {
    result[i][j] += matrixA[i][k] * matrixB[k][j];

    if (k == colsA - 1) {
        if (j == colsB - 1) {
            i++;
            j = 0;
        } else {
            j++;
        }
        k = 0;
    } else {
        k++;
    }

    if (i < rowsA && j < colsB) {
        multiplyMatrix(matrixA, matrixB, result, rowsA, colsA, rowsB, colsB, i, j, k);
    }
}