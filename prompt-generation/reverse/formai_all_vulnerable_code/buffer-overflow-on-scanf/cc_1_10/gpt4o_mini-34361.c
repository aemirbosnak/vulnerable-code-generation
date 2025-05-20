//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void addMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res[i][j] = m1[i][j] + m2[i][j];
}

void subtractMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            res[i][j] = m1[i][j] - m2[i][j];
}

void multiplyMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0; // Initialize result element
            for (int k = 0; k < c1; k++)
                res[i][j] += m1[i][k] * m2[k][j];
        }
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], res[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d %d", &r1, &c1);

    inputMatrix(matrix1, r1, c1);

    printf("Enter rows and columns for Matrix 2: ");
    scanf("%d %d", &r2, &c2);

    if (r1 != r2 || c1 != c2) {
        printf("Matrix addition and subtraction are not possible with the given sizes.\n");
        return EXIT_FAILURE;
    }

    inputMatrix(matrix2, r2, c2);

    printf("\nMatrix 1:\n");
    printMatrix(matrix1, r1, c1);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2, r2, c2);

    addMatrices(matrix1, matrix2, res, r1, c1);
    printf("\nSum of matrices:\n");
    printMatrix(res, r1, c1);

    subtractMatrices(matrix1, matrix2, res, r1, c1);
    printf("\nDifference of matrices:\n");
    printMatrix(res, r1, c1);

    if (c1 != r2) {
        printf("Matrix multiplication is not possible with the given sizes.\n");
    } else {
        multiplyMatrices(matrix1, matrix2, res, r1, c1, c2);
        printf("\nProduct of matrices:\n");
        printMatrix(res, r1, c2);
    }

    return EXIT_SUCCESS;
}