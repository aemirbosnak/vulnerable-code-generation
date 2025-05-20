//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

void draw_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    int i, j;

    // Initialize the board with random numbers
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 10;
        }
    }

    // Print the initial board
    draw_board(board);

    // Get input from the player
    int choice_row, choice_col;
    printf("Enter the row and column of the card you want to flip: ");
    scanf("%d %d", &choice_row, &choice_col);

    // Check if the input is valid
    if (choice_row >= 0 && choice_row < ROWS && choice_col >= 0 && choice_col < COLS) {
        // Flip the card
        char card = board[choice_row][choice_col];
        board[choice_row][choice_col] = '*';
        int card_value = card - '0';
        printf("You flipped card %d\n", card_value);

        // Check for a match
        int match_found = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == card) {
                    match_found = 1;
                    break;
                }
            }
            if (match_found) {
                break;
            }
        }

        // If a match is found, keep the cards flipped
        if (match_found) {
            draw_board(board);
            printf("Match found! Try again.\n");
        } else {
            // Otherwise, flip the cards back
            board[choice_row][choice_col] = card;
            draw_board(board);
            printf("No match found. Try again.\n");
        }
    } else {
        printf("Invalid input. Try again.\n");
    }

    return 0;
}