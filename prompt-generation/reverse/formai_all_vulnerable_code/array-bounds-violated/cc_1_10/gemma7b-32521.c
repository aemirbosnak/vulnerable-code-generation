//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
    printf("\033[ %d ; %d H", x, y);
}

int main()
{
    int x = 0, y = 0, direction = 1, score = 0;
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

    map[x][y] = 1;

    while (1)
    {
        system("clear");

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (map[i][j] == 1)
                {
                    gotoxy(j, i);
                    printf("O");
                }
                else
                {
                    gotoxy(j, i);
                    printf(".");
                }
            }
        }

        switch (direction)
        {
            case 1:
                y++;
                break;
            case 2:
                x++;
                break;
            case 3:
                y--;
                break;
            case 4:
                x--;
                break;
        }

        if (map[y][x] == 2)
        {
            direction = 0;
            score++;
        }

        if (score == 10)
        {
            system("clear");
            printf("Congratulations! You won!");
            break;
        }

        map[x][y] = 1;
        sleep(0.1);
    }

    return 0;
}