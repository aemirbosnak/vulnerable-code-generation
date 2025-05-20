//FormAI DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the Matrix!\n");
    printf("This program performs various matrix operations.\n");
    printf("We're going to start by creating two matrices.\n");

    int rows1, cols1, rows2, cols2;

    // get dimensions of first matrix from user
    printf("Enter number of rows for first matrix: ");
    scanf("%d", &rows1);

    printf("Enter number of columns for first matrix: ");
    scanf("%d", &cols1);

    // get dimensions of second matrix from user
    printf("\nEnter number of rows for second matrix: ");
    scanf("%d", &rows2);

    printf("Enter number of columns for second matrix: ");
    scanf("%d", &cols2);

    // validate matrix dimensions
    if (cols1 != rows2) {
        printf("\nError: Matrix dimensions are not compatible for multiplication.\n");
        printf("Please try again with different dimensions.\n");
        exit(1);
    }

    // create matrices
    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    // populate matrix1
    printf("\nPlease enter values for the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Enter value for matrix1[%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // populate matrix2
    printf("\nPlease enter values for the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Enter value for matrix2[%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nMatrix1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    // matrix addition
    printf("\nNow, let's add these matrices together:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // matrix multiplication
    printf("\nNow, let's multiply these matrices together:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("\nWow! We just performed some amazing matrix operations!\n");
    printf("Thanks for using our program!\n");

    return 0;
}