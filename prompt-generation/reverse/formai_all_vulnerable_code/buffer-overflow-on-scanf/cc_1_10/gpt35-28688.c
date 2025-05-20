//FormAI DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h> 
#include <stdlib.h>

// Function to print matrix
void printMatrix(int **matrix, int rows, int columns) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void addMatrix(int **matrix1, int **matrix2, int **result, int rows, int columns) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract matrices
void subtractMatrix(int **matrix1, int **matrix2, int **result, int rows, int columns) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply matrices
void multiplyMatrix(int **matrix1, int **matrix2, int **result, int rows, int columns1, int columns2) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns2; j++) {
            for (int k=0; k<columns1; k++) {
                result[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows, columns;
    
    printf("Enter the number of rows of matrix: ");
    scanf("%d", &rows);
    
    printf("Enter the number of columns of matrix: ");
    scanf("%d", &columns);
    
    // Dynamic memory allocation of matrices
    int **matrix1, **matrix2, **result;
    matrix1 = (int **)malloc(rows * sizeof(int *));
    matrix2 = (int **)malloc(rows * sizeof(int *));
    result = (int **)malloc(rows * sizeof(int *));
    for (int i=0; i<rows; i++) {
        matrix1[i] = (int *)malloc(columns * sizeof(int));
        matrix2[i] = (int *)malloc(columns * sizeof(int));
        result[i] = (int *)malloc(columns * sizeof(int));
    }
    
    // Input matrices
    printf("\nEnter the elements of first matrix:\n");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("\nEnter the elements of second matrix:\n");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    printf("\nFirst matrix:\n");
    printMatrix(matrix1, rows, columns);
    printf("\nSecond matrix:\n");
    printMatrix(matrix2, rows, columns);
    
    // Addition of matrices
    addMatrix(matrix1, matrix2, result, rows, columns);
    printf("\nAddition of matrices:\n");
    printMatrix(result, rows, columns);
    
    // Subtraction of matrices
    subtractMatrix(matrix1, matrix2, result, rows, columns);
    printf("\nSubtraction of matrices:\n");
    printMatrix(result, rows, columns);
    
    // Multiplication of matrices
    int columns2;
    printf("\nEnter the number of columns of second matrix for multiplication: ");
    scanf("%d", &columns2);
    multiplyMatrix(matrix1, matrix2, result, rows, columns, columns2);
    printf("\nMultiplication of matrices:\n");
    printMatrix(result, rows, columns2);
    
    // Free dynamically allocated memory
    for (int i=0; i<rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
    
    return 0;
}