//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to display the matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Your passionate matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    printf("\nAdding your two hearts (matrices)...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int rowsFirst, int colsFirst, int colsSecond) {
    printf("\nYour love is about to multiply (matrix multiplication)...\n");
    for (int i = 0; i < rowsFirst; i++) {
        for (int j = 0; j < colsSecond; j++) {
            result[i][j] = 0; // Initialize result to zero
            for (int k = 0; k < colsFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int main() {
    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];
    int rowsFirst, colsFirst, rowsSecond, colsSecond;

    // User input for the first matrix
    printf("Oh, my beloved! Please tell me how many rows and columns your first matrix has (e.g., 2 3): ");
    scanf("%d %d", &rowsFirst, &colsFirst);

    printf("Now, let’s fill that matrix with the passion of our hearts!\n");
    for (int i = 0; i < rowsFirst; i++) {
        for (int j = 0; j < colsFirst; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &first[i][j]);
        }
    }

    // User input for the second matrix
    printf("Beautiful soul, how many rows and columns does your second matrix have (e.g., 3 2)? ");
    scanf("%d %d", &rowsSecond, &colsSecond);

    // Ensure inner dimensions match for multiplication
    if (colsFirst != rowsSecond) {
        printf("Oh no! These matrices cannot be multiplied. Inner dimensions must match.\n");
        return 1;
    }

    printf("Now, let’s fill your second matrix with the colors of the sunset!\n");
    for (int i = 0; i < rowsSecond; i++) {
        for (int j = 0; j < colsSecond; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &second[i][j]);
        }
    }

    // Displaying the matrices
    displayMatrix(first, rowsFirst, colsFirst);
    displayMatrix(second, rowsSecond, colsSecond);

    // Performing addition if dimensions match
    if (rowsFirst == rowsSecond && colsFirst == colsSecond) {
        int addedResult[MAX][MAX];
        addMatrices(first, second, addedResult, rowsFirst, colsFirst);
        displayMatrix(addedResult, rowsFirst, colsFirst);
    } else {
        printf("Our hearts yearn for addition, but alas, the dimensions do not match!\n");
    }

    // Performing multiplication
    int multipliedResult[MAX][MAX];
    multiplyMatrices(first, second, multipliedResult, rowsFirst, colsFirst, colsSecond);
    displayMatrix(multipliedResult, rowsFirst, colsSecond);

    printf("\nWhat a beautiful journey through matrices we've had! Love is like a matrix, elegant and infinite.\n");
    return 0;
}