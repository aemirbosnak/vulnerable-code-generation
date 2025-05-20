//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 10

int map[MAP_SIZE][MAP_SIZE] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
{0, 1, 0, 1, 0, 1, 1, 0, 0, 0},
{0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
{0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int main()
{
    int x, y;
    char direction;

    printf("Enter initial position (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter direction (N, S, E, W): ");
    scanf(" %c", &direction);

    switch (direction)
    {
        case 'N':
            y--;
            break;
        case 'S':
            y++;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }

    if (map[x][y] == 1)
    {
        printf("You broke out of the box!\n");
    }
    else
    {
        printf("Invalid move.\n");
    }

    return 0;
}