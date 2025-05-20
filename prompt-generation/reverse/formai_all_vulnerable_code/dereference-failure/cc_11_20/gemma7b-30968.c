//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int i, j, k, l, n, m, x, y, z;
    time_t t;
    srand(time(NULL));

    n = 10;
    m = 10;
    x = 5;
    y = 5;
    z = 2;

    int **grid = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            grid[i][j] = 0;
        }
    }

    grid[x][y] = 1;

    t = time(NULL);
    while(time(NULL) - t < z)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    k = rand() % 4;
                    switch(k)
                    {
                        case 0:
                            if(i > 0) grid[i - 1][j] = 1;
                            break;
                        case 1:
                            if(j > 0) grid[i][j - 1] = 1;
                            break;
                        case 2:
                            if(i < n - 1) grid[i + 1][j] = 1;
                            break;
                        case 3:
                            if(j < m - 1) grid[i][j + 1] = 1;
                            break;
                    }
                }
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    printf("%d %d ", i, j);
                }
            }
        }

        printf("\n");
    }

    free(grid);

    return 0;
}