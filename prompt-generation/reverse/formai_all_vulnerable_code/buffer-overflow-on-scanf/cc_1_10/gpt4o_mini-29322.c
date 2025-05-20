//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsFirst, int colsFirst, int rowsSecond, int colsSecond);

int main() {
    int firstMatrix[MAX_SIZE][MAX_SIZE], secondMatrix[MAX_SIZE][MAX_SIZE], resultMatrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    printf("Welcome to the Happy Matrix Operations Program! 🌟\n");
    printf("Let's do some joyful math with matrices!\n");

    // Input dimensions
    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    // Input first matrix
    printf("🎉 Now, let's input the first matrix (%d x %d) 🎊\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    // Input second matrix
    printf("⭐ Time to input the second matrix (%d x %d) ⭐\n", rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    // Add matrices
    printf("\n✨ Let's add the matrices! ✨\n");
    addMatrices(firstMatrix, secondMatrix, resultMatrix, rows, cols);
    printf("The result of addition is:\n");
    printMatrix(resultMatrix, rows, cols);

    // Subtract matrices
    printf("\n💖 Now, let's subtract the matrices! 💖\n");
    subtractMatrices(firstMatrix, secondMatrix, resultMatrix, rows, cols);
    printf("The result of subtraction is:\n");
    printMatrix(resultMatrix, rows, cols);

    // Multiply matrices
    printf("\n🎉 Now, let's do multiplication! 🎉\n");
    // Note: For multiplication, cols of first must equal rows of second
    printf("Enter the number of columns for the second matrix for multiplication: ");
    int colsSecond;
    scanf("%d", &colsSecond);

    if (cols != colsSecond) {
        printf("Oh no! The number of columns of the first matrix must equal the number of rows of the second! 🎈\n");
        return 1;
    }

    printf("🔔 Please input the second matrix (%d x %d) for multiplication 🔔\n", cols, colsSecond);
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < colsSecond; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, rows, cols, cols, colsSecond);
    printf("The result of multiplication is:\n");
    printMatrix(resultMatrix, rows, colsSecond);

    printf("\n🎊 Thank you for playing with matrices! Have a great day! 🎊\n");
    return 0;
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void subtractMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
}

void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsFirst, int colsFirst, int rowsSecond, int colsSecond) {
    for(int i = 0; i < rowsFirst; i++) {
        for(int j = 0; j < colsSecond; j++) {
            result[i][j] = 0; // Initialize to 0
            for(int k = 0; k < colsFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}