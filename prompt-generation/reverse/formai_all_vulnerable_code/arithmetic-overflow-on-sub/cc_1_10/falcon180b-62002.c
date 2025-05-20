//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main()
{
    int rows, cols, i, j, n;
    int fib[MAX_ROWS][MAX_COLS];
    struct timespec start, end;
    double elapsed;

    // get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // initialize the Fibonacci sequence
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            fib[i][j] = 0;
        }
    }

    // set the first two terms of the sequence
    fib[0][0] = 1;
    fib[1][0] = 1;

    // calculate the rest of the sequence
    for (i = 2; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            n = i - 1;
            fib[i][j] = fib[i-1][j] + fib[i-2][j];
        }
    }

    // print the Fibonacci sequence
    printf("\nThe Fibonacci sequence is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", fib[i][j]);
        }
        printf("\n");
    }

    // get the current time
    clock_gettime(CLOCK_MONOTONIC, &start);

    // calculate the elapsed time
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;

    // print the elapsed time
    printf("\nElapsed time: %f seconds\n", elapsed);

    return 0;
}