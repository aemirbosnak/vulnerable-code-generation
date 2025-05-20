//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int **grid = (int**)malloc(MAX_SIZE * sizeof(int*));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int*)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate Percolation
    int x = rand() % MAX_SIZE;
    int y = rand() % MAX_SIZE;
    grid[x][y] = 1;

    // Spread the water
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; grid[x][y] && i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && nx < MAX_SIZE && ny >= 0 && ny < MAX_SIZE && grid[nx][ny] == 0)
            {
                grid[nx][ny] = 1;
            }
        }
        x = rand() % MAX_SIZE;
        y = rand() % MAX_SIZE;
    }

    // Print the grid
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}