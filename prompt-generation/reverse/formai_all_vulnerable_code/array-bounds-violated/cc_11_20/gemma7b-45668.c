//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 10

#define LEFT 0
#define RIGHT 1
#define DOWN 2
#define UP 3

int main() {

    // Define game variables
    int x = 0, y = 0, direction = RIGHT, speed = 1, aliens_alive = 10;
    char board[ROWS][COLS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Initialize alien positions
    for (int i = 0; i < aliens_alive; i++) {
        board[y][x] = 'A' + i;
        x++;
    }

    // Game loop
    while (aliens_alive) {

        // Move aliens
        switch (direction) {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case DOWN:
                y++;
                break;
            case UP:
                y--;
                break;
        }

        // Check if aliens have reached the edge of the board
        if (x < 0 || x >= COLS) {
            direction *= -1;
        }

        // Check if aliens have reached the bottom of the board
        if (y >= ROWS - 1) {
            aliens_alive = 0;
        }

        // Draw the board
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Check if the player has shot an alien
        if (board[y][x] == 'A') {
            board[y][x] = 0;
            aliens_alive--;
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();
    }

    // Game over message
    printf("Game over! You survived for %d rounds.", aliens_alive);

    return 0;
}