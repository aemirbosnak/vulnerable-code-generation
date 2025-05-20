//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int x, y, w, h, i, j, t, seed;
    x = y = w = h = 0;
    t = 0;
    seed = time(NULL);

    printf("Enter the dimensions of the grid (w, h): ");
    scanf("%d %d", &w, &h);

    int **grid = (int**)malloc(h * sizeof(int*));
    for(i = 0; i < h; i++)
    {
        grid[i] = (int*)malloc(w * sizeof(int));
    }

    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    printf("The grid is:\n");
    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("Enter the number of iterations: ");
    scanf("%d", &t);

    for(i = 0; i < t; i++)
    {
        for(j = 0; j < h; j++)
        {
            for(int k = 0; k < w; k++)
            {
                if(grid[j][k] == 1 && (grid[j-1][k] == 1 || grid[j+1][k] == 1 || grid[j][k-1] == 1 || grid[j][k+1] == 1))
                {
                    grid[j][k] = 2;
                }
            }
        }
    }

    printf("The grid after %d iterations is:\n", t);
    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}