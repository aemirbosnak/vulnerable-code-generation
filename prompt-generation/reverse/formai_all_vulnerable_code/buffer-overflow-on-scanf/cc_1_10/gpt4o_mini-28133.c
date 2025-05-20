//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int first[rows][cols], int second[rows][cols], int result[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int first[rows][cols], int second[rows][cols], int result[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
}

void multiplyMatrices(int firstRows, int firstCols, int secondRows, int secondCols, int first[firstRows][firstCols], int second[secondRows][secondCols], int result[firstRows][secondCols]) {
    if(firstCols != secondRows) {
        printf("Matrix multiplication is not possible!\n");
        return;
    }
    for(int i = 0; i < firstRows; i++) {
        for(int j = 0; j < secondCols; j++) {
            result[i][j] = 0;
            for(int k = 0; k < firstCols; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transposed[cols][rows]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);
    
    int first[rows][cols], second[rows][cols], result[rows][cols], transposed[cols][rows];

    inputMatrix(rows, cols, first);
    inputMatrix(rows, cols, second);

    printf("\nFirst Matrix:\n");
    displayMatrix(rows, cols, first);

    printf("\nSecond Matrix:\n");
    displayMatrix(rows, cols, second);

    // Addition
    addMatrices(rows, cols, first, second, result);
    printf("\nSum of Matrices:\n");
    displayMatrix(rows, cols, result);

    // Subtraction
    subtractMatrices(rows, cols, first, second, result);
    printf("\nDifference of Matrices:\n");
    displayMatrix(rows, cols, result);
    
    // Multiplication
    int firstRows, firstCols, secondRows, secondCols;
    printf("Matrix Multiplication requires first matrix columns to be equal to second matrix rows.\n");
    printf("Enter dimensions for first matrix (rows and columns): ");
    scanf("%d %d", &firstRows, &firstCols);
    printf("Enter dimensions for second matrix (rows and columns): ");
    scanf("%d %d", &secondRows, &secondCols);
  
    int firstMatrix[firstRows][firstCols], secondMatrix[secondRows][secondCols], product[firstRows][secondCols];
  
    printf("Input First Matrix:\n");
    inputMatrix(firstRows, firstCols, firstMatrix);
    printf("Input Second Matrix:\n");
    inputMatrix(secondRows, secondCols, secondMatrix);
  
    multiplyMatrices(firstRows, firstCols, secondRows, secondCols, firstMatrix, secondMatrix, product);
    printf("\nProduct of Matrices:\n");
    displayMatrix(firstRows, secondCols, product);
  
    // Transpose of the first matrix
    transposeMatrix(rows, cols, first, transposed);
    printf("\nTranspose of First Matrix:\n");
    displayMatrix(cols, rows, transposed);

    return 0;
}