//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **arr = (int **)malloc(sizeof(int *) * WIDTH);
    for (int i = 0; i < WIDTH; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * HEIGHT);
    }

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] = 2;
                if (i > 0)
                {
                    arr[i - 1][j] = 2;
                }
                if (i < WIDTH - 1)
                {
                    arr[i + 1][j] = 2;
                }
                if (j > 0)
                {
                    arr[i][j - 1] = 2;
                }
                if (j < HEIGHT - 1)
                {
                    arr[i][j + 1] = 2;
                }
            }
        }
    }

    for (int i = 0; i < WIDTH; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}