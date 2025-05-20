//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

// Function to print the Tic Tac Toe board
void print_board(char board[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
            if (j < COLS - 1)
                printf("|");
        }
        printf("\n");

        if (i < ROWS - 1) {
            for (j = 0; j < COLS; j++) {
                printf("---+");
                if (j < COLS - 1)
                    printf("---");
            }
            printf("\n");
        }
    }
}

// Function to check if a given cell is empty or not
int is_empty(char board[ROWS][COLS], int row, int col) {
    return board[row][col] == '\0';
}

// Function to check if a given player has won the game
int check_win(char board[ROWS][COLS], char player) {
    int i, j;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // Check columns
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

int main() {
    char board[ROWS][COLS];
    int row, col, player = 'X';

    // Initialize the board with empty cells
    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            board[row][col] = '\0';

    while (1) {
        print_board(board);

        do {
            printf("\nPlayer %c, enter the row and column: ", player);
            scanf("%d%d", &row, &col);

            row--;
            col--; // Adjust for 1-based indexing
        } while (!is_empty(board, row, col));

        board[row][col] = player;

        if (check_win(board, player)) {
            print_board(board);
            printf("\nPlayer %c wins!\n", player);
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}