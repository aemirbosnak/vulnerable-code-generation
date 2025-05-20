#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **maze = NULL;
    int x = 50, y = 50;

    maze = (int**)malloc(x * sizeof(int*) + y * sizeof(int));
    for (int i = 0; i < x; i++)
    {
        maze[i] = (int*)malloc(y * sizeof(int));
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            free(maze[i][j]);
        }
        free(maze[i]);
    }
    free(maze);

    return 0;
}
