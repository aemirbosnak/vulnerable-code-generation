//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

int main() {
    // Initialize the game board
    char board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = ' ';
        }
    }

    // Initialize the players
    char player1 = 'X';
    char player2 = 'O';

    // Initialize the turn
    char turn = player1;

    // Game loop
    while (1) {
        // Print the board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Get the player's move
        int row, col;
        printf("Player %c, enter your move (row, col): ", turn);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 0 || row >= N || col < 0 || col >= N || board[row][col] != ' ') {
            printf("Invalid move, try again.\n");
            continue;
        }

        // Place the player's piece on the board
        board[row][col] = turn;

        // Check if the game is over
        if (check_game_over(board)) {
            break;
        }

        // Switch turns
        turn = (turn == player1) ? player2 : player1;
    }

    // Print the final board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function to check if the game is over
int check_game_over(char board[N][N]) {
    // Check rows
    for (int i = 0; i < N; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < N; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    // Check if the board is full
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    // It's a tie
    return -1;
}