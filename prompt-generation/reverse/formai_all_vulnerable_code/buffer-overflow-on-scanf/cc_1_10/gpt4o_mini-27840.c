//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>

// Function prototypes
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]);
void multiplyMatrices(int r1, int c1, int r2, int c2, int mat1[r1][c1], int mat2[r2][c2], int result[r1][c2]);

int main() {
    int rows, cols;
    
    // Welcome Message
    printf("🎉 Welcome to the Matrix Magic World! 🎉\n");
    printf("Let's create and play with some matrices!\n");

    // User input for the matrices' dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int mat1[rows][cols], mat2[rows][cols], sum[rows][cols], product[rows][cols];

    // Filling the first matrix
    printf("\n🎈 Let's fill the first matrix! 🎈\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }
    
    // Filling the second matrix
    printf("\n🎈 Let's fill the second matrix! 🎈\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }

    // Adding matrices
    addMatrices(rows, cols, mat1, mat2, sum);
    printf("\n✨ Here is the sum of the two matrices: ✨\n");
    printMatrix(rows, cols, sum);

    // Multiplying matrices (for this example, ensure that cols in first matrix == rows in second matrix)
    // We will implement multiplication based on columns and rows defined earlier
    if (cols == rows) {
        multiplyMatrices(rows, cols, rows, cols, mat1, mat2, product);
        printf("\n✨ Here is the product of the two matrices! ✨\n");
        printMatrix(rows, cols, product);
    } else {
        printf("\n😢 Can't multiply these matrices because the number of columns in the first is not equal to the number of rows in the second! 😢\n");
    }

    printf("\n🎊 Thanks for playing with matrices! 🎊\n");
    return 0;
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int r1, int c1, int r2, int c2, int mat1[r1][c1], int mat2[r2][c2], int result[r1][c2]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize the result matrix element
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}