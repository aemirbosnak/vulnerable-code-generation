//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 4
#define NUM_COLS 4
#define NUM_CARDS 8

enum {
    EMPTY = 0,
    HIDDEN = 1,
    REVEALED = 2
};

void init_board(int board[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void shuffle_deck(int deck[NUM_CARDS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(int deck[NUM_CARDS], int board[NUM_ROWS][NUM_COLS]) {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        int row = rand() % NUM_ROWS;
        int col = rand() % NUM_COLS;
        while (board[row][col]!= EMPTY) {
            row = rand() % NUM_ROWS;
            col = rand() % NUM_COLS;
        }
        board[row][col] = deck[i];
    }
}

void print_board(int board[NUM_ROWS][NUM_COLS]) {
    int i, j;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            if (board[i][j] == EMPTY) {
                printf("-");
            } else {
                printf("X");
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int deck[NUM_CARDS];
    int board[NUM_ROWS][NUM_COLS];
    int i;

    // Initialize the deck
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i] = i + 1;
    }

    // Shuffle the deck
    shuffle_deck(deck);

    // Deal the cards
    deal_cards(deck, board);

    // Print the initial board
    printf("Initial board:\n");
    print_board(board);

    // Play the game
    int player_row, player_col;
    int matches = 0;
    while (matches < NUM_CARDS) {
        printf("Enter row and column to flip: ");
        scanf("%d%d", &player_row, &player_col);
        if (player_row >= 0 && player_row < NUM_ROWS && player_col >= 0 && player_col < NUM_COLS) {
            if (board[player_row][player_col] == EMPTY) {
                printf("Error: Card not found!\n");
            } else if (board[player_row][player_col] == deck[matches]) {
                board[player_row][player_col] = REVEALED;
                matches++;
                printf("Match found!\n");
            } else {
                board[player_row][player_col] = HIDDEN;
                printf("No match.\n");
            }
        } else {
            printf("Error: Invalid input!\n");
        }
    }

    // Print the final board
    printf("\nFinal board:\n");
    print_board(board);

    return 0;
}