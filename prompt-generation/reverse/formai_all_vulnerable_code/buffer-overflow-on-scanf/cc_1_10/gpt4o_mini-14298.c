//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void initializeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE],
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE],
                     int rows, int cols);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    // Input for first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    initializeMatrix(matrix1, rows1, cols1);
    
    // Input for second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    initializeMatrix(matrix2, rows2, cols2);
    
    // Matrix Addition
    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(matrix1, matrix2, result, rows1, cols1);
        printf("Result of Addition:\n");
        printMatrix(result, rows1, cols1);
    } else {
        printf("Matrices cannot be added due to differing dimensions.\n");
    }

    // Matrix Multiplication
    if (cols1 == rows2) {
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
        printf("Result of Multiplication:\n");
        printMatrix(result, rows1, cols2);
    } else {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
    }

    // Transposing the first matrix
    transposeMatrix(matrix1, transposed, rows1, cols1);
    printf("Transpose of the first matrix:\n");
    printMatrix(transposed, cols1, rows1);

    // Transposing the second matrix
    transposeMatrix(matrix2, transposed, rows2, cols2);
    printf("Transpose of the second matrix:\n");
    printMatrix(transposed, cols2, rows2);

    return 0;
}

void initializeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d): \n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE],
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < cols1; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE],
                     int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transposed[j][i] = matrix[i][j];
}