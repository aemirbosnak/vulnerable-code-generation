//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n, m;
    clock_t start, end;
    double duration;

    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &n, &m);

    // Allocate memory for the matrix
    double **a = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++)
    {
        a[i] = (double*)malloc(m * sizeof(double));
    }

    // Initialize the matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[i][j] = 0;
        }
    }

    start = clock();

    // Perform some calculations on the matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[i][j] = a[i][j] + 1;
        }
    }

    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("The time taken to perform the calculations is: %.2f seconds\n", duration);

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}