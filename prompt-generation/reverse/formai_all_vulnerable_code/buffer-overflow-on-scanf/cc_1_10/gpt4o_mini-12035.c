//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Here is your matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\nAdding matrices...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\nSubtracting matrices...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    printf("\nMultiplying matrices...\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize to 0
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    printf("Welcome to the Matrix Operations Program!\n");
    printf("Let's define the size of the matrices (maximum size is %d x %d):\n", MAX_SIZE, MAX_SIZE);
    printf("Enter number of rows (1 to 10): ");
    scanf("%d", &rows);
    
    printf("Enter number of columns (1 to 10): ");
    scanf("%d", &cols);

    if (rows > MAX_SIZE || cols > MAX_SIZE || rows < 1 || cols < 1) {
        printf("Invalid matrix size! Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Get first matrix input
    inputMatrix(matrix1, rows, cols);
    printMatrix(matrix1, rows, cols);

    // Get second matrix input
    inputMatrix(matrix2, rows, cols);
    printMatrix(matrix2, rows, cols);

    // Add matrices
    addMatrices(matrix1, matrix2, result, rows, cols);
    printMatrix(result, rows, cols);

    // Subtract matrices
    subtractMatrices(matrix1, matrix2, result, rows, cols);
    printMatrix(result, rows, cols);

    // Prepare for multiplication
    printf("For multiplication, enter the number of columns for the second matrix: ");
    int colsB;
    scanf("%d", &colsB);

    if (colsB > MAX_SIZE || colsB < 1) {
        printf("Invalid number of columns! Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Get second matrix with possibly different columns for multiplication
    int matrix2b[MAX_SIZE][MAX_SIZE];
    printf("Now, let's enter the second matrix (%dx%d):\n", cols, colsB);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2b[i][j]);
        }
    }

    // Matrix multiplication requires matrix1.cols == matrix2.rows
    multiplyMatrices(matrix1, matrix2b, result, rows, cols, colsB);
    printMatrix(result, rows, colsB);

    printf("All operations completed! Matrix magic accomplished!\n");

    return 0;
}