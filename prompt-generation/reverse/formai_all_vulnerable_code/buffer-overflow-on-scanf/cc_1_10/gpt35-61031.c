//FormAI DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>

void addMatrices(int a[][100], int b[][100], int result[][100], int rows, int columns) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[][100], int b[][100], int result[][100], int rows, int columns) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[][100], int b[][100], int result[][100], int rows1, int columns1, int rows2, int columns2) {
    int i, j, k;
    
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (k = 0; k < columns1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int mat[][100], int rows, int columns) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[100][100], b[100][100], result[100][100];
    int rows1, columns1, rows2, columns2;
    int i, j;
    
    printf("Enter dimensions of matrix A (rows columns): ");
    scanf("%d %d", &rows1, &columns1);
    
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < columns1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter dimensions of matrix B (rows columns): ");
    scanf("%d %d", &rows2, &columns2);
    
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < columns2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    
    // addition
    if (rows1 == rows2 && columns1 == columns2) {
        printf("Addition of matrices A and B:\n");
        addMatrices(a, b, result, rows1, columns1);
        printMatrix(result, rows1, columns1);
    } else {
        printf("Matrices cannot be added \n");
    }
    
    // subtraction
    if (rows1 == rows2 && columns1 == columns2) {
        printf("Subtraction of matrices B from A:\n");
        subtractMatrices(a, b, result, rows1, columns1);
        printMatrix(result, rows1, columns1);
    } else {
        printf("Matrices cannot be subtracted \n");
    }
    
    // multiplication
    if (columns1 == rows2) {
        printf("Multiplication of matrices A and B:\n");
        multiplyMatrices(a, b, result, rows1, columns1, rows2, columns2);
        printMatrix(result, rows1, columns2);
    } else {
        printf("Matrices cannot be multiplied \n");
    }
    
    return 0;
}