//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int firstRows, int firstCols, int secondCols);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int first[MAX_SIZE][MAX_SIZE], second[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &first[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &second[i][j]);
        }
    }

    printf("\nFirst Matrix:\n");
    displayMatrix(first, rows1, cols1);

    printf("\nSecond Matrix:\n");
    displayMatrix(second, rows2, cols2);

    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(first, second, result, rows1, cols1);
        printf("\nSum of both matrices:\n");
        displayMatrix(result, rows1, cols1);
    } else {
        printf("\nMatrices cannot be added due to different dimensions.\n");
    }

    if (cols1 == rows2) {
        multiplyMatrices(first, second, result, rows1, cols1, cols2);
        printf("\nProduct of both matrices:\n");
        displayMatrix(result, rows1, cols2);
    } else {
        printf("\nMatrices cannot be multiplied due to incompatible dimensions.\n");
    }

    transposeMatrix(first, result, rows1, cols1);
    printf("\nTranspose of the first matrix:\n");
    displayMatrix(result, cols1, rows1);

    return 0;
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int firstRows, int firstCols, int secondCols) {
    for (int i = 0; i < firstRows; i++) {
        for (int j = 0; j < secondCols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < firstCols; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}