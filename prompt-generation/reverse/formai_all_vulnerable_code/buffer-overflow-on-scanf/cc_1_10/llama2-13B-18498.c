//LLAMA2-13B DATASET v1.0 Category: Checkers Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
const int BOARD_SIZE = 8;
const int PIECE_SIZE = 2;
const int MAX_PLAYERS = 2;
const int WIN_CONDITION = 12;

// Function declarations
void init_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
void make_move(char board[BOARD_SIZE][BOARD_SIZE], int x, int y);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], int player);

// Function implementations

// Initializes the board with random pieces
void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = (i % 2 == 0) ? 'X' : 'O';
        }
    }
}

// Prints the current board state
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Makes a move on the board
void make_move(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    if (board[x][y] == ' ') {
        board[x][y] = (x % 2 == 0) ? 'X' : 'O';
    } else {
        printf("Error: invalid move\n");
    }
}

// Checks if a player has won
int check_win(char board[BOARD_SIZE][BOARD_SIZE], int player) {
    int rows = 0;
    int cols = 0;

    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            rows++;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            cols++;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        rows++;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        cols++;
    }

    // Check if a player has won
    if (rows == BOARD_SIZE || cols == BOARD_SIZE) {
        return player;
    }

    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 0;

    // Initialize the board
    init_board(board);

    // Print the board
    print_board(board);

    // Game loop
    while (1) {
        // Ask the player for a move
        printf("Your move (row, column): ");
        int x, y;
        scanf("%d%d", &x, &y);

        // Make the move
        make_move(board, x, y);

        // Check if the game is over
        if (check_win(board, player)) {
            break;
        }

        // Switch players
        player = player == 0 ? 1 : 0;
    }

    // Print the final board
    print_board(board);

    return 0;
}