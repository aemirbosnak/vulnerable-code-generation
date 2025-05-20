//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function prototypes
void printMenu();
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int r, int c);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int r, int c);
void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rA, int cA, int rB, int cB);
void transposeMatrix(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int r, int c);
void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int r, int c);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int r, int c);

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int rA, cA, rB, cB; // Rows and columns of matrices
    int choice;

    printf("Welcome to the Matrix Arithmetic Program!\n");

    // Input matrix A dimensions
    printf("Enter number of rows for Matrix A: ");
    scanf("%d", &rA);
    printf("Enter number of columns for Matrix A: ");
    scanf("%d", &cA);
    
    // Fill matrix A
    printf("Enter elements of Matrix A:\n");
    fillMatrix(A, rA, cA);
    
    // Input matrix B dimensions
    printf("Enter number of rows for Matrix B: ");
    scanf("%d", &rB);
    printf("Enter number of columns for Matrix B: ");
    scanf("%d", &cB);
    
    // Fill matrix B
    printf("Enter elements of Matrix B:\n");
    fillMatrix(B, rB, cB);
    
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (rA == rB && cA == cB) {
                    addMatrices(A, B, C, rA, cA);
                    printf("Result of Addition:\n");
                    printMatrix(C, rA, cA);
                } else {
                    printf("Matrices must have the same dimensions for addition.\n");
                }
                break;

            case 2:
                if (rA == rB && cA == cB) {
                    subtractMatrices(A, B, C, rA, cA);
                    printf("Result of Subtraction:\n");
                    printMatrix(C, rA, cA);
                } else {
                    printf("Matrices must have the same dimensions for subtraction.\n");
                }
                break;

            case 3:
                if (cA == rB) {
                    multiplyMatrices(A, B, C, rA, cA, rB, cB);
                    printf("Result of Multiplication:\n");
                    printMatrix(C, rA, cB);
                } else {
                    printf("Number of columns of Matrix A must match number of rows of Matrix B for multiplication.\n");
                }
                break;

            case 4:
                printf("Transpose of Matrix A:\n");
                transposeMatrix(A, C, rA, cA);
                printMatrix(C, cA, rA);
                break;

            case 5:
                printf("Transpose of Matrix B:\n");
                transposeMatrix(B, C, rB, cB);
                printMatrix(C, cB, rB);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void printMenu() {
    printf("\nMatrix Operations Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    printf("4. Transpose Matrix A\n");
    printf("5. Transpose Matrix B\n");
    printf("0. Exit\n");
}

void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rA, int cA, int rB, int cB) {
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            C[i][j] = 0; // Initialize to zero
            for (int k = 0; k < cA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            B[j][i] = A[i][j];
        }
    }
}