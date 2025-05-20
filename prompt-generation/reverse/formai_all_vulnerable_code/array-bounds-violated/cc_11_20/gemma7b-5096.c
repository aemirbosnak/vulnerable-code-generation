//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[20][20] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int i, j, k, l, r, c, alive = 0, dead = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Create a random number of live cells
    for (k = 0; k < 10; k++) {
        i = rand() % 20;
        j = rand() % 20;
        board[i][j] = 1;
    }

    // Simulate the Game of Life
    for (r = 0; r < 20; r++) {
        for (c = 0; c < 20; c++) {
            alive = 0;
            dead = 0;

            // Check the neighbors of the current cell
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    if (board[r + k][c + l] == 1) {
                        alive++;
                    }
                }
            }

            // Apply the Game of Life rules
            if (board[r][c] == 1) {
                if (alive < 2) {
                    dead = 1;
                }
            } else {
                if (alive == 3) {
                    alive = 1;
                }
            }

            // Update the cell's state
            if (dead) {
                board[r][c] = 0;
            } else if (alive) {
                board[r][c] = 1;
            }
        }
    }

    // Print the final board
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}