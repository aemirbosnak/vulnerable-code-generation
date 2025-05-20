//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS];
    int i, j, k, choice;

    // Initialize matrices with random values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    // Display matrices
    printf("Matrix 1:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix 2:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    // Perform matrix operation
    printf("Enter the operation you want to perform:\n1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Addition
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            break;
        case 2: // Subtraction
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            break;
        case 3: // Multiplication
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    result[i][j] = matrix1[i][j] * matrix2[i][j];
                }
            }
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    // Display result
    printf("Result:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}