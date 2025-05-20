//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the game board
char board[4][4];
int player_turn = 0;
int matches = 0;
int moves = 0;

// Initialize the game loop
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the game board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = rand() % 10 + '0';
        }
    }

    // Print the game board
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Start the game loop
    while (matches < 8) {
        // Get the player's input
        int row1, col1, row2, col2;
        printf("Player %d, enter the row and column of the first card: ", player_turn + 1);
        scanf("%d %d", &row1, &col1);
        printf("Player %d, enter the row and column of the second card: ", player_turn + 1);
        scanf("%d %d", &row2, &col2);

        // Check if the cards match
        if (board[row1][col1] == board[row2][col2]) {
            printf("Match!\n");
            matches++;
            moves++;
        } else {
            printf("No match.\n");
            moves++;
        }

        // Switch to the other player
        player_turn = (player_turn + 1) % 2;
    }

    // Print the game results
    printf("Game over!\n");
    printf("Player 1: %d matches in %d moves\n", matches, moves);
    printf("Player 2: %d matches in %d moves\n", matches, moves);

    return 0;
}