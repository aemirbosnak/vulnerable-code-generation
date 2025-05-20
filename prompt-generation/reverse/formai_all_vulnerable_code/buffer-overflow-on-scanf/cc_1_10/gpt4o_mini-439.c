//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col);
void subtractMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col);
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row1, int col1, int row2, int col2, int r, int c);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col);
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col);

// Main function
int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int choice, row1, col1, row2, col2;

    printf("Enter rows and columns for Matrix 1: ");
    scanf("%d %d", &row1, &col1);
    inputMatrix(matrix1, row1, col1);

    printf("Enter rows and columns for Matrix 2: ");
    scanf("%d %d", &row2, &col2);
    inputMatrix(matrix2, row2, col2);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Display Matrices\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (row1 == row2 && col1 == col2) {
                    addMatrices(matrix1, matrix2, result, 0, 0);
                    printf("Result of Addition:\n");
                    displayMatrix(result, row1, col1);
                } else {
                    printf("Matrices cannot be added due to size mismatch.\n");
                }
                break;

            case 2:
                if (row1 == row2 && col1 == col2) {
                    subtractMatrices(matrix1, matrix2, result, 0, 0);
                    printf("Result of Subtraction:\n");
                    displayMatrix(result, row1, col1);
                } else {
                    printf("Matrices cannot be subtracted due to size mismatch.\n");
                }
                break;

            case 3:
                if (col1 == row2) {
                    multiplyMatrices(matrix1, matrix2, result, row1, col1, row2, col2, 0, 0);
                    printf("Result of Multiplication:\n");
                    displayMatrix(result, row1, col2);
                } else {
                    printf("Matrices cannot be multiplied due to size mismatch.\n");
                }
                break;

            case 4:
                printf("Matrix 1:\n");
                displayMatrix(matrix1, row1, col1);
                printf("Matrix 2:\n");
                displayMatrix(matrix2, row2, col2);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

// Recursive function to add two matrices
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col) {
    if (row >= MAX_SIZE) return;
    if (col >= MAX_SIZE) { // Move to the next row
        addMatrices(matrix1, matrix2, result, row + 1, 0);
        return;
    }
    result[row][col] = matrix1[row][col] + matrix2[row][col];
    addMatrices(matrix1, matrix2, result, row, col + 1); // Continue to next column
}

// Recursive function to subtract two matrices
void subtractMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col) {
    if (row >= MAX_SIZE) return;
    if (col >= MAX_SIZE) { // Move to the next row
        subtractMatrices(matrix1, matrix2, result, row + 1, 0);
        return;
    }
    result[row][col] = matrix1[row][col] - matrix2[row][col];
    subtractMatrices(matrix1, matrix2, result, row, col + 1); // Continue to next column
}

// Recursive function to multiply two matrices
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row1, int col1, int row2, int col2, int r, int c) {
    if (r >= row1) return; // Stop condition for rows
    if (c >= col2) { // If all columns are processed, move to the next row
        multiplyMatrices(matrix1, matrix2, result, row1, col1, row2, col2, r + 1, 0);
        return;
    }
    result[r][c] = 0;
    
    for (int k = 0; k < col1; k++) {
        result[r][c] += matrix1[r][k] * matrix2[k][c];
    }
    multiplyMatrices(matrix1, matrix2, result, row1, col1, row2, col2, r, c + 1); // Continue to next column
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to input a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);
}