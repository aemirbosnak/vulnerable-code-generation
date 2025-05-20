//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS], i, j, k;
    char operation;

    // Initialize matrices with random values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    // Ask user for operation
    printf("Enter operation (+, -, *, /): ");
    scanf("%c", &operation);

    // Perform matrix operation
    switch (operation) {
        case '+':
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            break;
        case '-':
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            break;
        case '*':
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    result[i][j] = matrix1[i][j] * matrix2[i][j];
                }
            }
            break;
        case '/':
            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    if (matrix2[i][j] == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    result[i][j] = matrix1[i][j] / matrix2[i][j];
                }
            }
            break;
        default:
            printf("Invalid operation.\n");
            exit(1);
    }

    // Print result matrix
    printf("\nResult:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}