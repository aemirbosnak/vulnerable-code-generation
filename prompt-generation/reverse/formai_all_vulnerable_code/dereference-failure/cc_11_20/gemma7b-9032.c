//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 5
#define BALL_SIZE 2

int main()
{
    // Map creation
    int **map = (int **)malloc(MAP_SIZE * sizeof(int *));
    for (int i = 0; i < MAP_SIZE; i++)
    {
        map[i] = (int *)malloc(MAP_SIZE * sizeof(int));
    }

    // Ball position
    int ball_x = 0;
    int ball_y = 0;

    // Ball direction
    int ball_dx = 1;
    int ball_dy = 1;

    // Border collision detection
    int border_collision = 0;

    // Game loop
    while (!border_collision)
    {
        // Draw the map
        for (int i = 0; i < MAP_SIZE; i++)
        {
            for (int j = 0; j < MAP_SIZE; j++)
            {
                if (map[i][j] == 1)
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Move the ball
        ball_x += ball_dx;
        ball_y += ball_dy;

        // Border collision check
        if (ball_x >= MAP_SIZE - BALL_SIZE || ball_x < 0)
        {
            ball_dx *= -1;
            border_collision = 1;
        }
        if (ball_y >= MAP_SIZE - BALL_SIZE || ball_y < 0)
        {
            ball_dy *= -1;
            border_collision = 1;
        }

        // Update the map
        map[ball_x][ball_y] = 1;

        // Sleep for 50 milliseconds
        sleep(0.05);
    }

    // Free the memory
    for (int i = 0; i < MAP_SIZE; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}