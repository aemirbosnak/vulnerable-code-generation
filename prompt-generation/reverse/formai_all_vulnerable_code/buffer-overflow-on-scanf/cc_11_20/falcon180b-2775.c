//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_TRIALS 1000

double matrixA[MAX_SIZE][MAX_SIZE];
double matrixB[MAX_SIZE][MAX_SIZE];
double result[MAX_SIZE][MAX_SIZE];

int main()
{
    int size, i, j, k;
    double sum;
    struct timespec start, end;
    double elapsed_time;

    printf("Enter the size of the matrix (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Initialize matrices with random values
    srand(time(NULL));
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            matrixA[i][j] = rand() % 100;
            matrixB[i][j] = rand() % 100;
        }
    }

    // Perform matrix multiplication
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            sum = 0;
            for (k = 0; k < size; k++)
            {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = sum;
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    // Print results
    printf("Matrix A:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    printf("Result:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    return 0;
}