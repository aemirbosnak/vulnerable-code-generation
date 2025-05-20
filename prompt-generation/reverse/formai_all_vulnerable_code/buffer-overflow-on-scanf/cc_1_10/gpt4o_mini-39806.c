//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4
#define TOTAL_CARDS (SIZE * SIZE)
#define MAX_ATTEMPTS 3

void initialize_board(char board[SIZE][SIZE], char symbols[TOTAL_CARDS]) {
    int symbol_index = 0;
    for (int i = 0; i < TOTAL_CARDS / 2; ++i) {
        char symbol = 'A' + i; // Generate letters A, B, C...
        symbols[symbol_index++] = symbol;
        symbols[symbol_index++] = symbol; // Two of each symbol
    }

    for (int i = 0; i < TOTAL_CARDS; ++i) {
        int r = rand() % TOTAL_CARDS;
        char temp = symbols[i];
        symbols[i] = symbols[r];
        symbols[r] = temp; // Shuffle symbols
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = '*'; // Hide cards with '*'
        }
    }
}

void print_board(char board[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int get_card_position(int *row, int *col) {
    int input;

    printf("Select a card (row and column as 'row col'): ");
    if (scanf("%d %d", row, col) != 2 || *row < 0 || *row >= SIZE || 
        *col < 0 || *col >= SIZE) {
        printf("Invalid input! Please provide valid row and column.\n");
        while (getchar() != '\n'); // Clear the buffer
        return 0;
    }
    return 1;
}

void reveal_card(char board[SIZE][SIZE], char symbols[TOTAL_CARDS], int row, int col) {
    board[row][col] = symbols[row * SIZE + col];
}

int cards_match(char board[SIZE][SIZE], char symbols[TOTAL_CARDS], int first_row, int first_col, int second_row, int second_col) {
    return symbols[first_row * SIZE + first_col] == symbols[second_row * SIZE + second_col];
}

int main() {
    srand(time(0)); // Seed for randomness
    char board[SIZE][SIZE];
    char symbols[TOTAL_CARDS];

    initialize_board(board, symbols);
    
    int uncovered = 0, attempts = MAX_ATTEMPTS;
    while (uncovered < TOTAL_CARDS) {
        print_board(board);
        printf("Attempts remaining: %d\n", attempts);

        int first_row, first_col, second_row, second_col;
        if (!get_card_position(&first_row, &first_col)) continue;

        reveal_card(board, symbols, first_row, first_col);
        print_board(board);

        if (!get_card_position(&second_row, &second_col) || (first_row == second_row && first_col == second_col)) {
            printf("Invalid second choice! You lose the attempt.\n");
            board[first_row][first_col] = '*'; // Hide the card again
            continue; // Retry
        }

        reveal_card(board, symbols, second_row, second_col);
        print_board(board);

        if (cards_match(board, symbols, first_row, first_col, second_row, second_col)) {
            printf("Match found!\n");
            uncovered += 2; // Two cards uncovered
        } else {
            printf("No match! Hiding the cards.\n");
            sleep(1); // Wait a moment before hiding
            board[first_row][first_col] = '*';
            board[second_row][second_col] = '*';
            attempts--;
        }

        if (attempts <= 0) {
            printf("You've run out of attempts! Game Over!\n");
            break;
        }
    }

    if (uncovered == TOTAL_CARDS) {
        printf("Congratulations! You've matched all the cards!\n");
    }

    return 0;
}