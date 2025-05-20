//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    printf("Post-Apocalyptic Tic Tac Toe\n");
    printf("Survivors: X  Invaders: O\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
}

bool isWinning(char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) return false;
        }
    }
    return true;
}

void playerMove() {
    int row, col;
    while (true) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void aiMove() {
    // A primitive AI that randomly picks an empty spot
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                return;
            }
        }
    }
}

void aiMoveSmart() {
    // AI that attempts to win or block the player
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                if (isWinning(AI)) return;
                board[i][j] = EMPTY;
            }
        }
    }
  
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER;
                if (isWinning(PLAYER)) {
                    board[i][j] = AI;
                    return;
                }
                board[i][j] = EMPTY;
            }
        }
    }
  
    // If no immediate win or block, pick random
    aiMove();
}

int main() {
    printf("Welcome to the Desolate Arena of Tic Tac Toe...\n");
    initializeBoard();
    printBoard();

    while (true) {
        playerMove();
        printBoard();
        if (isWinning(PLAYER)) {
            printf("You survived! You beat the invaders!\n");
            break;
        }
        if (isBoardFull()) {
            printf("The battle ended in a stalemate...\n");
            break;
        }
        aiMoveSmart();
        printBoard();
        if (isWinning(AI)) {
            printf("The invaders have claimed victory...\n");
            break;
        }
        if (isBoardFull()) {
            printf("The battle ended in a stalemate...\n");
            break;
        }
    }

    printf("Game Over.\n");
    return 0;
}