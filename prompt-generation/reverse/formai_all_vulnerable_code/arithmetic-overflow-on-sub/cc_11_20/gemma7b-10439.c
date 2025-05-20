//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480

int main()
{
    int x1 = WIDTH / 2 - 10;
    int y1 = HEIGHT / 2 - 20;

    int x2 = WIDTH / 2 + 10;
    int y2 = HEIGHT / 2 - 20;

    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT / 2;

    int direction = 1;

    clock_t start_time = clock();

    while (1)
    {
        if (ball_x >= WIDTH - 20 || ball_x <= 20)
        {
            direction *= -1;
        }

        if (ball_y >= HEIGHT - 10 || ball_y <= 0)
        {
            direction *= -1;
        }

        switch (direction)
        {
            case 1:
                ball_x++;
                break;
            case -1:
                ball_x--;
                break;
            case 2:
                ball_y++;
                break;
            case -2:
                ball_y--;
                break;
        }

        // AI opponent's move
        if (ball_x - x2 > 10)
        {
            x2++;
        }
        else if (ball_x - x2 < -10)
        {
            x2--;
        }

        sleep(0.05);

        system("clear");

        // Draw the paddle and ball
        printf("*******************************\n");
        printf("           /\n");
        printf("          ||||_|/\n");
        printf("           \__) \n");
        printf("*******************************\n");

        printf("Ball: (%d, %d)\n", ball_x, ball_y);

        printf("Paddle 1: (%d, %d)\n", x1, y1);

        printf("Paddle 2: (%d, %d)\n", x2, y2);

        if (clock() - start_time >= 600000)
        {
            printf("Time up!");
            break;
        }
    }

    return 0;
}