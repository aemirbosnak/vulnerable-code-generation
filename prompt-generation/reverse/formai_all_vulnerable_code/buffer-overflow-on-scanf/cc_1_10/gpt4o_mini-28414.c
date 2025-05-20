//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int choice;
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Matrix Operations Program\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Subtraction\n");
    printf("3. Matrix Multiplication\n");
    printf("4. Matrix Transposition\n");
    printf("5. Exit\n");

    do {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of rows and columns for first matrix: ");
                scanf("%d%d", &rows1, &cols1);
                printf("Enter number of rows and columns for second matrix: ");
                scanf("%d%d", &rows2, &cols2);

                if (rows1 == rows2 && cols1 == cols2) {
                    printf("Enter elements of first matrix:\n");
                    inputMatrix(mat1, rows1, cols1);
                    printf("Enter elements of second matrix:\n");
                    inputMatrix(mat2, rows2, cols2);
                    addMatrices(mat1, mat2, result, rows1, cols1);
                    printf("Result of Addition:\n");
                    displayMatrix(result, rows1, cols1);
                } else {
                    printf("Error: Matrices dimensions do not match for addition.\n");
                }
                break;

            case 2:
                printf("Enter number of rows and columns for first matrix: ");
                scanf("%d%d", &rows1, &cols1);
                printf("Enter number of rows and columns for second matrix: ");
                scanf("%d%d", &rows2, &cols2);

                if (rows1 == rows2 && cols1 == cols2) {
                    printf("Enter elements of first matrix:\n");
                    inputMatrix(mat1, rows1, cols1);
                    printf("Enter elements of second matrix:\n");
                    inputMatrix(mat2, rows2, cols2);
                    subtractMatrices(mat1, mat2, result, rows1, cols1);
                    printf("Result of Subtraction:\n");
                    displayMatrix(result, rows1, cols1);
                } else {
                    printf("Error: Matrices dimensions do not match for subtraction.\n");
                }
                break;

            case 3:
                printf("Enter rows and columns for first matrix: ");
                scanf("%d%d", &rows1, &cols1);
                printf("Enter rows and columns for second matrix (make sure columns of first matches rows of second): ");
                scanf("%d%d", &rows2, &cols2);

                if (cols1 == rows2) {
                    printf("Enter elements of first matrix:\n");
                    inputMatrix(mat1, rows1, cols1);
                    printf("Enter elements of second matrix:\n");
                    inputMatrix(mat2, rows2, cols2);
                    multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);
                    printf("Result of Multiplication:\n");
                    displayMatrix(result, rows1, cols2);
                } else {
                    printf("Error: Number of columns in first matrix must equal number of rows in second matrix for multiplication.\n");
                }
                break;

            case 4:
                printf("Enter number of rows and columns for matrix: ");
                scanf("%d%d", &rows1, &cols1);
                printf("Enter elements of matrix:\n");
                inputMatrix(mat1, rows1, cols1);
                transposeMatrix(mat1, result, rows1, cols1);
                printf("Result of Transposition:\n");
                displayMatrix(result, cols1, rows1);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
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

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize cell to 0
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}