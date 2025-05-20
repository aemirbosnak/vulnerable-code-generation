//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    int **arr = NULL;
    int i, j, k;

    arr = (int **)malloc(WIDTH * sizeof(int *));
    for(i = 0; i < WIDTH; i++)
    {
        arr[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            arr[i][j] = 0;
        }
    }

    arr[2][2] = 1;
    arr[2][3] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;

    k = 0;
    while(k < 10)
    {
        for(i = 0; i < HEIGHT; i++)
        {
            for(j = 0; j < WIDTH; j++)
            {
                if(arr[i][j] == 0 && (arr[i-1][j] == 1 || arr[i][j-1] == 1 || arr[i+1][j] == 1 || arr[i][j+1] == 1))
                {
                    arr[i][j] = 1;
                }
            }
        }

        k++;
    }

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}