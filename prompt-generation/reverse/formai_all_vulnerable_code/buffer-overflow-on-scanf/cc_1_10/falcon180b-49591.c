//Falcon-180B DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define BOARD_MAX 9

void initBoard(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[BOARD_SIZE][BOARD_SIZE];
    initBoard(board);
    int player = 1;
    while (1) {
        system("clear");
        printBoard(board);
        printf("Player %d's turn\n", player);
        int row, col;
        scanf("%d%d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid move\n");
            continue;
        }
        if (board[row][col]!= 0) {
            printf("Spot already taken\n");
            continue;
        }
        board[row][col] = player;
        if (checkWin(board) == player) {
            printf("Player %d wins!\n", player);
            break;
        }
        player =!player;
    }
    return 0;
}