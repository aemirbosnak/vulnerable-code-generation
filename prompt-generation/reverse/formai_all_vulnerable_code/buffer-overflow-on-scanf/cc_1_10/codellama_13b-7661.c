//Code Llama-13B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_CELLS (BOARD_SIZE * BOARD_SIZE)
#define EMPTY_CELL ' '
#define PLAYER1 'X'
#define PLAYER2 'O'

// Function prototypes
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void resetBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void playGame(char board[BOARD_SIZE][BOARD_SIZE]);
int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    resetBoard(board);
    playGame(board);
    return 0;
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void resetBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }
}

void playGame(char board[BOARD_SIZE][BOARD_SIZE]) {
    char player = PLAYER1;
    while (checkWin(board, player) == 0) {
        printBoard(board);
        int row, col;
        printf("Enter row and column for player %c: ", player);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            if (board[row][col] == EMPTY_CELL) {
                board[row][col] = player;
            } else {
                printf("Invalid move. Try again.\n");
                continue;
            }
        } else {
            printf("Invalid move. Try again.\n");
            continue;
        }
        player = (player == PLAYER1) ? PLAYER2 : PLAYER1;
    }
    printBoard(board);
    printf("Game over. Player %c wins!\n", player);
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check diagonals
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] == player) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - i - 1] == player) {
            count++;
        }
    }
    if (count == BOARD_SIZE) {
        return 1;
    }

    return 0;
}