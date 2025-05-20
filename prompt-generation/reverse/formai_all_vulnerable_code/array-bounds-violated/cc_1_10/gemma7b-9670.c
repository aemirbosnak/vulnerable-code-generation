//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    // Game board
    int board[WIDTH][HEIGHT] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 1, 0, 1, 0},
                              {0, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0}};

    // Pac-Man position
    int pac_man_x = 0;
    int pac_man_y = 0;

    // Direction
    int dx = 1;
    int dy = 0;

    // Food position
    int food_x = 2;
    int food_y = 2;

    // Game loop
    while (!board[pac_man_x][pac_man_y])
    {
        // Move Pac-Man
        pac_man_x += dx;
        pac_man_y += dy;

        // Check if Pac-Man has eaten the food
        if (pac_man_x == food_x && pac_man_y == food_y)
        {
            // Eat the food
            board[pac_man_x][pac_man_y] = 0;

            // Generate new food position
            food_x = rand() % WIDTH;
            food_y = rand() % HEIGHT;
        }

        // Draw the game board
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                printf("%d ", board[x][y]);
            }
            printf("\n");
        }

        // Sleep
        sleep(1);
    }

    // Game over
    printf("Game over!");

    return 0;
}