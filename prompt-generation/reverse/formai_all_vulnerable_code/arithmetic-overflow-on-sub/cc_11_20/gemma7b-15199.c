//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 10
#define MAX_Y 20

int main()
{
    int x1 = MAX_X / 2;
    int y1 = MAX_Y / 2;
    int x2 = MAX_X - 1;
    int y2 = MAX_Y - 1;

    int ball_x = MAX_X / 2;
    int ball_y = MAX_Y / 2;

    int direction = 1;

    clock_t start_time = clock();

    while (clock() - start_time < 1000)
    {
        // Move the paddle
        if (x1 - ball_x > 0)
        {
            x1--;
        }
        else if (x1 + 1 < ball_x)
        {
            x1++;
        }

        // Move the ball
        ball_x += direction;
        ball_y--;

        // Check if the ball has hit a paddle
        if (ball_x == x1 && ball_y == y1)
        {
            direction *= -1;
        }
        else if (ball_x == x2 && ball_y == y2)
        {
            direction *= -1;
        }

        // Draw the game
        system("clear");
        for (int y = 0; y < MAX_Y; y++)
        {
            for (int x = 0; x < MAX_X; x++)
            {
                if (x == ball_x && y == ball_y)
                {
                    printf("O");
                }
                else if (x == x1 && y == y1)
                {
                    printf("P");
                }
                else if (x == x2 && y == y2)
                {
                    printf("P");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }

        sleep(0.05);
    }

    return 0;
}