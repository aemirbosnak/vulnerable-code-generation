//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8
#define MATCH_POINTS 10
#define MISMATCH_POINTS -5

int main() {
    srand(time(0)); // Seed the random number generator
    int board[ROWS][COLS]; // 2D array to store the cards
    int points = 0; // Points earned by the player
    int matches = 0; // Number of matches made by the player
    int card1, card2; // Variables to store the cards

    // Initialize the board with random cards
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % TOTAL_CARDS + 1; // Each card has a value from 1 to 8
        }
    }

    // Print the initial board
    printf("Initial board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Main game loop
    while (1) {
        // Ask the player to choose two cards
        printf("Choose two cards:\n");
        scanf("%d %d", &card1, &card2);

        // Check if the cards are valid
        if (card1 < 1 || card1 > TOTAL_CARDS || card2 < 1 || card2 > TOTAL_CARDS) {
            printf("Invalid cards!\n");
            continue;
        }

        // Check if the cards match
        if (board[card1 - 1][card2 - 1] == board[card1 - 1][card1 - 1]) {
            matches++;
            points += MATCH_POINTS;
        } else {
            printf("Mismatch!\n");
            points += MISMATCH_POINTS;
        }

        // Flip the cards back
        board[card1 - 1][card2 - 1] = 0;
        board[card1 - 1][card1 - 1] = 0;

        // Check if the game is over
        if (matches == TOTAL_CARDS / 2) {
            printf("You won! Your score is %d.\n", points);
            break;
        } else if (matches + 2 * MISMATCH_POINTS == TOTAL_CARDS / 2) {
            printf("You lost! Your score is %d.\n", points);
            break;
        }
    }

    return 0;
}