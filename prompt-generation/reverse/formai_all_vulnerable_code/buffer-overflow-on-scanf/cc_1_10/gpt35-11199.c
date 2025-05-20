//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLUMNS 3

void print_board(char board[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf(" %c ", board[i][j]);
            if (j != COLUMNS - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i != ROWS - 1) {
            printf("---+---+---\n");
        }
    }
}

bool update_board(char board[][COLUMNS], int row, int column, char player)
{
    if (board[row][column] != ' ') {
        printf("Invalid move! Please choose another cell.\n");
        return false;
    }
    board[row][column] = player;
    return true;
}

bool check_win(char board[][COLUMNS], char player)
{
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < COLUMNS; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool check_game_over(char board[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void clear_board(char board[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = ' ';
        }
    }
}

int main()
{
    char board[ROWS][COLUMNS];
    clear_board(board);
    int row, column;
    char player = 'X';
    bool game_over = false;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");

    do {
        print_board(board);
        printf("Player %c's turn. Please enter row and column (e.g. 1 1): ", player);
        scanf("%d %d", &row, &column);
        row--;
        column--;
        if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
            printf("Invalid input! Please choose a row and column within the board.\n");
            continue;
        }
        if (update_board(board, row, column, player)) {
            if (check_win(board, player)) {
                printf("\nCongratulations! Player %c wins!\n", player);
                game_over = true;
            } else if (check_game_over(board)) {
                printf("\nGame over! It's a draw!\n");
                game_over = true;
            } else {
                player = (player == 'X') ? 'O' : 'X';
            }
        }
    } while (!game_over);

    print_board(board);

    return 0;
}