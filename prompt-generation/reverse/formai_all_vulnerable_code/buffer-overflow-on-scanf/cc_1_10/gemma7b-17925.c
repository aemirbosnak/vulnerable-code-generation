//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void knight_search(int **grid, int size, int x, int y)
{
    if (x < 0 || x >= size || y < 0 || y >= size)
    {
        return;
    }
    if (grid[x][y] == 1)
    {
        return;
    }
    grid[x][y] = 1;

    knight_search(grid, size, x - 2, y - 1);
    knight_search(grid, size, x - 1, y - 2);
    knight_search(grid, size, x + 1, y - 2);
    knight_search(grid, size, x + 2, y - 1);
}

int main()
{
    int size, x, y;
    int **grid;

    printf("Enter the size of the grid: ");
    scanf("%d", &size);

    grid = (int **)malloc(size * size * sizeof(int));
    for (x = 0; x < size; x++)
    {
        grid[x] = (int *)malloc(size * sizeof(int));
        for (y = 0; y < size; y++)
        {
            grid[x][y] = 0;
        }
    }

    printf("Enter the coordinates of the knight: ");
    scanf("%d %d", &x, &y);

    knight_search(grid, size, x, y);

    printf("The knight has been found!\n");

    return 0;
}