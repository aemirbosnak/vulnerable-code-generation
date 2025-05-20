//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void inputMatrix(int matrix[][10], int rows, int cols);
void displayMatrix(int matrix[][10], int rows, int cols);
void addMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols);
void subtractMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols);
void multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int rowsMat1, int colsMat1, int colsMat2);
void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols);

int main() {
    int mat1[10][10], mat2[10][10], result[10][10];
    int rows1, cols1, rows2, cols2;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != cols2) {
        printf("Matrix addition and subtraction require equal dimensions!\n");
        return -1;
    }

    printf("Input elements for first matrix:\n");
    inputMatrix(mat1, rows1, cols1);
    
    printf("Input elements for second matrix:\n");
    inputMatrix(mat2, rows2, cols2);

    // Displaying the matrices
    printf("First Matrix:\n");
    displayMatrix(mat1, rows1, cols1);
    printf("Second Matrix:\n");
    displayMatrix(mat2, rows2, cols2);

    // Matrix Addition
    addMatrices(mat1, mat2, result, rows1, cols1);
    printf("Result of addition:\n");
    displayMatrix(result, rows1, cols1);

    // Matrix Subtraction
    subtractMatrices(mat1, mat2, result, rows1, cols1);
    printf("Result of subtraction:\n");
    displayMatrix(result, rows1, cols1);

    // Matrix Multiplication
    if (cols1 != rows2) {
        printf("Matrix multiplication requires that the number of columns of the first matrix be equal to the number of rows of the second matrix!\n");
        return -1;
    }

    multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
    printf("Result of multiplication:\n");
    displayMatrix(result, rows1, cols2);

    // Transposing the first matrix
    transposeMatrix(mat1, result, rows1, cols1);
    printf("Transpose of first matrix:\n");
    displayMatrix(result, cols1, rows1);

    return 0;
}

void inputMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int rowsMat1, int colsMat1, int colsMat2) {
    for (int i = 0; i < rowsMat1; i++) {
        for (int j = 0; j < colsMat2; j++) {
            result[i][j] = 0; // Initialize the element to 0
            for (int k = 0; k < colsMat1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}