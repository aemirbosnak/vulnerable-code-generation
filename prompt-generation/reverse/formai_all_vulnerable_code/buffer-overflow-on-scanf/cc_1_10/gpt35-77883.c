//FormAI DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>

// function to print a matrix
void printMatrix(int matrix[][100], int rows, int cols) {
    printf("Matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
void addMatrix(int matrix1[][100], int matrix2[][100], int resultMatrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// function to subtract two matrices
void subtractMatrix(int matrix1[][100], int matrix2[][100], int resultMatrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// function to multiply two matrices
void multiplyMatrix(int matrix1[][100], int matrix2[][100], int resultMatrix[][100], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[100][100], matrix2[100][100], resultMatrix[100][100];
    int rows1, cols1, rows2, cols2;

    // take input for matrix1
    printf("Enter number of rows and columns for matrix1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter elements of matrix1: \n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // take input for matrix2
    printf("Enter number of rows and columns for matrix2: ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter elements of matrix2: \n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // check if matrices can be added, subtracted, or multiplied
    if (rows1 == rows2 && cols1 == cols2) {
        printf("Matrices can be added and subtracted!\n");
        addMatrix(matrix1, matrix2, resultMatrix, rows1, cols1);
        printMatrix(resultMatrix, rows1, cols1);

        subtractMatrix(matrix1, matrix2, resultMatrix, rows1, cols1);
        printMatrix(resultMatrix, rows1, cols1);
    }
    if (cols1 == rows2) {
        printf("Matrices can be multiplied!\n");
        multiplyMatrix(matrix1, matrix2, resultMatrix, rows1, cols1, cols2);
        printMatrix(resultMatrix, rows1, cols2);
    }
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices can't be added or subtracted!\n");
    }
    if (cols1 != rows2) {
        printf("Matrices can't be multiplied!\n");
    }

    return 0;
}