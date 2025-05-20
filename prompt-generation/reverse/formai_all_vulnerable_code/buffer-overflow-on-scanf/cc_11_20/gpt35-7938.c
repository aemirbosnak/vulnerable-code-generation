//FormAI DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>

int main() {
    int m1[10][10], m2[10][10], result[10][10];
    int r1, c1, r2, c2;
    int i, j, k;

    // Get matrix dimensions from user
    printf("Enter number of rows and columns for matrix 1: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter number of rows and columns for matrix 2: ");
    scanf("%d %d", &r2, &c2);

    // Verify if matrix dimensions are valid for matrix multiplication
    if (c1 != r2) {
        printf("Invalid matrix dimensions. Matrix multiplication not possible.");
        return 0;
    }

    // Get matrix elements from user for matrix 1
    printf("Enter elements matrix 1:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    // Get matrix elements from user for matrix 2
    printf("Enter elements for matrix 2:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    // Multiply the matrices
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // Print the result
    printf("Product of the matrices:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}