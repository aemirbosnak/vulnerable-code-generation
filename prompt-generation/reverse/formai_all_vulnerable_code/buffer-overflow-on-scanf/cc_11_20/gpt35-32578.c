//FormAI DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

int main(void) {
    int matrix[ROW][COL];
    int i, j, sum;

    // Input matrix values from user
    printf("Enter %d x %d matrix values:\n", ROW, COL);
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n");

    // Display matrix
    printf("Matrix:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Calculate and display sum of each row
    printf("Sum of each row:\n");
    for (i = 0; i < ROW; i++) {
        sum = 0;
        for (j = 0; j < COL; j++) {
            sum += matrix[i][j];
        }
        printf("%d\n", sum);
    }

    printf("\n");

    // Calculate and display sum of each column
    printf("Sum of each column:\n");
    for (j = 0; j < COL; j++) {
        sum = 0;
        for (i = 0; i < ROW; i++) {
            sum += matrix[i][j];
        }
        printf("%d\t", sum);
    }
    printf("\n");

    printf("\n");

    // Find and display diagonal elements
    printf("Diagonal elements:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (i == j) {
                printf("%d\t", matrix[i][j]);
            }
        }
    }

    printf("\n");

    return 0;
}