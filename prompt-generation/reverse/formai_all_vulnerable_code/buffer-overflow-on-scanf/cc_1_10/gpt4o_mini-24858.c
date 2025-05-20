//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Resulting Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int rows1, int cols1, int rows2, int cols2, int mat1[rows1][cols1], int mat2[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize to zero
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows, cols, choice;
    
    printf("Welcome to the Matrix Operation Wizard!\n");
    printf("Let's do some amazing things with matrices!\n");
    printf("Enter the number of rows and columns for your square matrices (e.g., 3 3 for 3x3): ");
    scanf("%d %d", &rows, &cols);
    
    int mat1[rows][cols], mat2[rows][cols], result[rows][cols];
    
    printf("Input elements for the first matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Input elements for the second matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("Choose an operation:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMatrices(rows, cols, mat1, mat2, result);
            printf("Here's the addition result:\n");
            printMatrix(rows, cols, result);
            break;
        case 2:
            subtractMatrices(rows, cols, mat1, mat2, result);
            printf("Here's the subtraction result:\n");
            printMatrix(rows, cols, result);
            break;
        case 3:
            if (rows != cols) {
                printf("Matrix multiplication requires columns of the first matrix to be equal to the rows of the second. Please restart with valid matrices.\n");
                return 1;
            }
            multiplyMatrices(rows, cols, cols, rows, mat1, mat2, result);
            printf("Here's the multiplication result:\n");
            printMatrix(rows, rows, result);
            break;
        default:
            printf("Invalid choice! Please restart the program and select a valid operation.\n");
            break;
    }
    
    printf("Thank you for using the Matrix Operation Wizard! Have a great day!\n");
    return 0;
}