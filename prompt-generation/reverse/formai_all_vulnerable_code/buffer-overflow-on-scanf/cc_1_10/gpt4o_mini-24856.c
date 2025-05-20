//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void printMatrix(int matrix[MAX][MAX], int row, int col);
void addMatrix(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int row, int col);
void subtractMatrix(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int row, int col);
void multiplyMatrix(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int row1, int col1, int col2);
void transposeMatrix(int matrix[MAX][MAX], int res[MAX][MAX], int row, int col);

int main() {
    int m1[MAX][MAX], m2[MAX][MAX], res[MAX][MAX];
    int row1, col1, row2, col2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);
    
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);
    
    if (row2 != row1 || col2 != col1) {
        printf("Matrix addition and subtraction require same dimensions.\n");
        return -1;
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m2[i][j]);
        }
    }

    // Add the matrices
    addMatrix(m1, m2, res, row1, col1);
    printf("Result of Addition:\n");
    printMatrix(res, row1, col1);

    // Subtract the matrices
    subtractMatrix(m1, m2, res, row1, col1);
    printf("Result of Subtraction:\n");
    printMatrix(res, row1, col1);

    // Multiply the matrices if possible (checking for multiplication compatibility)
    if (col1 == row2) {
        multiplyMatrix(m1, m2, res, row1, col1, col2);
        printf("Result of Multiplication:\n");
        printMatrix(res, row1, col2);
    } else {
        printf("Matrix multiplication is not possible with given dimensions.\n");
    }

    // Transpose the first matrix
    transposeMatrix(m1, res, row1, col1);
    printf("Transpose of the first matrix:\n");
    printMatrix(res, col1, row1);

    return 0;
}

void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void subtractMatrix(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = m1[i][j] - m2[i][j];
        }
    }
}

void multiplyMatrix(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[j][i] = matrix[i][j];
        }
    }
}