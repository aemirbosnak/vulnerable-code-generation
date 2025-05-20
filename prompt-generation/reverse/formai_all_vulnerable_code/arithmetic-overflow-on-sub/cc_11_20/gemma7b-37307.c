//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 0
#define RIGHT 1
#define DOWN 2
#define UP 3

int main() {
    // Define the game board
    int board[5][5] = {{0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0}};

    // Initialize the invader's position
    int invader_x = 0;
    int invader_y = 0;

    // Initialize the invader's direction
    int invader_dir = RIGHT;

    // Initialize the bullet's position
    int bullet_x = -1;
    int bullet_y = -1;

    // Initialize the game clock
    time_t start_time = time(NULL);

    // Game loop
    while (!board[invader_y][invader_x] && time(NULL) - start_time < 60) {
        // Move the invader
        switch (invader_dir) {
            case LEFT:
                invader_x--;
                break;
            case RIGHT:
                invader_x++;
                break;
            case DOWN:
                invader_y++;
                break;
            case UP:
                invader_y--;
                break;
        }

        // Check if the invader has reached the border
        if (invader_x < 0 || invader_x >= 4) {
            invader_dir = DOWN;
        }

        // Check if the invader has reached the bottom of the board
        if (invader_y >= 4) {
            board[invader_y][invader_x] = 1;
            break;
        }

        // Fire the bullet
        if (bullet_x == -1 && bullet_y == -1) {
            bullet_x = invader_x;
            bullet_y = invader_y;
        }

        // Move the bullet
        bullet_x++;

        // Check if the bullet has hit the invader
        if (board[bullet_y][bullet_x] == 1) {
            board[bullet_y][bullet_x] = 0;
            bullet_x = -1;
            bullet_y = -1;
        }

        // Draw the game board
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                printf("%d ", board[y][x]);
            }
            printf("\n");
        }

        // Sleep for a bit
        sleep(0.1);
    }

    // Game over
    printf("Game over!");
    return 0;
}