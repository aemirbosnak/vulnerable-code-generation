//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2);

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    int choice;

    printf("Enter dimensions of first matrix (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter dimensions of second matrix (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);
  
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible with these dimensions.\n");
        return 1;
    }

    printf("\nEnter elements of first matrix:\n");
    inputMatrix(mat1, rows1, cols1);
    printf("Matrix A:\n");
    displayMatrix(mat1, rows1, cols1);

    printf("\nEnter elements of second matrix:\n");
    inputMatrix(mat2, rows2, cols2);
    printf("Matrix B:\n");
    displayMatrix(mat2, rows2, cols2);

    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Exit\n");
        printf("Choose an operation (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rows1 == rows2 && cols1 == cols2) {
                    addMatrices(mat1, mat2, result, rows1, cols1);
                    printf("\nResult of Addition:\n");
                    displayMatrix(result, rows1, cols1);
                } else {
                    printf("Matrices must have the same dimensions for addition.\n");
                }
                break;
            case 2:
                if (rows1 == rows2 && cols1 == cols2) {
                    subtractMatrices(mat1, mat2, result, rows1, cols1);
                    printf("\nResult of Subtraction:\n");
                    displayMatrix(result, rows1, cols1);
                } else {
                    printf("Matrices must have the same dimensions for subtraction.\n");
                }
                break;
            case 3:
                multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);
                printf("\nResult of Multiplication:\n");
                displayMatrix(result, rows1, cols2);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize each element to 0
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}