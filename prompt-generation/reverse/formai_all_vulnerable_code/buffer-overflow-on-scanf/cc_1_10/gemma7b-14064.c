//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int x, y, i, j, found = 0;
    char maze[MAX][MAX] = {
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
        { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
    };

    printf("Enter the starting position (x, y): ");
    scanf("%d %d", &x, &y);

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (maze[i][j] == 'S' && x == i && y == j)
            {
                maze[i][j] = 'P';
                found = 1;
            }
            else if (maze[i][j] == 'E' && found)
            {
                maze[i][j] = 'T';
            }
        }
    }

    printf("The path is: ");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}