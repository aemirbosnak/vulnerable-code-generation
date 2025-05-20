//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

int main()
{
    // Create a grid of squares
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate a post-apocalyptic environment
    grid[5][5] = 1;
    grid[6][6] = 1;
    grid[7][7] = 1;

    // Percolation simulation
    int x, y;
    printf("Enter the coordinates of the water source (x, y): ");
    scanf("%d %d", &x, &y);

    // Check if the water source is valid
    if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE)
    {
        printf("Invalid coordinates.\n");
        return 1;
    }

    // Spread the water
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        // Check if the cell is empty and not out of bounds
        if (grid[new_x][new_y] == 0 && new_x >= 0 && new_x < MAX_SIZE && new_y >= 0 && new_y < MAX_SIZE)
        {
            // Spread the water
            grid[new_x][new_y] = 1;
        }
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

    return 0;
}