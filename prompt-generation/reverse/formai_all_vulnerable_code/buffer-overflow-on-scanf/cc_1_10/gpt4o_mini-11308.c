//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'
#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
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
    printf("\n");
}

int checkWinner(char board[SIZE][SIZE]) {
    // Check rows and columns for a winner
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i];
    }
    
    // Check diagonals for a winner
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2];

    return EMPTY;
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == EMPTY)
                return 0;
    return 1;
}

void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    while (1) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
}

void aiMove(char board[SIZE][SIZE]) {
    // Simple strategy for AI - first available space
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                return;
            }
        }
    }
}

int main() {
    char board[SIZE][SIZE] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };

    printf("Welcome to Tic Tac Toe!\n");
    printBoard(board);

    while (1) {
        // Player's turn
        playerMove(board);
        printBoard(board);
        
        if (checkWinner(board) == PLAYER) {
            printf("Congratulations! You win!\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a tie!\n");
            break;
        }

        // AI's turn
        printf("AI's turn!\n");
        aiMove(board);
        printBoard(board);
        
        if (checkWinner(board) == AI) {
            printf("AI wins! Better luck next time.\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}