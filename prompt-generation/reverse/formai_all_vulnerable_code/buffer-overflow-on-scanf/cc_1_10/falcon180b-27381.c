//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, i, j, sum;
    int **matrix1, **matrix2, **result;
    clock_t start, end;
    double cpu_time_used;

    // Get the dimensions of the matrices
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &n, &m);

    // Allocate memory for the matrices
    matrix1 = (int **)malloc(n * sizeof(int *));
    matrix2 = (int **)malloc(n * sizeof(int *));
    result = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix1[i] = (int *)malloc(m * sizeof(int));
        matrix2[i] = (int *)malloc(m * sizeof(int));
        result[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the matrices with random values
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    // Perform matrix addition
    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum = matrix1[i][j] + matrix2[i][j];
            result[i][j] = sum;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the results
    printf("The sum of the matrices is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("The program took %.2f seconds to run.\n", cpu_time_used);

    // Free the memory allocated for the matrices
    for (i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}