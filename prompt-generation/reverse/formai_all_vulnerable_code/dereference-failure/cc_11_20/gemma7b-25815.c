//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

int main()
{
    int **arr = NULL;
    int i, j, x, y, count = 0;
    srand(time(NULL));

    // Allocate memory for the 2D array
    arr = (int **)malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++)
    {
        arr[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the array
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Percolation process
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (arr[y][x] == 0)
            {
                count++;
                arr[y][x] = 1;
                if (x - 1 >= 0 && arr[y][x - 1] == 1)
                {
                    arr[y][x] = 1;
                }
                if (x + 1 < WIDTH && arr[y][x + 1] == 1)
                {
                    arr[y][x] = 1;
                }
                if (y - 1 >= 0 && arr[y - 1][x] == 1)
                {
                    arr[y][x] = 1;
                }
                if (y + 1 < HEIGHT && arr[y + 1][x] == 1)
                {
                    arr[y][x] = 1;
                }
            }
        }
    }

    // Print the result
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < HEIGHT; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}