//FormAI DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>

/* Function to print a given matrix */
void printMatrix(int matrix[][10], int rows, int cols) {
    printf("Matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

/* Function to add two matrices */
void addMatrices(int matrix1[][10], int matrix2[][10], int rows, int cols) {
    int result[rows][cols];
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
    
    printf("\nAddition:\n");
    printMatrix(result, rows, cols);
}

/* Function to subtract two matrices */
void subMatrices(int matrix1[][10], int matrix2[][10], int rows, int cols) {
    int result[rows][cols];
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
    
    printf("\nSubtraction:\n");
    printMatrix(result, rows, cols);
}

/* Function to transpose a matrix */
void transposeMatrix(int matrix[][10], int rows, int cols) {
    int result[cols][rows];
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            result[j][i] = matrix[i][j];
    
    printf("\nTranspose:\n");
    printMatrix(result, cols, rows);
}

int main() {
    int matrix1[10][10], matrix2[10][10], rows, cols, option;

    printf("Enter the number of rows and columns of the matrices (max size of matrix should be 10x10):\n");
    scanf("%d%d", &rows, &cols);

    printf("Enter the elements of the first matrix:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &matrix1[i][j]);

    printf("\nEnter the elements of the second matrix:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &matrix2[i][j]);

    printf("\nChoose an operation:\n1. Add matrices\n2. Subtract matrices\n3. Transpose first matrix\n4. Transpose second matrix\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            addMatrices(matrix1, matrix2, rows, cols);
            break;
        case 2:
            subMatrices(matrix1, matrix2, rows, cols);
            break;
        case 3:
            transposeMatrix(matrix1, rows, cols);
            break;
        case 4:
            transposeMatrix(matrix2, rows, cols);
            break;
        default:
            printf("Invalid option\n");
    }
    
    return 0;
}