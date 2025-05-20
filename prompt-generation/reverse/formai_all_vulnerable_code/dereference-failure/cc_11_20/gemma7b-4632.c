//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: brave
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x, y, z;
    int **arr;
    arr = (int**)malloc(10 * sizeof(int*));
    for(x = 0; x < 10; x++)
    {
        arr[x] = (int*)malloc(10 * sizeof(int));
        for(y = 0; y < 10; y++)
        {
            arr[x][y] = 0;
        }
    }

    x = rand() % 10;
    y = rand() % 10;
    arr[x][y] = 1;

    for(z = 0; z < 10; z++)
    {
        for(x = 0; x < 10; x++)
        {
            for(y = 0; y < 10; y++)
            {
                if(arr[x][y] == 1)
                {
                    arr[x][y] = 2;
                    if(x > 0 && arr[x-1][y] == 0)
                        arr[x-1][y] = 2;
                    if(x < 9 && arr[x+1][y] == 0)
                        arr[x+1][y] = 2;
                    if(y > 0 && arr[x][y-1] == 0)
                        arr[x][y-1] = 2;
                    if(y < 9 && arr[x][y+1] == 0)
                        arr[x][y+1] = 2;
                }
            }
        }
    }

    printf("Percolation Simulation:\n");
    for(x = 0; x < 10; x++)
    {
        for(y = 0; y < 10; y++)
        {
            printf("%d ", arr[x][y]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}