//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int n;
    int i, j;
    int **matrix1, **matrix2, **result;
    int status;

    // Allocate memory for matrices
    matrix1 = (int **)malloc(MAX_SIZE * sizeof(int *));
    matrix2 = (int **)malloc(MAX_SIZE * sizeof(int *));
    result = (int **)malloc(MAX_SIZE * sizeof(int *));

    for (i = 0; i < MAX_SIZE; i++) {
        matrix1[i] = (int *)malloc(MAX_SIZE * sizeof(int));
        matrix2[i] = (int *)malloc(MAX_SIZE * sizeof(int));
        result[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Get size of matrices from user
    printf("Enter the size of matrices: ");
    scanf("%d", &n);

    // Get elements of matrices from user
    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Compute sum of matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print result
    printf("Result:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < MAX_SIZE; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}