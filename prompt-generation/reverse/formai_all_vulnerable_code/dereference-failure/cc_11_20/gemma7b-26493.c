//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main()
{
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    int x = MAX_SIZE / 2;
    int y = MAX_SIZE / 2;
    grid[x][y] = 1;

    int num_percolation = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (grid[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && nx < MAX_SIZE && ny >= 0 && ny < MAX_SIZE && grid[nx][ny] == 0)
                    {
                        grid[nx][ny] = 1;
                        num_percolation++;
                    }
                }
            }
        }
    }

    printf("Number of percolations: %d\n", num_percolation);

    free(grid);

    return 0;
}