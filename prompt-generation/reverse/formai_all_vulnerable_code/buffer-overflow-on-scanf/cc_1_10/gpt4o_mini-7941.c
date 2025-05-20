//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum size for our matrices

// Function to take matrix input from the user
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of a %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Here is your matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    printf("Adding the matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    printf("Subtracting the matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols1, int cols2) {
    printf("Multiplying the matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize result cell
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Main fun function
int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;

    printf("🎉 Welcome to the Matrix Magic Program! 🎉\n\n");

    // Get dimensions and input for first matrix
    printf("Please enter the number of rows and columns for the first matrix:\n");
    printf("Rows: ");
    scanf("%d", &rows1);
    printf("Columns: ");
    scanf("%d", &cols1);
    inputMatrix(mat1, rows1, cols1);
    displayMatrix(mat1, rows1, cols1);

    // Get dimensions and input for second matrix
    printf("\nNext, let's enter the dimensions for the second matrix:\n");
    printf("Rows: ");
    scanf("%d", &rows2);
    printf("Columns: ");
    scanf("%d", &cols2);
    
    if (rows1 != rows2 || cols1 != cols2) {
        printf("🎈 Hold on! Only matrices of the same dimensions can be added or subtracted!\n");
        return 0; // Exit for addition/subtraction
    }
    
    inputMatrix(mat2, rows2, cols2);
    displayMatrix(mat2, rows2, cols2);

    // Matrix addition
    addMatrices(mat1, mat2, result, rows1, cols1);
    printf("\nResult of Addition:\n");
    displayMatrix(result, rows1, cols1);

    // Matrix subtraction
    subtractMatrices(mat1, mat2, result, rows1, cols1);
    printf("\nResult of Subtraction:\n");
    displayMatrix(result, rows1, cols1);

    // Matrix multiplication only possible if cols1 == rows2
    if (cols1 != rows2) {
        printf("🏳️ Note: Multiplication cannot be performed as dimensions do not match!\n");
    } else {
        printf("\nPreparing for Multiplication! 🎩✨\n");
        multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
        printf("Result of Multiplication:\n");
        displayMatrix(result, rows1, cols2);
    }

    printf("\n🎉 Thank you for using Matrix Magic! Have a great day! 🎉\n");
    return 0;
}