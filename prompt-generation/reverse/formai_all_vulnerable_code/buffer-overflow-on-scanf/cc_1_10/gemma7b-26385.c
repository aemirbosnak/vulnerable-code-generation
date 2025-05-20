//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

void draw_map(int **map, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%c ", map[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **map = NULL;
    int x, y;

    printf("Enter the dimensions of the map (x, y): ");
    scanf("%d %d", &x, &y);

    map = (int **)malloc(x * sizeof(int *) + y * sizeof(int));
    for (int i = 0; i < x; i++)
    {
        map[i] = (int *)malloc(y * sizeof(int));
    }

    // Invade the map
    printf("Enter the coordinates of the invader (x, y): ");
    int invader_x, invader_y;
    scanf("%d %d", &invader_x, &invader_y);

    map[invader_x][invader_y] = 1;

    // Draw the map
    draw_map(map, x, y);

    // Check if the invader has been captured
    if (map[0][invader_y] == 1)
    {
        printf("The invader has been captured!");
    }
    else
    {
        printf("The invader is still free!");
    }

    free(map);

    return 0;
}