//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n;
    int **matrix1, **matrix2, **result;
    int rows, cols;

    // Get matrix dimensions from user
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for matrices
    matrix1 = (int **)malloc(rows * sizeof(int *));
    matrix2 = (int **)malloc(cols * sizeof(int *));
    result = (int **)malloc(rows * sizeof(int *));

    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    // Fill matrices with random numbers
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            for (n = 0; n < cols; n++) {
                result[i][j] += matrix1[i][n] * matrix2[n][j];
            }
        }
    }

    // Print result matrix
    printf("\nResult:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}