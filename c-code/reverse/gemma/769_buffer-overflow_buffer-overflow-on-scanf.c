#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grid[10][10];
    int x1, y1, x2, y2;
    int i, j, found = 0;

    printf("Enter the grid values (10x10): ");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter the coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (grid[i][j] == 0 && i == x1 && j == y1)
            {
                found = 1;
                grid[i][j] = 2;
            }
            else if (grid[i][j] == 0 && i == x2 && j == y2)
            {
                found = 1;
                grid[i][j] = 2;
            }
        }
    }

    if (found)
    {
        printf("Path found!\n");
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No path found.\n");
    }

    return 0;
}
