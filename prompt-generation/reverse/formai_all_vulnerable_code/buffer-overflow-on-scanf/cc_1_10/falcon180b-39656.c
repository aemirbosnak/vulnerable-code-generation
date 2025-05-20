//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NUMBERS 100

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int generateRandomMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandomNumber(1, 100);
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int newMatrix[MAX_COLS][MAX_ROWS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }
}

int main() {
    srand(time(NULL));

    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid input.\n");
        return 1;
    }

    int matrix[MAX_ROWS][MAX_COLS];
    generateRandomMatrix(matrix, rows, cols);

    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);

    transposeMatrix(matrix, rows, cols);

    printf("\nTransposed Matrix:\n");
    printMatrix(matrix, cols, rows);

    return 0;
}