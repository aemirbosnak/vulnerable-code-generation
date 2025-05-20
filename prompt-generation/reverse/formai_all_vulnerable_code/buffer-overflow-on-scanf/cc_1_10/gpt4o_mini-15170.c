//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void displayMenu();
void createMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    int choice;

    printf("Welcome to the Mysterious Matrix Land!\n");
    printf("Here, we shall do algebraic wizardry!\n\n");

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createMatrix(matrix1, &rows1, &cols1);
                displayMatrix(matrix1, rows1, cols1);
                break;
            case 2:
                createMatrix(matrix2, &rows2, &cols2);
                displayMatrix(matrix2, rows2, cols2);
                break;
            case 3:
                if (rows1 == rows2 && cols1 == cols2) {
                    addMatrices(matrix1, matrix2, result, rows1, cols1);
                    printf("Sum of the matrices is:\n");
                    displayMatrix(result, rows1, cols1);
                } else {
                    printf("Alas! Matrices dimensions do not match for addition.\n");
                }
                break;
            case 4:
                if (rows1 == rows2 && cols1 == cols2) {
                    subtractMatrices(matrix1, matrix2, result, rows1, cols1);
                    printf("Difference of the matrices is:\n");
                    displayMatrix(result, rows1, cols1);
                } else {
                    printf("Alas! Matrices dimensions do not match for subtraction.\n");
                }
                break;
            case 5:
                if (cols1 == rows2) {
                    multiplyMatrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
                    printf("Product of the matrices is:\n");
                    displayMatrix(result, rows1, cols2);
                } else {
                    printf("Alas! Cannot multiply these matrices due to dimensional mismatch.\n");
                }
                break;
            case 6:
                printf("Exiting the magical realm of matrices. Farewell!\n");
                exit(0);
            default:
                printf("Hmm! That doesn't seem like a valid choice.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Matrix Operations Menu ---\n");
    printf("1. Create Matrix 1\n");
    printf("2. Create Matrix 2\n");
    printf("3. Add Matrices\n");
    printf("4. Subtract Matrices\n");
    printf("5. Multiply Matrices\n");
    printf("6. Exit\n");
}

void createMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", rows);
    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", cols);
    
    printf("Now, fill out the matrix:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Here's the matrix you conjured:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}