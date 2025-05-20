//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main()
{
    int **arr = NULL;
    int i, j, k, seed, percolate = 0;

    seed = time(NULL);
    srand(seed);

    arr = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++)
    {
        arr[i] = (int *)malloc(COLS * sizeof(int));
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    printf("Original Array:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Percolation Algorithm:\n");
    for (k = 0; k < 10; k++)
    {
        percolate = 0;
        for (i = 0; i < ROWS; i++)
        {
            for (j = 0; j < COLS; j++)
            {
                if (arr[i][j] == 1)
                {
                    percolate++;
                    arr[i][j] = 2;
                }
            }
        }

        printf("Iteration %d: %d sites percolated\n", k, percolate);
    }

    for (i = 0; i < ROWS; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}