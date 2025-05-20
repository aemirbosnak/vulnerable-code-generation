//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY '.'
#define PLAYER1 'X'
#define PLAYER2 'O'
#define WINNING_CONDITIONS {3, 4, 5, 6, 7, 8, 9}

void initBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE], int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int checkDraw(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

void aiMove(char board[BOARD_SIZE][BOARD_SIZE], int player) {
    int move = rand() % BOARD_SIZE;
    int row = rand() % BOARD_SIZE;
    while (board[row][move]!= EMPTY) {
        move = rand() % BOARD_SIZE;
        row = rand() % BOARD_SIZE;
    }
    board[row][move] = player;
}

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE];
    initBoard(board);
    int player = 1;
    while (1) {
        printBoard(board);
        int x, y;
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == EMPTY) {
            board[x][y] = player == 1? PLAYER1 : PLAYER2;
            player = 3 - player;
            if (checkWin(board, player)) {
                printf("Player %d wins!\n", player);
                break;
            } else if (checkDraw(board)) {
                printf("Draw!\n");
                break;
            }
        }
    }
    return 0;
}