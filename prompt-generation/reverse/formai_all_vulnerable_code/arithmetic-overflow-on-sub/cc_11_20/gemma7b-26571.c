//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20

int main()
{
    int x_pos = WIDTH / 2;
    int y_pos = HEIGHT / 2;

    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT - 1;

    int direction = 1;

    time_t t = time(NULL);

    while (1)
    {
        system("clear");

        // Draw the border
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (x == ball_x && y == ball_y)
                {
                    printf("O ");
                }
                else if (x == x_pos && y == y_pos)
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

        // Move the paddle
        if (time(NULL) - t > 1)
        {
            t = time(NULL);

            if (direction == 1)
            {
                x_pos++;
            }
            else
            {
                x_pos--;
            }

            if (x_pos > WIDTH - 1)
            {
                direction = -1;
            }
            else if (x_pos < 0)
            {
                direction = 1;
            }
        }

        // Move the ball
        ball_x++;

        if (ball_x > WIDTH - 1)
        {
            ball_x = WIDTH - 1;
            direction *= -1;
        }
        else if (ball_x < 0)
        {
            ball_x = 0;
            direction *= -1;
        }

        if (ball_y == y_pos)
        {
            direction *= -1;
            ball_y--;
        }

        sleep(0.1);
    }
}