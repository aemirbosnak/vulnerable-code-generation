//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the Matrix Operations Program!\n");
    printf("Get ready to crunch some numbers!\n\n");

    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows, columns;

    printf("Enter the number of rows in the matrices: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrices: ");
    scanf("%d", &columns);

    // Input matrix 1
    printf("\nEnter the elements of matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter element (%d, %d): ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input matrix 2
    printf("\nEnter the elements of matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter element (%d, %d): ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Addition
    printf("\nPerforming matrix addition...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Matrix Addition Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Subtraction
    printf("\nPerforming matrix subtraction...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("Matrix Subtraction Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Multiplication
    printf("\nPerforming matrix multiplication...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("Matrix Multiplication Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\nThanks for using the Matrix Operations Program!");

    return 0;
}