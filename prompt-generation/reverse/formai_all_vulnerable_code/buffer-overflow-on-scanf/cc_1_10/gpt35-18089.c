//FormAI DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>

int readMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the matrix values:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int addMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int multiplyMatrix(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    if(cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    readMatrix(rows1, cols1, matrix1);
    readMatrix(rows2, cols2, matrix2);

    printf("\n");

    // Add the matrices
    addMatrix(rows1, cols1, matrix1, matrix2, result);
    printf("Addition of the matrices:\n");
    printMatrix(rows1, cols1, result);

    printf("\n");

    // Multiply the matrices
    multiplyMatrix(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
    printf("Multiplication of the matrices:\n");
    printMatrix(rows1, cols2, result);

    return 0;
}