//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 10
#define TOP_BOUND 0
#define BOTTOM_BOUND 20

#define BULLET_SPEED 2
#define SHIP_SPEED 1

int main()
{
    int x = 5, y = 5;
    int bullet_x = 0, bullet_y = TOP_BOUND - 1;
    int score = 0;

    char board[20][11] = {{'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'}
                           };

    board[x][y] = 'S';

    srand(time(NULL));

    while (1)
    {
        int direction = rand() % 4;

        switch (direction)
        {
            case 0:
                bullet_x--;
                break;
            case 1:
                bullet_x++;
                break;
            case 2:
                bullet_y++;
                break;
            case 3:
                bullet_y--;
                break;
        }

        if (bullet_x < LEFT_BOUND || bullet_x > RIGHT_BOUND)
        {
            bullet_x = x;
            bullet_y = TOP_BOUND - 1;
            score++;
        }

        if (bullet_y > BOTTOM_BOUND)
        {
            bullet_x = x;
            bullet_y = TOP_BOUND - 1;
            score++;
        }

        if (board[bullet_x][bullet_y] == 'S')
        {
            board[bullet_x][bullet_y] = '.';
            bullet_x = x;
            bullet_y = TOP_BOUND - 1;
            score++;
        }

        system("clear");

        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                printf("%c ", board[i][j]);
            }

            printf("\n");
        }

        printf("Score: %d", score);

        if (score == 10)
        {
            break;
        }
    }

    return 0;
}