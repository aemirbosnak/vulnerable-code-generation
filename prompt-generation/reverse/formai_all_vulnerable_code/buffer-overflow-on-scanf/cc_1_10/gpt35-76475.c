//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

// Function prototypes
void print_board(char board[][COLS]);
bool mark_board(char board[][COLS], char symbol, int row, int col);
bool is_winner(char board[][COLS], char symbol);
bool is_board_full(char board[][COLS]);

int main()
{
    char board[ROWS][COLS] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player1 = 'X';
    char player2 = 'O';
    char current_player = player1;
    int row, col;

    printf("Welcome to C Table Game!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("--------------------\n");

    print_board(board);

    while (true) {
        // Get player's move
        printf("Player %c, enter row and column (e.g. 1 2): ", current_player);
        scanf("%d %d", &row, &col);

        // Check if move is valid
        if (!(row >= 1 && row <= 3 && col >= 1 && col <= 3)) {
            printf("Invalid move! Row and column must be between 1 and 3.\n");
            continue;
        }

        if (board[row-1][col-1] != ' ') {
            printf("Invalid move! That cell is already marked.\n");
            continue;
        }

        // Mark board and check if game is over
        if (!mark_board(board, current_player, row-1, col-1)) {
            printf("Invalid move! Row and column must be between 1 and 3.\n");
            continue;
        }

        if (is_winner(board, current_player)) {
            printf("Player %c wins!\n", current_player);
            print_board(board);
            break;
        }

        if (is_board_full(board)) {
            printf("Game over! It's a tie.\n");
            print_board(board);
            break;
        }

        print_board(board);

        // Switch players
        if (current_player == player1) {
            current_player = player2;
        } else {
            current_player = player1;
        }
    }

    return 0;
}

/**
 * Print the current state of the game board.
 */
void print_board(char board[][COLS])
{
    printf("\n");
    printf("  1   2   3\n");
    printf("1 %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf(" ---+---+---\n");
    printf("2 %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf(" ---+---+---\n");
    printf("3 %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

/**
 * Mark the cell at row/col with symbol.
 * Returns true if the move is valid, false otherwise.
 */
bool mark_board(char board[][COLS], char symbol, int row, int col)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }

    if (board[row][col] != ' ') {
        return false;
    }

    board[row][col] = symbol;

    return true;
}

/**
 * Check if the given symbol has won the game.
 */
bool is_winner(char board[][COLS], char symbol)
{
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }

    return false;
}

/**
 * Check if all cells are filled.
 */
bool is_board_full(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}