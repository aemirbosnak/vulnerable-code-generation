//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void initBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2]!= '-') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i]!= '-') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2]!= '-') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!= '-') {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    initBoard(board);
    int moves = 0;
    int player = 1;
    while (1) {
        system("clear");
        printBoard(board);
        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d%d", &moves, &moves);
        if (moves < 0 || moves > 2) {
            printf("Invalid move.\n");
            continue;
        }
        if (board[moves][moves]!= '-') {
            printf("Tile already flipped.\n");
            continue;
        }
        board[moves][moves] = (player == 1)? 'X' : 'O';
        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
        moves++;
    }
    return 0;
}