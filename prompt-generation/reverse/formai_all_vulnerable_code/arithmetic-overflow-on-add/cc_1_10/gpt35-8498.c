//FormAI DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][COLS], int matrix2[][COLS], int result[][COLS], int rows1, int cols1, int rows2, int cols2) {
    if(cols1 != rows2) {
        printf("Error: The number of columns in the first matrix must equal the number of rows in the second matrix.\n");
        exit(1);
    }
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols2; j++) {
            result[i][j] = 0;
            for(int k=0; k<cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix2[ROWS][COLS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int result[ROWS][COLS];

    printf("Matrix 1:\n");
    printMatrix(matrix1, ROWS, COLS);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, ROWS, COLS);

    addMatrices(matrix1, matrix2, result, ROWS, COLS);
    printf("\nMatrix Sum (Matrix 1 + Matrix 2):\n");
    printMatrix(result, ROWS, COLS);

    subtractMatrices(matrix1, matrix2, result, ROWS, COLS);
    printf("\nMatrix Difference (Matrix 1 - Matrix 2):\n");
    printMatrix(result, ROWS, COLS);

    int rows1 = ROWS;
    int cols1 = COLS;
    int rows2 = COLS;
    int cols2 = ROWS;

    int matrix3[rows1][cols1];
    int matrix4[rows2][cols2];

    printf("\nEnter Matrix 1 (%d x %d):\n", rows1, cols1);
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols1; j++) {
            scanf("%d", &matrix3[i][j]);
        }
    }

    printf("\nEnter Matrix 2 (%d x %d):\n", rows2, cols2);
    for(int i=0; i<rows2; i++) {
        for(int j=0; j<cols2; j++) {
            scanf("%d", &matrix4[i][j]);
        }
    }

    multiplyMatrices(matrix3, matrix4, result, rows1, cols1, rows2, cols2);
    printf("\nMatrix Product (Matrix 1 * Matrix 2):\n");
    printMatrix(result, rows1, cols2);

    return 0;
}