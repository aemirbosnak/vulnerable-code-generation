//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_SQUARES (BOARD_SIZE * BOARD_SIZE)
#define MAX_TURNS 9

// Function prototypes
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int is_board_full(char board[BOARD_SIZE][BOARD_SIZE]);
int is_game_won(char board[BOARD_SIZE][BOARD_SIZE], char player);
int is_move_valid(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);
void make_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    int row, col;

    // Game loop
    for (int turn = 0; turn < MAX_TURNS; turn++) {
        // Print the current board
        print_board(board);

        // Get the move from the user
        printf("Enter row and column for your move: ");
        scanf("%d %d", &row, &col);

        // Make the move
        make_move(board, row, col, player);

        // Check if the game is won
        if (is_game_won(board, player)) {
            printf("Player %c wins!\n", player);
            break;
        }

        // Check if the board is full
        if (is_board_full(board)) {
            printf("It's a tie!\n");
            break;
        }

        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_board_full(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int is_game_won(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int is_move_valid(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ');
}

void make_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player) {
    if (is_move_valid(board, row, col)) {
        board[row][col] = player;
    }
}