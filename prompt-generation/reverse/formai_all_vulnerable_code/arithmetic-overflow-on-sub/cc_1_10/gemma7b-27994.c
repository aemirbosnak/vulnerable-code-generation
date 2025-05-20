//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 24

int main()
{
    int x_paddle = WIDTH / 2;
    int y_paddle = HEIGHT - 1;
    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT - 1;
    int direction = 1;

    char board[HEIGHT][WIDTH] = {0};

    board[ball_y][ball_x] = 'O';
    board[y_paddle][x_paddle] = 'P';

    time_t start = time(NULL);

    while (time(NULL) - start < 30)
    {
        // Ball movement
        ball_x += direction * 2;
        ball_y--;

        // Paddle movement
        if (ball_x - x_paddle >= WIDTH / 2)
        {
            direction = -1;
            x_paddle = ball_x - WIDTH / 2;
        }
        else if (ball_x - x_paddle <= -WIDTH / 2)
        {
            direction = 1;
            x_paddle = ball_x + WIDTH / 2;
        }

        // Draw the board
        system("clear");
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                printf("%c ", board[y][x]);
            }
            printf("\n");
        }

        // Update the board
        board[ball_y][ball_x] = 'O';
        board[y_paddle][x_paddle] = 'P';

        sleep(0.1);
    }

    return 0;
}