//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2, choice;

    printf("Matrix Operations Program\n");
    printf("===========================\n");
    
    // Input first matrix
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    inputMatrix(mat1, rows1, cols1);
    displayMatrix(mat1, rows1, cols1);

    // Input second matrix
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    inputMatrix(mat2, rows2, cols2);
    displayMatrix(mat2, rows2, cols2);
    
    do {
        printf("\nChoose an operation:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose First Matrix\n");
        printf("5. Transpose Second Matrix\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rows1 != rows2 || cols1 != cols2) {
                    printf("Matrices must be of the same dimension to add!\n");
                } else {
                    addMatrices(mat1, mat2, result, rows1, cols1);
                    displayMatrix(result, rows1, cols1);
                }
                break;
                
            case 2:
                if (rows1 != rows2 || cols1 != cols2) {
                    printf("Matrices must be of the same dimension to subtract!\n");
                } else {
                    subtractMatrices(mat1, mat2, result, rows1, cols1);
                    displayMatrix(result, rows1, cols1);
                }
                break;
                
            case 3:
                if (cols1 != rows2) {
                    printf("Matrices cannot be multiplied! Columns of first must match rows of second.\n");
                } else {
                    multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
                    displayMatrix(result, rows1, cols2);
                }
                break;
                
            case 4:
                transposeMatrix(mat1, result, rows1, cols1);
                displayMatrix(result, cols1, rows1);
                break;
                
            case 5:
                transposeMatrix(mat2, result, rows2, cols2);
                displayMatrix(result, cols2, rows2);
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}