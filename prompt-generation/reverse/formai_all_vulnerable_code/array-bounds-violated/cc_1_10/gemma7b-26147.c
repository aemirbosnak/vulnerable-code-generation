//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3
#define EMPTY_CHAR ' '
#define PLAYER_CHAR 'X'
#define COMPUTER_CHAR 'O'

int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_CHAR, EMPTY_CHAR, EMPTY_CHAR},
                              {EMPTY_CHAR, EMPTY_CHAR, EMPTY_CHAR},
                              {EMPTY_CHAR, EMPTY_CHAR, EMPTY_CHAR}};

int isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_CHAR) {
                return 0;
            }
        }
    }
    return 1;
}

int hasPlayerWon(char playerChar) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == playerChar && board[i][1] == playerChar && board[i][2] == playerChar) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == playerChar && board[1][j] == playerChar && board[2][j] == playerChar) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == playerChar && board[1][1] == playerChar && board[2][2] == playerChar) {
        return 1;
    }
    if (board[0][2] == playerChar && board[1][1] == playerChar && board[2][0] == playerChar) {
        return 1;
    }

    return 0;
}

void placePiece(char playerChar, int row, int col) {
    if (board[row][col] != EMPTY_CHAR) {
        return;
    }

    board[row][col] = playerChar;
}

int main() {
    char currentPlayer = PLAYER_CHAR;
    int gameWon = 0;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CHAR;
        }
    }

    // Game loop
    while (!gameWon && !isBoardFull()) {
        // Get the player's move
        int row = 0;
        int col = 0;
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);

        // Place the piece
        placePiece(currentPlayer, row, col);

        // Check if the player has won
        gameWon = hasPlayerWon(currentPlayer);

        // Switch to the next player
        currentPlayer = (currentPlayer == PLAYER_CHAR) ? COMPUTER_CHAR : PLAYER_CHAR;
    }

    // Game over
    if (gameWon) {
        printf("Congratulations! You won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}