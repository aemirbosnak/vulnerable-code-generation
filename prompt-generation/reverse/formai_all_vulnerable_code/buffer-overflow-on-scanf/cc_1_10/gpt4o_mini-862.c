//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int aRows, int aCols, int bCols);
void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols);

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rows, cols;

    printf("Welcome to the Matrix Operations Program!\n");
    
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Input the first matrix:\n");
    inputMatrix(a, rows, cols);
    
    printf("Input the second matrix:\n");
    inputMatrix(b, rows, cols);

    printf("\nFirst Matrix:\n");
    displayMatrix(a, rows, cols);
    
    printf("\nSecond Matrix:\n");
    displayMatrix(b, rows, cols);

    printf("\nAdding the two matrices:\n");
    addMatrices(a, b, result, rows, cols);
    displayMatrix(result, rows, cols);

    printf("\nSubtracting the second matrix from the first:\n");
    subtractMatrices(a, b, result, rows, cols);
    displayMatrix(result, rows, cols);

    printf("\nMultiplying the two matrices:\n");
    multiplyMatrices(a, b, result, rows, cols, cols); // bCols is same as cols here
    displayMatrix(result, rows, cols);

    printf("\nTransposing the first matrix:\n");
    transposeMatrix(a, result, rows, cols);
    displayMatrix(result, cols, rows); // Rows and cols are swapped during transposition

    return 0;
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
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

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int aRows, int aCols, int bCols) {
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < aCols; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}