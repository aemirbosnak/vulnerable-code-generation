//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("🎩 Here’s the fabulous matrix for your viewing pleasure:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n✨ - - - - - - - - - - - - - - - - - - - - - - - - - - - -✨\n");
}

void fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("🪄 Filling the matrix with random numbers between 1 and 20...\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 20 + 1; // Random numbers from 1 to 20
        }
    }
}

void add_matrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], 
                  int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("🧮 Adding two fabulous matrices together...\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void transpose_matrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("🔄 Transposing this wild matrix game...\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void multiply_matrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], 
                       int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    printf("🎉 It’s multiplication time! Let’s mash these matrices.\n");
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for(int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], 
        addResult[MAX_SIZE][MAX_SIZE], mulResult[MAX_SIZE][MAX_SIZE], 
        transposed[MAX_SIZE][MAX_SIZE];

    printf("🔔 Welcome to the Matrix Extravaganza! 🎊\n");
    
    printf("✏️ Please enter the number of rows for Matrix A (max %d): ", MAX_SIZE);
    scanf("%d", &rowsA);
    printf("✏️ Please enter the number of columns for Matrix A (max %d): ", MAX_SIZE);
    scanf("%d", &colsA);

    fill_matrix(matrixA, rowsA, colsA);
    print_matrix(matrixA, rowsA, colsA);

    printf("✏️ Please enter the number of rows for Matrix B (should be the same as Matrix A's columns): ");
    rowsB = colsA; // ensuring the compatibility for multiplication
    printf("✏️ Please enter the number of columns for Matrix B (max %d): ", MAX_SIZE);
    scanf("%d", &colsB);

    fill_matrix(matrixB, rowsB, colsB);
    print_matrix(matrixB, rowsB, colsB);

    printf("🔥 Let’s add these wild numbers and see who comes out on top!\n");
    add_matrices(matrixA, matrixB, addResult, rowsA, colsA);
    print_matrix(addResult, rowsA, colsA);

    printf("💪 Time to transpose Matrix A, because it’s feeling a little unbalanced!\n");
    transpose_matrix(matrixA, transposed, rowsA, colsA);
    print_matrix(transposed, colsA, rowsA); // Note: rows and cols are swapped

    printf("⚔️ Now let’s multiply Matrix A and Matrix B, let’s see who can outgrow the other!\n");
    if (colsA == rowsB) {
        multiply_matrices(matrixA, matrixB, mulResult, rowsA, colsA, colsB);
        print_matrix(mulResult, rowsA, colsB);
    } else {
        printf("❌ You can't multiply those matrices! Make sure columns of A match rows of B.\n");
    }

    printf("🎊 Thanks for joining the Matrix Funhouse! See you next time! 🎉\n");

    return 0;
}