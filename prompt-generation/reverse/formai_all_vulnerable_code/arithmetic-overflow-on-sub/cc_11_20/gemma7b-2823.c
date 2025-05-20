//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

#define PACMAN_SIZE 3
#define FOOD_SIZE 2

int main()
{
    // Map representation
    int map[HEIGHT][WIDTH] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0},
                              {0, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0}};

    // Pac-Man position
    int pacman_x = 0;
    int pacman_y = 0;

    // Food position
    int food_x = 2;
    int food_y = 2;

    // Direction of movement
    int direction = 0;

    // Game loop flag
    int game_on = 1;

    // Clock speed
    int clock_speed = 100;

    // Game clock
    clock_t start_time = clock();

    // Main game loop
    while (game_on)
    {
        // Draw the map
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                if (map[y][x] == 1)
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

        // Draw Pac-Man
        printf("o");

        // Move Pac-Man
        switch (direction)
        {
            case 0:
                pacman_y--;
                break;
            case 1:
                pacman_x++;
                break;
            case 2:
                pacman_y++;
                break;
            case 3:
                pacman_x--;
                break;
        }

        // Check if Pac-Man has eaten the food
        if (pacman_x == food_x && pacman_y == food_y)
        {
            // Eat the food and generate new food position
            map[food_y][food_x] = 0;
            food_x = rand() % WIDTH;
            food_y = rand() % HEIGHT;
        }

        // Check if Pac-Man has hit a wall
        if (pacman_x < 0 || pacman_x >= WIDTH)
        {
            direction = 1;
        }
        if (pacman_y < 0 || pacman_y >= HEIGHT)
        {
            direction = 0;
        }

        // Sleep for a while
        clock_t end_time = clock();
        if (end_time - start_time >= clock_speed)
        {
            start_time = end_time;
            sleep(0.01);
        }
    }

    return 0;
}