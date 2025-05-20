//FormAI DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rowsA, colsA, rowsB, colsB, i, j, k;
    printf("Enter the number of rows and columns of Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    int **matrixA = (int **) malloc(rowsA * sizeof(int *));
    for (i = 0; i < rowsA; i++)
        matrixA[i] = (int *) malloc(colsA * sizeof(int));

    printf("Enter elements of Matrix A: \n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the number of rows and columns of Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    int **matrixB = (int **) malloc(rowsB * sizeof(int *));
    for (i = 0; i < rowsB; i++)
        matrixB[i] = (int *) malloc(colsB * sizeof(int));

    printf("Enter elements of Matrix B: \n");
    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    int **result = (int **) malloc(rowsA * sizeof(int *));
    for (i = 0; i < rowsA; i++)
        result[i] = (int *) malloc(colsB * sizeof(int));

    // Multiplying matrixA and matrixB
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printf("\nMatrix A: \n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B: \n");
    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    printf("\nResult of matrix multiplication: \n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}