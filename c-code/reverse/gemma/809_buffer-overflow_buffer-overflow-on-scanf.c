#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0, y = 0, treasure_x = 5, treasure_y = 3;
    char direction;

    printf("You are in a labyrinth. Enter w/a/s/d to move:");

    scanf("%c", &direction);

    switch (direction)
    {
        case 'w':
            y--;
            break;
        case 'a':
            x--;
            break;
        case 's':
            y++;
            break;
        case 'd':
            x++;
            break;
        default:
            printf("Invalid direction.\n");
            return 1;
    }

    if (x == treasure_x && y == treasure_y)
    {
        printf("You found the treasure!\n");
    }
    else
    {
        printf("You are not on the treasure. Try again.\n");
    }

    return 0;
}
