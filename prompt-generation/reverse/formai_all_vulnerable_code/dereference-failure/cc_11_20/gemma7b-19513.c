//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main()
{
    int **grid = NULL;
    int **percolation_array = NULL;
    int num_iter = 0;
    int seed = time(NULL);

    grid = (int **)malloc(ROWS * sizeof(int *));
    percolation_array = (int **)malloc(ROWS * sizeof(int *));
    for(int r = 0; r < ROWS; r++)
    {
        grid[r] = (int *)malloc(COLS * sizeof(int));
        percolation_array[r] = (int *)malloc(COLS * sizeof(int));
    }

    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            percolation_array[r][c] = rand() % 2;
        }
    }

    for(num_iter = 0; num_iter < 1000; num_iter++)
    {
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(percolation_array[r][c] == 1)
                {
                    int up = 0, down = 0, left = 0, right = 0;
                    if(r > 0) up = percolation_array[r - 1][c];
                    if(r < ROWS - 1) down = percolation_array[r + 1][c];
                    if(c > 0) left = percolation_array[r][c - 1];
                    if(c < COLS - 1) right = percolation_array[r][c + 1];
                    if(up || down || left || right)
                    {
                        grid[r][c] = 1;
                    }
                }
            }
        }
    }

    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    return 0;
}