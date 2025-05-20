#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grid[10][10];
    int x, y, i, j;

    scanf(" %d %d ", &x, &y);

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            scanf(" %d ", &grid[i][j]);
        }
    }

    printf("Path found!\n");

    return 0;
}
