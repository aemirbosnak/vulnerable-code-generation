//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
}

int isWinner(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int isDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) return 0;
        }
    }
    return 1;
}

void playerMove(char board[SIZE][SIZE], char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE]) {
    int row, col;
    // Simple AI: choose the first available spot
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == EMPTY) {
                board[row][col] = PLAYER2; // AI plays as O
                return;
            }
        }
    }
}

int main() {
    char board[SIZE][SIZE];
    int gameOver = 0;
    char currentPlayer = PLAYER1;

    initializeBoard(board);
    printBoard(board);
    
    while (!gameOver) {
        if (currentPlayer == PLAYER1) {
            playerMove(board, currentPlayer);
        } else {
            aiMove(board);
        }
        
        printBoard(board);

        if (isWinner(board, currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            gameOver = 1;
        } else if (isDraw(board)) {
            printf("It's a draw!\n");
            gameOver = 1;
        }

        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1; // Switch player
    }
    
    return 0;
}