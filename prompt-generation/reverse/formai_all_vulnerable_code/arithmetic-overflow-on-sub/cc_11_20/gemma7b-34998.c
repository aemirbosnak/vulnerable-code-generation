//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20

int main()
{
    int x_paddle = WIDTH / 2;
    int y_paddle = HEIGHT - 1;

    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT / 2;

    int direction = 1;

    time_t start_time = time(NULL);

    while (time(NULL) - start_time < 60)
    {
        // Draw the screen
        system("clear");
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (x == x_paddle && y == y_paddle)
                {
                    printf("P");
                }
                else if (x == ball_x && y == ball_y)
                {
                    printf("O");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }

        // Move the ball
        ball_x += direction * 2;

        // If the ball hits a wall, change direction
        if (ball_x < 0 || ball_x >= WIDTH)
        {
            direction *= -1;
        }

        // Move the paddle
        if (ball_x - x_paddle > 0)
        {
            x_paddle++;
        }
        else if (ball_x - x_paddle < 0)
        {
            x_paddle--;
        }

        // Sleep
        sleep(0.1);
    }

    return 0;
}