//FormAI DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];

    // Initialize matrices with random numbers between 1 and 10
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix1[i][j] = rand() % 10 + 1;
            matrix2[i][j] = rand() % 10 + 1;
        }
    }

    printf("Matrix 1:\n");
    printMatrix(matrix1);

    printf("\nMatrix 2:\n");
    printMatrix(matrix2);

    int choice;
    printf("\nEnter 1 to add matrices, 2 to multiply matrices: ");
    scanf("%d", &choice);

    int result[ROWS][COLS];

    switch (choice) {
        case 1:
            addMatrices(matrix1, matrix2, result);
            printf("\nResultant matrix:\n");
            printMatrix(result);
            break;
        case 2:
            multiplyMatrices(matrix1, matrix2, result);
            printf("\nResultant matrix:\n");
            printMatrix(result);
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }

    return 0;
}