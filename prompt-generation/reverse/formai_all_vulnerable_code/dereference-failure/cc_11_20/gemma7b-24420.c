//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **grid, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            int neighbors = 0;
            // Check the 8 neighbors
            if(i-1 >= 0) neighbors++;
            if(i+1 < r) neighbors++;
            if(j-1 >= 0) neighbors++;
            if(j+1 < c) neighbors++;
            if(i-1 && j-1 >= 0) neighbors++;
            if(i-1 && j+1 < c) neighbors++;
            if(i+1 && j-1 >= 0) neighbors++;
            if(i+1 && j+1 < c) neighbors++;

            // Apply the Game of Life rules
            if(neighbors < 2) grid[i][j] = 0;
            else if(neighbors == 2) grid[i][j] = grid[i][j];
            else if(neighbors > 3) grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
}

int main()
{
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    int **grid = (int**)malloc(r * sizeof(int*));
    for(int i = 0; i < r; i++) grid[i] = (int*)malloc(c * sizeof(int));

    // Initialize the grid
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Enter the initial state of the grid
    printf("Enter the initial state of the grid (1 for alive, 0 for dead):\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    // Play the Game of Life
    GameOfLife(grid, r, c);

    // Print the final state of the grid
    printf("The final state of the grid is:\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}