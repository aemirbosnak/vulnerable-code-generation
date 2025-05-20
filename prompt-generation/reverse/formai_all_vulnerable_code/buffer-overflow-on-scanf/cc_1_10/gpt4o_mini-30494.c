//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE) / 2
#define HIDE_CHAR 'X'

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE], char symbols[NUM_PAIRS]);
void shuffle_symbols(char symbols[NUM_PAIRS]);
void display_board(char board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE]);
int get_user_input(int *row, int *col);
int check_match(char board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2);
void reveal_tiles(char board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2);
void hide_tiles(int revealed[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2);
int all_pairs_found(int revealed[BOARD_SIZE][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char symbols[NUM_PAIRS];
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0};  // 0 = hidden, 1 = revealed

    // Initialize symbols for the game
    for (int i = 0; i < NUM_PAIRS; i++) {
        symbols[i] = 'A' + i;  // Use letters A-Z for symbols
    }

    // Shuffle and initialize the board
    shuffle_symbols(symbols);
    initialize_board(board, symbols);

    printf("Welcome to the Memory Game!\n\n");

    while (!all_pairs_found(revealed)) {
        display_board(board, revealed);

        int row1, col1, row2, col2;

        printf("Select the first tile: ");
        if (!get_user_input(&row1, &col1)) continue;

        revealed[row1][col1] = 1;  // reveal first tile
        display_board(board, revealed);

        printf("Select the second tile: ");
        if (!get_user_input(&row2, &col2)) {
            revealed[row1][col1] = 0;  // hide first tile if invalid second selection
            continue;
        }

        revealed[row2][col2] = 1;  // reveal second tile
        display_board(board, revealed);

        if (!check_match(board, row1, col1, row2, col2)) {
            printf("No match! Hiding tiles...\n");
            sleep(1);
            hide_tiles(revealed, row1, col1, row2, col2);
        } else {
            printf("You found a match!\n");
        }
    }

    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}

// Initializing the board with shuffled symbols
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE], char symbols[NUM_PAIRS]) {
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = symbols[index / 2];
            index++;
        }
    }
}

// Shuffling the symbols randomly
void shuffle_symbols(char symbols[NUM_PAIRS]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_PAIRS; i++) {
        int j = rand() % NUM_PAIRS;
        char temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
}

// Display the board based on revealed tiles
void display_board(char board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nBoard:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" %c ", HIDE_CHAR);
            }
        }
        printf("\n");
    }
}

// Function to read user input for row and column
int get_user_input(int *row, int *col) {
    if (scanf("%d %d", row, col) != 2 || *row < 0 || *row >= BOARD_SIZE || *col < 0 || *col >= BOARD_SIZE) {
        printf("Invalid input. Please enter valid coordinates between 0 and %d.\n", BOARD_SIZE - 1);
        while(getchar() != '\n');  // clear input buffer
        return 0;
    }
    return 1;
}

// Check if the selected tiles match
int check_match(char board[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}

// Reveal the tiles chosen by the player
void reveal_tiles(char board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    revealed[row1][col1] = 1;
    revealed[row2][col2] = 1;
}

// Hide the tiles that don't match
void hide_tiles(int revealed[BOARD_SIZE][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    revealed[row1][col1] = 0;
    revealed[row2][col2] = 0;
}

// Check if all pairs are found
int all_pairs_found(int revealed[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!revealed[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}