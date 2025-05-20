//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col);
void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col);
void subtractMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col);
void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row1, int col1, int col2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col);

int main() {
    int first[MAX_SIZE][MAX_SIZE], second[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int row1, col1, row2, col2;
    int choice;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    if (row1 <= 0 || col1 <= 0 || row2 <= 0 || col2 <= 0 || row1 > MAX_SIZE || col1 > MAX_SIZE || row2 > MAX_SIZE || col2 > MAX_SIZE) {
        printf("Matrix size must be between 1 and %d\n", MAX_SIZE);
        return 1;
    }

    printf("Enter elements of the first matrix:\n");
    inputMatrix(first, row1, col1);
    printf("Enter elements of the second matrix:\n");
    inputMatrix(second, row2, col2);

    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose First Matrix\n");
        printf("5. Transpose Second Matrix\n");
        printf("0. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (row1 == row2 && col1 == col2) {
                    addMatrices(first, second, result, row1, col1);
                    printf("Result of Addition:\n");
                    printMatrix(result, row1, col1);
                } else {
                    printf("Matrix dimensions must match for addition!\n");
                }
                break;
            case 2:
                if (row1 == row2 && col1 == col2) {
                    subtractMatrices(first, second, result, row1, col1);
                    printf("Result of Subtraction:\n");
                    printMatrix(result, row1, col1);
                } else {
                    printf("Matrix dimensions must match for subtraction!\n");
                }
                break;
            case 3:
                if (col1 == row2) {
                    multiplyMatrices(first, second, result, row1, col1, col2);
                    printf("Result of Multiplication:\n");
                    printMatrix(result, row1, col2);
                } else {
                    printf("Number of columns of the first matrix must match number of rows of the second matrix for multiplication!\n");
                }
                break;
            case 4:
                transposeMatrix(first, result, row1, col1);
                printf("Transpose of First Matrix:\n");
                printMatrix(result, col1, row1);
                break;
            case 5:
                transposeMatrix(second, result, row2, col2);
                printf("Transpose of Second Matrix:\n");
                printMatrix(result, col2, row2);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void subtractMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
}

void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}