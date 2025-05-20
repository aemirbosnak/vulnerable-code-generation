//Falcon-180B DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int board[SIZE][SIZE];

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void drawBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2]!= 0) {
            return board[i][2];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i]!= 0) {
            return board[2][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2]!= 0) {
        return board[2][2];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!= 0) {
        return board[2][0];
    }
    return 0;
}

int main() {
    initBoard();
    int player = 1;
    int x, y;

    while (1) {
        drawBoard();
        printf("\nPlayer %d's turn\n", player);
        scanf("%d%d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y]!= 0) {
            printf("Invalid move\n");
            continue;
        }

        board[x][y] = player;

        if (checkWin()!= 0) {
            printf("Player %d wins!\n", checkWin());
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}