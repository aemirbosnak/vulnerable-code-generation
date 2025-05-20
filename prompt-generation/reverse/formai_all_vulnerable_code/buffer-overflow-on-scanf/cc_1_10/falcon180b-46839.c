//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int n, i, j, k, count = 0;
    int **matrix, **result_matrix;
    int *row, *col;
    double start_time, end_time;

    // get input dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &n, &n);

    // allocate memory for matrices
    matrix = (int **)malloc(n * sizeof(int *));
    result_matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        result_matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // initialize matrices with random values
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // start timer
    start_time = clock();

    // perform matrix multiplication
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                count += matrix[i][k] * result_matrix[k][j];
            }
            result_matrix[i][j] = count;
            count = 0;
        }
    }

    // end timer
    end_time = clock();

    // print result
    printf("Result:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", result_matrix[i][j]);
        }
        printf("\n");
    }

    // free memory
    for (i = 0; i < n; i++) {
        free(matrix[i]);
        free(result_matrix[i]);
    }
    free(matrix);
    free(result_matrix);

    return 0;
}