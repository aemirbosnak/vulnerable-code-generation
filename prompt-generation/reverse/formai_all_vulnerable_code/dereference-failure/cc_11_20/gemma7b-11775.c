//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **grid = (int **)malloc(MAX * sizeof(int *));
    for(int i = 0; i < MAX; i++)
    {
        grid[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the grid
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Create a path
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[2][3] = 1;

    // Find the path
    int x = 0, y = 0;
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, 1, -1, 0};

    while(grid[x][y] != 1)
    {
        int min_dist = MAX;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && grid[nx][ny] == 0 && min_dist > abs(nx - x) + abs(ny - y))
            {
                min_dist = abs(nx - x) + abs(ny - y);
            }
        }

        x += dx[min_dist];
        y += dy[min_dist];

        grid[x][y] = 1;
    }

    // Print the path
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}