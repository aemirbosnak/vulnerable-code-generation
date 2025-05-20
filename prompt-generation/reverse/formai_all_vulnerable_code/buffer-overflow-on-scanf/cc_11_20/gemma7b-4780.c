//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

int main()
{
    system("clear");
    int x = 0, y = 0, z = 0, map[10][10] = {0};

    map[5][5] = 1;
    map[6][5] = 1;
    map[6][6] = 1;

    printf("Press 'w' to move north, 's' to move south, 'a' to move west, 'e' to move east.\n");

    char direction;

    while (1)
    {
        printf("Enter direction: ");
        scanf("%c", &direction);

        switch (direction)
        {
            case 'w':
                if (map[x - 1][y] == 0)
                {
                    x--;
                }
                break;
            case 's':
                if (map[x + 1][y] == 0)
                {
                    x++;
                }
                break;
            case 'a':
                if (map[x][y - 1] == 0)
                {
                    y--;
                }
                break;
            case 'e':
                if (map[x][y + 1] == 0)
                {
                    y++;
                }
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        system("clear");

        printf("You are at (%d, %d).", x, y);

        if (map[x][y] == 1)
        {
            printf("There is a wall there.\n");
        }

        printf("\nPress 'q' to quit.\n");

        char quit;

        scanf("Enter quit: ", &quit);

        if (quit == 'q')
        {
            break;
        }
    }

    return 0;
}