//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int x = 0, y = 0, w = 10, h = 10, map[w][h], score = 0, game_over = 0;

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            map[i][j] = 0;
        }
    }

    map[x][y] = 1;

    while (!game_over)
    {
        system("clear");
        printf("Score: %d\n", score);

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                if (map[i][j] == 1)
                {
                    printf("X ");
                }
                else
                {
                    printf(". ");
                }
            }
            printf("\n");
        }

        printf("Enter move (w/a/s/d): ");
        char move;

        scanf("%c", &move);

        switch (move)
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
                printf("Invalid move.\n");
                break;
        }

        if (map[x][y] == 2)
        {
            game_over = 1;
            printf("Game Over! Your score is: %d\n", score);
        }
        else if (map[x][y] == 0)
        {
            map[x][y] = 1;
            score++;
        }
    }

    return 0;
}