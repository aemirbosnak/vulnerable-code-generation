//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Here's your matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void subtractMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
}

void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int main() {
    int firstMatrix[MAX][MAX], secondMatrix[MAX][MAX], resultMatrix[MAX][MAX];
    int rows, cols;

    printf("Welcome to the Matrix Wizard! 🎩✨\n");
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    inputMatrix(firstMatrix, rows, cols);
    printMatrix(firstMatrix, rows, cols);
    
    inputMatrix(secondMatrix, rows, cols);
    printMatrix(secondMatrix, rows, cols);

    addMatrices(firstMatrix, secondMatrix, resultMatrix, rows, cols);
    printf("🎉 Result of Matrix Addition:\n");
    printMatrix(resultMatrix, rows, cols);

    subtractMatrices(firstMatrix, secondMatrix, resultMatrix, rows, cols);
    printf("💥 Result of Matrix Subtraction:\n");
    printMatrix(resultMatrix, rows, cols);

    printf("⏳ For multiplication, please enter the number of columns for the second matrix: ");
    int cols2;
    scanf("%d", &cols2);

    int secondMatrixForMultiplication[MAX][MAX];
    inputMatrix(secondMatrixForMultiplication, cols, cols2);
    printf("Your second matrix for multiplication:\n");
    printMatrix(secondMatrixForMultiplication, cols, cols2);

    multiplyMatrices(firstMatrix, secondMatrixForMultiplication, resultMatrix, rows, cols, cols2);
    printf("🚀 Result of Matrix Multiplication:\n");
    printMatrix(resultMatrix, rows, cols2);

    printf("🌟 Thanks for using the Matrix Wizard! Have a great day! 🎉\n");
    return 0;
}