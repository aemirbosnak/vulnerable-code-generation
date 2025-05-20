//Falcon-180B DATASET v1.0 Category: Table Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void initializeBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][SIZE], char mark) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return 1;
        }
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
            return 1;
        }
    }
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return 1;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    initializeBoard(board);
    int player = 1;
    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        int x, y;
        scanf("%d %d", &x, &y);
        if (board[x][y]!= '-') {
            continue;
        }
        board[x][y] = (player % 2 == 0)? 'X' : 'O';
        player++;
        if (checkWin(board, 'X')) {
            printf("\nPlayer 1 wins!\n");
            break;
        }
        if (checkWin(board, 'O')) {
            printf("\nPlayer 2 wins!\n");
            break;
        }
        if (player > 9) {
            printf("\nIt's a draw.\n");
            break;
        }
    }
    return 0;
}