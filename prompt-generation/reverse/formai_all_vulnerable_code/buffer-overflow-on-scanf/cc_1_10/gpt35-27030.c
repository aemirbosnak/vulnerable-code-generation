//FormAI DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define game board size
#define BOARD_SIZE 3

// Define player markers
#define EMPTY ' '
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// Define function to print game board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("-------------\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| ");

        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c | ", board[i][j]);
        }

        printf("\n-------------\n");
    }
}

// Define function to check if board has been fully played
int board_full(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }

    return 1;
}

// Define function to check if there is a winner
char check_win(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY) {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY) {
        return board[0][2];
    }

    // If no winner, check if board is full
    if (board_full(board)) {
        return 'T'; // Tie
    }

    // Otherwise, return null character
    return '\0';
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int row, col, turn = 1;
    char winner = '\0';

    // Initialize board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Print empty board
    print_board(board);

    // Game loop
    while (winner == '\0') {
        // Get user input
        printf("Player %d's turn (row col): ", turn);
        scanf("%d %d", &row, &col);

        // Check if input is valid
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Update board with player's marker
        board[row][col] = turn == 1 ? PLAYER_1 : PLAYER_2;

        // Print updated board
        print_board(board);

        // Check if there is a winner
        winner = check_win(board);

        // Switch turn
        turn = turn == 1 ? 2 : 1;
    }

    // Print winner or tie message
    if (winner == 'T') {
        printf("It's a tie!\n");
    } else {
        printf("Player %c wins!\n", winner);
    }

    return 0;
}