//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 5
#define MAX_HEIGHT 5

int main()
{

    int board[MAX_WIDTH][MAX_HEIGHT] = {{0, 0, 1, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    int paddle_x = 0;
    int paddle_y = MAX_HEIGHT - 1;

    int ball_x = MAX_WIDTH / 2;
    int ball_y = MAX_HEIGHT - 2;

    int direction = 1;

    while (1)
    {
        system("clear");

        for (int y = 0; y < MAX_HEIGHT; y++)
        {
            for (int x = 0; x < MAX_WIDTH; x++)
            {
                if (board[x][y] == 1)
                {
                    printf("#");
                }
                else if (x == paddle_x && y == paddle_y)
                {
                    printf("P");
                }
                else if (x == ball_x && y == ball_y)
                {
                    printf("O");
                }
                else
                {
                    printf(" ");
                }
            }

            printf("\n");
        }

        switch (direction)
        {
            case 1:
                ball_x++;
                break;
            case 2:
                ball_x--;
                break;
            case 3:
                ball_y--;
                break;
            case 4:
                ball_y++;
                break;
        }

        if (board[ball_x][ball_y] == 1)
        {
            direction = 0;
        }

        if (ball_x == paddle_x && ball_y == paddle_y)
        {
            direction = 0;
        }

        if (direction == 0)
        {
            printf("Game Over!");
            break;
        }

        sleep(0.1);
    }

    return 0;
}