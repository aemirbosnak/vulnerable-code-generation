//Falcon-180B DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void createBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE], char symbol) {
    for (int i = 0; i < SIZE - 2; i++) {
        if (board[i][0] == symbol && board[i + 1][0] == symbol && board[i + 2][0] == symbol) {
            return 1;
        }
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    createBoard(board);
    int players = 2;
    int currentPlayer = 1;
    while (players > 0) {
        int row, col;
        printf("Player %d's turn\n", currentPlayer);
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid move\n");
        } else if (board[row][col]!= '.') {
            printf("Spot already taken\n");
        } else {
            board[row][col] = (currentPlayer == 1)? 'X' : 'O';
            if (checkWin(board, board[row][col])) {
                printf("Player %d wins!\n", currentPlayer);
                players--;
            } else if (players == 1) {
                printf("Tie game\n");
            } else {
                currentPlayer = (currentPlayer == 1)? 2 : 1;
            }
        }
        printBoard(board);
    }
    return 0;
}