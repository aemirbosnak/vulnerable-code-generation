//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols);

int main() {
    int choice, A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Matrix Operations Menu\n");
    printf("=======================\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    printf("4. Transpose a Matrix\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);
                
                if (r1 != r2 || c1 != c2) {
                    printf("Matrices should have the same dimensions for addition!\n");
                    break;
                }

                printf("Input elements of Matrix A:\n");
                inputMatrix(A, r1, c1);
                printf("Input elements of Matrix B:\n");
                inputMatrix(B, r2, c2);
                
                addMatrices(A, B, C, r1, c1);
                printf("Result of A + B:\n");
                displayMatrix(C, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);
                
                if (r1 != r2 || c1 != c2) {
                    printf("Matrices should have the same dimensions for subtraction!\n");
                    break;
                }

                printf("Input elements of Matrix A:\n");
                inputMatrix(A, r1, c1);
                printf("Input elements of Matrix B:\n");
                inputMatrix(B, r2, c2);
                
                subtractMatrices(A, B, C, r1, c1);
                printf("Result of A - B:\n");
                displayMatrix(C, r1, c1);
                break;

            case 3:
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);
                
                if (c1 != r2) {
                    printf("Number of columns of A must equal number of rows of B for multiplication!\n");
                    break;
                }

                printf("Input elements of Matrix A:\n");
                inputMatrix(A, r1, c1);
                printf("Input elements of Matrix B:\n");
                inputMatrix(B, r2, c2);
                
                multiplyMatrices(A, B, C, r1, c1, c2);
                printf("Result of A * B:\n");
                displayMatrix(C, r1, c2);
                break;

            case 4:
                printf("Enter rows and columns for the Matrix: ");
                scanf("%d %d", &r1, &c1);
                
                printf("Input elements of the Matrix:\n");
                inputMatrix(A, r1, c1);
                
                transposeMatrix(A, C, r1, c1);
                printf("Transposed Matrix:\n");
                displayMatrix(C, c1, r1);
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose between 1-5.\n");
        }
    }
    return 0;
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}