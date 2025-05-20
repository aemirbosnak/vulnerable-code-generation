//Gemma-7B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

int main()
{
    int x1 = WIDTH / 2, y1 = HEIGHT / 2, x2 = WIDTH / 2, y2 = HEIGHT - 1;
    int ball_x = WIDTH / 2, ball_y = HEIGHT / 2, direction = 1;

    time_t start, end;
    start = time(NULL);

    // Game loop
    while (time(NULL) - start < 30)
    {
        // Ball movement
        ball_x += direction * 2;
        if (ball_x >= WIDTH - 1 || ball_x <= 0)
            direction *= -1;

        // AI opponent movement
        if (ball_x > x1)
            x1++;
        else if (ball_x < x1)
            x1--;

        // Collision detection
        if (ball_x == x1 && ball_y == y1)
            direction *= -1;

        // Draw the screen
        system("clear");
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (x == x1 && y == y1)
                    printf("O ");
                else if (x == ball_x && y == ball_y)
                    printf("X ");
                else
                    printf(" ");
            }
            printf("\n");
        }

        // Sleep
        sleep(0.1);
    }

    end = time(NULL);
    printf("Time taken: %d seconds", end - start);

    return 0;
}