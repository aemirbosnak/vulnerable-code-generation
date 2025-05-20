//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int main() {
    // Declare game board
    int board[ROWS][COLS] = {{0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    // Place the breakout paddle
    board[2][2] = 1;

    // Game loop
    while (1) {

        // Print the board
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Get the user input
        int x, y;
        printf("Enter the coordinates of the ball (x, y): ");
        scanf("%d %d", &x, &y);

        // Move the ball
        board[x][y] = 1;

        // Check if the ball has broken out
        if (board[0][y] == 1) {
            printf("You win!");
            break;
        }

        // Check if the ball has hit a wall
        if (board[x][0] == 1 || board[x][COLS - 1] == 1) {
            board[x][y] = 0;
        }

        // Check if the ball has reached the paddle
        if (board[x][2] == 1) {
            board[x][y] = 0;
        }
    }

    return 0;
}