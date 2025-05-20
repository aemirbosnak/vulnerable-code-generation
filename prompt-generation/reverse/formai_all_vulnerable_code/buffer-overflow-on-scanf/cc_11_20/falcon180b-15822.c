//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4
#define NUM_CARDS (ROWS * COLS)

int main() {
    int i, j, k, x, y, matches = 0;
    char board[ROWS][COLS];
    char *card_values = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    srand(time(NULL));

    // Initialize the board with random cards
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = card_values[rand() % 26];
        }
    }

    // Print the initial board
    printf("Initial Board:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }

    while (matches < NUM_CARDS) {
        // Get user input for row and column
        printf("\nEnter row and column for first card: ");
        scanf("%d%d", &x, &y);

        // Check if card is on the board
        if (x >= ROWS || y >= COLS || x < 0 || y < 0) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Check if card is already matched
        if (board[x][y] == '*') {
            printf("Card already matched. Try again.\n");
            continue;
        }

        // Check if card matches previously revealed card
        int match_found = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j]!= '*' && board[i][j] == board[x][y]) {
                    match_found = 1;
                    break;
                }
            }
            if (match_found) {
                break;
            }
        }

        if (!match_found) {
            printf("No match found. Card turned back over.\n");
            board[x][y] = '*';
        } else {
            printf("Match found!\n");
            board[i][j] = '*';
            matches++;
        }
    }

    printf("\nCongratulations! You matched all the cards in %d turns.\n", matches);

    return 0;
}