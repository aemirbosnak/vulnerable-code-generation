//FormAI DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4   // Size of the memory game board
#define MAX_NUM 8      // Maximum number for each card value
#define MAX_GUESSES 15 // Maximum number of allowed guesses

/*
 * Struct to represent a single memory game card.
 */
typedef struct {
    int value;      // The number on the card
    int flipped;    // Whether the card is currently flipped over
    int matched;    // Whether the card has been matched with its pair
} Card;

/*
 * Helper function to print the current state of the game board.
 */
void print_board(Card board[][BOARD_SIZE]) {
    printf("\n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].matched) {
                printf("%2d", board[i][j].value);
            } else if (board[i][j].flipped) {
                printf("[]");
            } else {
                printf("  ");
            }
            printf(" ");
        }
        printf("\n");
    }
}

/*
 * Helper function to check whether all cards on the board have been matched.
 */
int all_matched(Card board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].matched) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // Initialize the game board with random card values
    Card board[BOARD_SIZE][BOARD_SIZE];
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].value = rand() % MAX_NUM + 1;
            board[i][j].flipped = 0;
            board[i][j].matched = 0;
        }
    }

    // Main game loop
    int num_guesses = 0;
    while (num_guesses < MAX_GUESSES && !all_matched(board)) {
        print_board(board);
        printf("\nGuess %d: ", num_guesses + 1);

        // Get user input for two card positions to flip over
        int pos1_i, pos1_j, pos2_i, pos2_j;
        scanf("%d %d %d %d", &pos1_i, &pos1_j, &pos2_i, &pos2_j);
        while (board[pos1_i][pos1_j].matched || board[pos2_i][pos2_j].matched ||
               (pos1_i == pos2_i && pos1_j == pos2_j)) {
            printf("Invalid input, please try again: ");
            scanf("%d %d %d %d", &pos1_i, &pos1_j, &pos2_i, &pos2_j);
        }

        // Flip over the selected cards and check for a match
        board[pos1_i][pos1_j].flipped = 1;
        board[pos2_i][pos2_j].flipped = 1;
        if (board[pos1_i][pos1_j].value == board[pos2_i][pos2_j].value) {
            board[pos1_i][pos1_j].matched = 1;
            board[pos2_i][pos2_j].matched = 1;
            printf("Match found!\n");
        } else {
            printf("No match found.\n");
            // Flip the cards back over if they don't match
            board[pos1_i][pos1_j].flipped = 0;
            board[pos2_i][pos2_j].flipped = 0;
        }

        num_guesses++;
    }

    // Print end game message
    print_board(board);
    if (all_matched(board)) {
        printf("\nCongratulations, you won in %d guesses!\n", num_guesses);
    } else {
        printf("\nSorry, you lost. Better luck next time!\n");
    }

    return 0;
}