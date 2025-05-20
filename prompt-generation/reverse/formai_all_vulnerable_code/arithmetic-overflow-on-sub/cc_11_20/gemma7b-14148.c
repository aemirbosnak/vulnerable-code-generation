//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

#define PADDLE_SIZE 10
#define BALL_SIZE 5

int main()
{
    int x_ball = WIDTH / 2;
    int y_ball = HEIGHT - 1;
    int x_paddle_left = 0;
    int y_paddle_left = HEIGHT - PADDLE_SIZE - 1;
    int x_paddle_right = WIDTH - PADDLE_SIZE - 1;
    int y_paddle_right = HEIGHT - PADDLE_SIZE - 1;

    char direction = 'r';

    time_t start_time = time(NULL);

    while (!((x_ball >= WIDTH) || (x_ball <= 0) || (y_ball <= 0) || (y_ball >= HEIGHT)))
    {
        // Ball movement
        x_ball += direction * 2;
        y_ball--;

        // Paddle movement
        if (y_ball >= y_paddle_left)
        {
            direction = 'r';
            x_paddle_left++;
        }
        else if (y_ball <= y_paddle_right)
        {
            direction = 'l';
            x_paddle_left--;
        }

        // Draw the game
        system("clear");
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (x == x_ball && y == y_ball)
                {
                    printf("O");
                }
                else if (x == x_paddle_left && y == y_paddle_left)
                {
                    printf("P");
                }
                else if (x == x_paddle_right && y == y_paddle_right)
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

        // Sleep
        sleep(0.1);
    }

    time_t end_time = time(NULL);
    int time_taken = end_time - start_time;

    printf("Game over! You took %d seconds.", time_taken);

    return 0;
}