//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

// Function prototypes
void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);

// Welcome to the Matrix Funhouse!
void welcomeMessage() {
    printf("Welcome to the Matrix Funhouse!\n");
    printf("Where we manipulate numbers in mystical grids!\n");
    printf("Buckle up, it’s going to be a matrix-tastic ride!\n\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    welcomeMessage();

    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    printf("Enter the number of rows and columns for the matrices (max %d): ", MAX_SIZE);
    scanf("%d %d", &rows, &cols);
    
    if (rows > MAX_SIZE || cols > MAX_SIZE) {
        printf("Whoa there! That's too big for our matrix-bus! Try a size below %d.\n", MAX_SIZE);
        return 1;
    }

    // Filling matrices with random values and printing them
    printf("\nFilling Matrix 1 with random numbers...\n");
    fillMatrix(matrix1, rows, cols);
    printMatrix(matrix1, rows, cols);

    printf("\nFilling Matrix 2 with random numbers...\n");
    fillMatrix(matrix2, rows, cols);
    printMatrix(matrix2, rows, cols);

    // Adding the two matrices
    printf("\nLet's add these two magnificent matrices together, shall we?\n");
    addMatrices(matrix1, matrix2, result, rows, cols);
    printf("Here’s the result of the addition:\n");
    printMatrix(result, rows, cols);

    // Multiplying the matrices (for multiplication, columns of matrix1 must equal rows of matrix2)
    printf("\nNow, let's try and multiply these two adventurous matrices!\n");
    
    if (rows == cols) { // For simplicity, we’ll restrict it to square matrices
        multiplyMatrices(matrix1, matrix2, result, rows, cols, cols, rows);
        printf("Behold! The result of multiplication is:\n");
        printMatrix(result, rows, rows);
    } else {
        printf("Uh-oh! These matrices cannot be multiplied. Their dimensions just don’t vibe together!\n");
    }

    printf("Thanks for visiting the Matrix Funhouse! Remember, keep those matrices divide and conquering till next time!\n");
    return 0;
}

void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Fill with random numbers from 0 to 9
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize the product cell
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}