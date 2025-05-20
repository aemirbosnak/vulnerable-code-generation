//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include <stdio.h>

#define MAX 10

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX], i, j, k;

    // Input first matrix
    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Addition of two matrices
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Display result
    printf("Result:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    // Multiplication of two matrices
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            for (k = 0; k < MAX; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Display result
    printf("\nProduct:\n");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}