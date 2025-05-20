//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 32

#define PADDLE_WIDTH 8
#define PADDLE_HEIGHT 20

#define BALL_SIZE 8

int main()
{
    int x_ball = WIDTH / 2;
    int y_ball = HEIGHT - 1;

    int x_paddle_left = 0;
    int y_paddle_left = HEIGHT - PADDLE_HEIGHT - 1;

    int x_paddle_right = WIDTH - PADDLE_WIDTH - 1;
    int y_paddle_right = HEIGHT - PADDLE_HEIGHT - 1;

    int direction_ball = 1;
    int direction_paddle_left = 1;
    int direction_paddle_right = -1;

    time_t t_start = time(NULL);

    // Game Loop
    while (time(NULL) - t_start < 60)
    {
        // Move the ball
        x_ball += direction_ball * 2;
        y_ball -= direction_ball;

        // Move the paddles
        if (direction_paddle_left == 1)
        {
            x_paddle_left += direction_paddle_left;
            if (x_paddle_left < 0)
            {
                direction_paddle_left *= -1;
                x_paddle_left = 0;
            }
        }

        if (direction_paddle_right == -1)
        {
            x_paddle_right += direction_paddle_right;
            if (x_paddle_right > WIDTH - PADDLE_WIDTH)
            {
                direction_paddle_right *= -1;
                x_paddle_right = WIDTH - PADDLE_WIDTH - 1;
            }
        }

        // Check if the ball has hit a paddle
        if (x_ball >= x_paddle_right && y_ball <= y_paddle_right)
        {
            direction_ball *= -1;
            x_ball = x_paddle_right - BALL_SIZE;
        }

        if (x_ball <= x_paddle_left && y_ball <= y_paddle_left)
        {
            direction_ball *= -1;
            x_ball = x_paddle_left + BALL_SIZE;
        }

        // Draw the game
        system("clear");
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (x_ball == x && y_ball == y)
                {
                    printf("O ");
                }
                else if (x_paddle_left == x && y_paddle_left == y)
                {
                    printf("L ");
                }
                else if (x_paddle_right == x && y_paddle_right == y)
                {
                    printf("R ");
                }
                else
                {
                    printf(". ");
                }
            }
            printf("\n");
        }

        sleep(0.1);
    }

    return 0;
}