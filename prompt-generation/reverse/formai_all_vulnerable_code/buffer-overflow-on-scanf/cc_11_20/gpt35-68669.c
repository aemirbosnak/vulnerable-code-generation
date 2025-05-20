//FormAI DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Function to check if a player has won the game
int check_win(char board[ROWS][COLS], char symbol) {
    for (int i = 0; i < ROWS; i++) {
        // Check horizontal win
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
        // Check vertical win
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    // Check diagonal win
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    return 0;
}

// Function to print the game board
void print_board(char board[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
            if (j < COLS - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < ROWS - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int main() {
    // Initialize the game board
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    // Randomly select which player goes first
    srand(time(NULL));
    int turn = rand() % 2;
    char player = turn == 0 ? 'X' : 'O';

    printf("Welcome to Tic Tac Toe\n\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n\n");

    while (1) {
        // Print the game board
        print_board(board);

        // Check if the game is a tie
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] != ' ') {
                    count++;
                }
            }
        }
        if (count == ROWS * COLS) {
            printf("The game is a tie!\n");
            break;
        }

        // Get the player's move
        int row, col;
        if (turn == 0) {
            printf("Player 1's turn (X)\n");
        } else {
            printf("Player 2's turn (O)\n");
        }
        printf("Enter the row (1-3) and column (1-3) separated by a space: ");
        scanf("%d %d", &row, &col);

        // Check if move is valid and update the board
        if (row > 0 && row <= ROWS && col > 0 && col <= COLS && board[row-1][col-1] == ' ') {
            board[row-1][col-1] = player;
            if (check_win(board, player)) {
                print_board(board);
                if (turn == 0) {
                    printf("Player 1 (X) wins!\n");
                } else {
                    printf("Player 2 (O) wins!\n");
                }
                break;
            }
            // Switch to the other player's turn
            turn = turn == 0 ? 1 : 0;
            player = turn == 0 ? 'X' : 'O';
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}