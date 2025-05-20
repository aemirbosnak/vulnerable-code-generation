//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, n, m, p;
    int **matrix;
    int **result;
    int sum = 0;

    // Initialize random seed
    srand(time(NULL));

    // Get matrix dimensions from user
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);

    // Allocate memory for matrix
    matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }

    // Fill matrix with random numbers
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // Print original matrix
    printf("\nOriginal matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Perform matrix multiplication
    result = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        result[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < m; k++) {
                sum += matrix[i][k] * matrix[k][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }

    // Print result matrix
    printf("\nResult matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}