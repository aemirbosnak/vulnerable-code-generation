//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>

#define MAX 10 // Maximum size for the matrices

// Function prototypes 
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB);

int main() {
    int rowsA, colsA, rowsB, colsB;
    int a[MAX][MAX], b[MAX][MAX];
    int resultAdd[MAX][MAX], resultSub[MAX][MAX], resultMul[MAX][MAX];

    printf("🌟 Welcome to the Matrix Operations Celebration! 🌟\n");

    // Input for first matrix
    printf("Enter number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("🎉 Let's fill Matrix A with happy numbers! 🎉\n");
    inputMatrix(a, rowsA, colsA);
    
    // Input for second matrix
    printf("Enter number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);
    printf("🎈 It's time to fill Matrix B with joyful digits! 🎈\n");
    inputMatrix(b, rowsB, colsB);

    // Check if we can add or subtract matrices
    if (rowsA == rowsB && colsA == colsB) {
        // Perform and print addition
        printf("✨ Adding Matrix A and Matrix B! ✨\n");
        addMatrices(a, b, resultAdd, rowsA, colsA);
        printf("Result of A + B:\n");
        printMatrix(resultAdd, rowsA, colsA);
        
        // Perform and print subtraction
        printf("✨ Subtracting Matrix B from Matrix A! ✨\n");
        subtractMatrices(a, b, resultSub, rowsA, colsA);
        printf("Result of A - B:\n");
        printMatrix(resultSub, rowsA, colsA);
    } else {
        printf("🚫 Oops! Cannot add or subtract matrices with different dimensions!\n");
    }    

    // Check if we can multiply matrices
    if (colsA == rowsB) {
        // Perform and print multiplication
        printf("✨ Multiplying Matrix A and Matrix B! ✨\n");
        multiplyMatrices(a, b, resultMul, rowsA, colsA, colsB);
        printf("Result of A * B:\n");
        printMatrix(resultMul, rowsA, colsB);
    } else {
        printf("🚫 Oops! Cannot multiply matrices where A's columns do not match B's rows!\n");
    }

    printf("🎉 Thank you for playing with matrices! Have a dazzling day! 🎊\n");
    return 0;
}

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize the result
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}