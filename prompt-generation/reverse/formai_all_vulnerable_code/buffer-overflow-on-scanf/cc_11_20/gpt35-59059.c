//FormAI DATASET v1.0 Category: Funny ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10], b[10][10], product[10][10], i, j, k, row1, col1, row2, col2;

    printf("Enter number of rows and columns of first matrix (max 10x10) separated by space: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter number of rows and columns of second matrix (max 10x10) separated by space: ");
    scanf("%d %d", &row2, &col2);

    if (col1 != row2) {
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        exit(1);
    }

    printf("\nEnter elements of first matrix:\n");

    for (i = 0; i < row1; ++i) {
        for (j = 0; j < col1; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");

    for (i = 0; i < row2; ++i) {
        for (j = 0; j < col2; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    // Initializing elements of product matrix to 0
    for (i = 0; i < row1; ++i) {
        for (j = 0; j < col2; ++j) {
            product[i][j] = 0;
        }
    }

    // Multiplying matrices a and b and storing in product
    for (i = 0; i < row1; ++i) {
        for (j = 0; j < col2; ++j) {
            for (k = 0; k < col1; ++k) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nResultant matrix:\n");

    for (i = 0; i < row1; ++i) {
        for (j = 0; j < col2; ++j) {
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}