//Falcon2-11B DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Define the game board
    int board[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    // Game loop
    while (1) {
        // Print the game board
        printf("---------\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%2d ", board[i][j]);
            }
            printf("|");
        }
        printf("---------\n");

        // Get player input
        char player_input;
        printf("Player 1: Enter a number from 1 to 9: ");
        scanf(" %c", &player_input);
        if (player_input >= '1' && player_input <= '9') {
            // Check if the input is valid
            int row = player_input - '0';
            int col = player_input - '1';
            if (row < 0 || row > 2 || col < 0 || col > 2) {
                printf("Invalid input!\n");
            } else {
                // Update the game board
                board[row][col] = 1;

                // Check for a winner
                int count_ones = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[i][j] == 1) {
                            count_ones++;
                        }
                    }
                }
                if (count_ones == 9) {
                    printf("Player 1 wins!\n");
                    break;
                }
            }
        }

        // Get computer input
        if (board[0][0] == 0) {
            int row = rand() % 3;
            int col = rand() % 3;
            board[row][col] = 1;
        }

        // Print the game board again
        printf("---------\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%2d ", board[i][j]);
            }
            printf("|");
        }
        printf("---------\n");

        // Check for a draw
        int count_zeros = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    count_zeros++;
                }
            }
        }
        if (count_zeros == 9) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}