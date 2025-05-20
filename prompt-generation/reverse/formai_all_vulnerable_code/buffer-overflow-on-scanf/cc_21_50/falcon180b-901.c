//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS];
    int i, j, k;
    int option;
    srand(time(NULL));

    // Initialize matrices with random values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    // Print matrices
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

    // Ask user for operation
    printf("Enter operation (1 for addition, 2 for subtraction, 3 for multiplication): ");
    scanf("%d", &option);

    // Perform operation and print result
    switch (option) {
        case 1:
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            printf("Result:\n");
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            printf("Result:\n");
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    result[i][j] = matrix1[i][j] * matrix2[i][j];
                }
            }
            printf("Result:\n");
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}