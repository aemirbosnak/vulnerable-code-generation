//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3 // Let's work with 3x3 matrices for simplicity!

// Function prototypes
void readMatrix(int matrix[SIZE][SIZE], int num);
void printMatrix(int matrix[SIZE][SIZE]);
void addMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]);
void subtractMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);

int main() {
    int matrixA[SIZE][SIZE], matrixB[SIZE][SIZE];
    int result[SIZE][SIZE];
    
    printf("🎉 Welcome to the Fun Matrix Operations Program! 🎉\n\n");

    printf("Let's fill the first matrix (Matrix A).\n");
    readMatrix(matrixA, 1);
    
    printf("\nNow, let’s fill the second matrix (Matrix B).\n");
    readMatrix(matrixB, 2);
    
    printf("\nHere are the matrices you entered:\n");
    printf("Matrix A:\n");
    printMatrix(matrixA);
    printf("Matrix B:\n");
    printMatrix(matrixB);

    printf("\n✨ Let's add these two matrices! ✨\n");
    addMatrices(matrixA, matrixB, result);
    printf("Result of A + B:\n");
    printMatrix(result);
    
    printf("\n✨ Now, let's subtract Matrix B from Matrix A! ✨\n");
    subtractMatrices(matrixA, matrixB, result);
    printf("Result of A - B:\n");
    printMatrix(result);
    
    printf("\n✨ Buckle up! We're multiplying these matrices! ✨\n");
    multiplyMatrices(matrixA, matrixB, result);
    printf("Result of A * B:\n");
    printMatrix(result);
    
    printf("\n✨ Let’s transpose Matrix A and see the magic! ✨\n");
    transposeMatrix(matrixA, result);
    printf("Transpose of Matrix A:\n");
    printMatrix(result);
    
    printf("\n👐 And that’s a wrap! Thanks for playing with matrices! 👐\n");
    return 0;
}

void readMatrix(int matrix[SIZE][SIZE], int num) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Enter element [%d][%d] for Matrix %d: ", i + 1, j + 1, num);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0; // Initialize the result cell to 0
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}