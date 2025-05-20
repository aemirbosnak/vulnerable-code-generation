//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char map[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    char direction = ' ';
    int x = 0, y = 0;

    system("clear");

    while (direction != 'q')
    {
        printf("Enter direction (w, a, s, d, q): ");
        scanf(" %c", &direction);

        switch (direction)
        {
            case 'w':
                if (map[x][y - 1] == 0)
                    y--;
                break;
            case 'a':
                if (map[x - 1][y] == 0)
                    x--;
                break;
            case 's':
                if (map[x][y + 1] == 0)
                    y++;
                break;
            case 'd':
                if (map[x + 1][y] == 0)
                    x++;
                break;
            case 'q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        map[x][y] = 1;

        system("clear");

        printf("You are at (%d, %d).\n", x, y);
        printf("Press 'q' to quit.\n");

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (map[i][j] == 1)
                    printf("X ");
                else
                    printf(". ");
            }
            printf("\n");
        }
    }

    return 0;
}