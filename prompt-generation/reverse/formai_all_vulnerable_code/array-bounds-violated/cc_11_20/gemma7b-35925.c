//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 5

int main()
{
    int map[MAP_SIZE][MAP_SIZE] = {{0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 1},
                              {0, 0, 0, 0, 0}};

    int player_x = 0;
    int player_y = 0;

    char direction = ' ';

    while (direction != 'q')
    {
        printf("Enter direction (w, a, s, d, q): ");
        scanf("%c", &direction);

        switch (direction)
        {
            case 'w':
                if (map[player_x][player_y - 1] == 0)
                {
                    player_y--;
                }
                break;
            case 'a':
                if (map[player_x - 1][player_y] == 0)
                {
                    player_x--;
                }
                break;
            case 's':
                if (map[player_x][player_y + 1] == 0)
                {
                    player_y++;
                }
                break;
            case 'd':
                if (map[player_x + 1][player_y] == 0)
                {
                    player_x++;
                }
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid direction.\n");
                break;
        }

        system("clear");

        for (int y = 0; y < MAP_SIZE; y++)
        {
            for (int x = 0; x < MAP_SIZE; x++)
            {
                if (x == player_x && y == player_y)
                {
                    printf("P ");
                }
                else if (map[x][y] == 1)
                {
                    printf("# ");
                }
                else
                {
                    printf(". ");
                }
            }

            printf("\n");
        }
    }

    return 0;
}