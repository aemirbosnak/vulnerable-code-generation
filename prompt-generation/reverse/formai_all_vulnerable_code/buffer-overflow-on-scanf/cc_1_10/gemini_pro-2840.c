//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 4
#define MAX_COLS 4
#define MAX_CARDS (MAX_ROWS * MAX_COLS)

typedef struct {
    int value;
    int revealed;
} Card;

void print_board(const Card board[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (board[i][j].revealed) {
                printf("%2d ", board[i][j].value);
            } else {
                printf("## ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Create the game board.
    Card board[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j].value = (i * MAX_ROWS) + j + 1;
            board[i][j].revealed = 0;
        }
    }

    // Shuffle the cards.
    for (int i = 0; i < MAX_CARDS; i++) {
        int a = rand() % MAX_CARDS;
        int b = rand() % MAX_CARDS;
        Card temp = board[a / MAX_COLS][a % MAX_ROWS];
        board[a / MAX_COLS][a % MAX_ROWS] = board[b / MAX_COLS][b % MAX_ROWS];
        board[b / MAX_COLS][b % MAX_ROWS] = temp;
    }

    // Play the game.
    int first_card_row = -1;
    int first_card_col = -1;
    int second_card_row = -1;
    int second_card_col = -1;
    int matches = 0;
    int guesses = 0;

    while (matches < MAX_CARDS / 2) {
        // Get the first card.
        printf("Guess a card (row, column): ");
        scanf("%d %d", &first_card_row, &first_card_col);

        // Check if the first card is valid.
        if (first_card_row < 0 || first_card_row >= MAX_ROWS ||
            first_card_col < 0 || first_card_col >= MAX_COLS ||
            board[first_card_row][first_card_col].revealed) {
            printf("Invalid card. Please try again.\n");
        } else {
            // Reveal the first card.
            board[first_card_row][first_card_col].revealed = 1;

            // Get the second card.
            printf("Guess another card (row, column): ");
            scanf("%d %d", &second_card_row, &second_card_col);

            // Check if the second card is valid.
            if (second_card_row < 0 || second_card_row >= MAX_ROWS ||
                second_card_col < 0 || second_card_col >= MAX_COLS ||
                board[second_card_row][second_card_col].revealed) {
                printf("Invalid card. Please try again.\n");
            } else {
                // Reveal the second card.
                board[second_card_row][second_card_col].revealed = 1;

                // Check if the cards match.
                if (board[first_card_row][first_card_col].value ==
                    board[second_card_row][second_card_col].value) {
                    printf("Match!\n");
                    matches++;
                } else {
                    printf("No match.\n");
                }

                // Increment the number of guesses.
                guesses++;

                // Print the board.
                print_board(board);
            }
        }
    }

    // Print the final results.
    printf("Congratulations! You found all the matches in %d guesses.\n", guesses);

    return 0;
}