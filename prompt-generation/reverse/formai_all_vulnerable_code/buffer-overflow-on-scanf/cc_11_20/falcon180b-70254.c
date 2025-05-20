//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 16

int main() {
    int board[ROWS][COLS];
    int x, y, matches = 0, attempts = 0;
    int card1, card2;
    int value;

    // Initialize the board with card values
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            board[y][x] = -1;
        }
    }

    // Shuffle the cards
    srand(time(NULL));
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            value = rand() % TOTAL_CARDS + 1;
            board[y][x] = value;
        }
    }

    // Print the initial board
    printf("Initial board:\n");
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            printf("%4d ", board[y][x]);
        }
        printf("\n");
    }

    // Main game loop
    while (matches < TOTAL_CARDS) {
        attempts++;

        // Get user input for card selection
        printf("Attempt %d:\n", attempts);
        printf("Select two cards:\n");
        scanf("%d %d", &card1, &card2);

        // Check if cards are valid
        if (card1 < 1 || card1 > TOTAL_CARDS || card2 < 1 || card2 > TOTAL_CARDS) {
            printf("Invalid card selection.\n");
            continue;
        }

        // Flip the selected cards
        if (board[card1 - 1][0] == -1 || board[card2 - 1][0] == -1) {
            printf("Card already selected.\n");
            continue;
        }

        if (board[card1 - 1][0] == board[card2 - 1][0]) {
            matches++;
            printf("Match!\n");
        } else {
            printf("Mismatch.\n");
            board[card1 - 1][0] = -1;
            board[card2 - 1][0] = -1;
        }

        // Check if game is over
        if (matches == TOTAL_CARDS) {
            printf("Congratulations! You won in %d attempts.\n", attempts);
            break;
        }
    }

    return 0;
}