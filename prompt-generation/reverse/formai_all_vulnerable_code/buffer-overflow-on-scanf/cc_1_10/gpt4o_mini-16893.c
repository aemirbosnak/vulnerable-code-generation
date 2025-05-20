//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

// Function prototypes
void printMatrix(int matrix[][100], int rows, int cols, int row, int col);
void initializeMatrix(int matrix[][100], int rows, int cols);
int sumMatrix(int matrix[][100], int rows, int cols, int row, int col);

// Main function
int main() {
    int rows, cols;
    printf("Enter number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows > 100 || cols > 100) {
        printf("Maximum size of matrix is 100x100\n");
        return 1;
    }

    int matrix[100][100];
    initializeMatrix(matrix, rows, cols);

    printf("Matrix:\n");
    printMatrix(matrix, rows, cols, 0, 0);

    int totalSum = sumMatrix(matrix, rows, cols, 0, 0);
    printf("Total Sum of Matrix Elements: %d\n", totalSum);

    return 0;
}

// Recursive function to print the matrix
void printMatrix(int matrix[][100], int rows, int cols, int row, int col) {
    if (row < rows) {
        if (col < cols) {
            printf("%d ", matrix[row][col]);
            printMatrix(matrix, rows, cols, row, col + 1);
        } else {
            printf("\n");
            printMatrix(matrix, rows, cols, row + 1, 0);
        }
    }
}

// Recursive function to initialize the matrix with user values
void initializeMatrix(int matrix[][100], int rows, int cols) {
    if (rows > 0) {
        if (cols > 0) {
            printf("Enter value for matrix[%d][%d]: ", (100 - rows), (100 - cols));
            scanf("%d", &matrix[100 - rows][100 - cols]);
            initializeMatrix(matrix, rows, cols - 1);
        } else {
            initializeMatrix(matrix, rows - 1, cols);  // Move to next row
        }
    }
}

// Recursive function to sum the elements of the matrix
int sumMatrix(int matrix[][100], int rows, int cols, int row, int col) {
    if (row >= rows) {
        return 0; // base case: no more rows to process
    } else {
        if (col < cols) {
            return matrix[row][col] + sumMatrix(matrix, rows, cols, row, col + 1); // Sum current row
        } else {
            return sumMatrix(matrix, rows, cols, row + 1, 0); // Move to next row
        }
    }
}