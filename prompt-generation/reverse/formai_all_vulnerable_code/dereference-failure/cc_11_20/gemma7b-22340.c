//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main() {
    int **board = NULL;
    int i, j, k, l, r, c, alive = 0, dead = 0;

    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++) {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board with random values
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Calculate the number of alive and dead cells
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            alive = 0;
            dead = 0;
            // Check the neighbors of the current cell
            for (k = -1; k <= 1; k++) {
                for (l = -1; l <= 1; l++) {
                    // Check if the neighbor is alive
                    if (board[i + k][j + l] == 1) {
                        alive++;
                    }
                }
            }
            // Apply the Game of Life rules
            if (board[i][j] == 1 && alive < 2) {
                dead++;
            }
            else if (board[i][j] == 0 && alive == 3) {
                alive++;
            }
            board[i][j] -= dead;
            board[i][j] += alive;
        }
    }

    // Print the final board
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}