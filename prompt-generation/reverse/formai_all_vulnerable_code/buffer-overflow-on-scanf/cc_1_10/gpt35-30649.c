//FormAI DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Define the board as a 2D array
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's turn (1 for player 1, 2 for player 2)
int player_turn = 1;

// Define function to initialize the board
void init_board() {
    // Set all board cells to ' '
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Set pieces for player 1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                board[i][j] = 'O';
            }
        }
    }

    // Set pieces for player 2
    for (int i = BOARD_SIZE - 1; i >= BOARD_SIZE - 3; i--) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                board[i][j] = 'X';
            }
        }
    }
}

// Define function to print the board
void print_board() {
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  +---------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
        printf("  +---------------+\n");
    }
}

// Define function to move a piece
void move_piece(int from_row, int from_col, int to_row, int to_col) {
    // Check if the move is valid
    if (board[to_row][to_col] == ' ' && abs(from_row - to_row) == 1 && abs(from_col - to_col) == 1) {
        // Move piece
        board[to_row][to_col] = board[from_row][from_col];
        board[from_row][from_col] = ' ';
    }
}

int main() {
    // Initialize the board
    init_board();

    // Play the game
    int game_in_progress = 1;
    while (game_in_progress) {
        // Print the board
        print_board();

        // Get move from player
        int from_row, from_col, to_row, to_col;
        printf("Player %d, enter your move (from_row from_col to_row to_col): ", player_turn);
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);

        // Move the piece
        move_piece(from_row, from_col, to_row, to_col);

        // Switch player turn
        player_turn = (player_turn == 1) ? 2 : 1;
    }

    return 0;
}