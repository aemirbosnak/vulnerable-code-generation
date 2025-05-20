//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void createMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols);
void multiplyMatrix(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int rows2, int cols2);

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1!= rows2) {
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix for matrix multiplication.\n");
        return 0;
    }

    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];

    createMatrix(matrix1, rows1, cols1);
    createMatrix(matrix2, rows2, cols2);

    printf("Matrix 1:\n");
    displayMatrix(matrix1, rows1, cols1);

    printf("Matrix 2:\n");
    displayMatrix(matrix2, rows2, cols2);

    multiplyMatrix(matrix1, matrix2, result, rows1, cols1, rows2, cols2);

    printf("Result:\n");
    displayMatrix(result, rows1, cols2);

    return 0;
}

void createMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int result[MAX][MAX];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    printf("Transposed matrix:\n");
    displayMatrix(result, cols, rows);
}

void multiplyMatrix(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int rows2, int cols2) {
    if (cols1!= rows2) {
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix for matrix multiplication.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Result:\n");
    displayMatrix(result, rows1, cols2);
}