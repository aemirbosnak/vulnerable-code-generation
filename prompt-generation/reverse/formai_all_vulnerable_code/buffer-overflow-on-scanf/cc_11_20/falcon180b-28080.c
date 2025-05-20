//Falcon-180B DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define SYMBOLS 4

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
    int player = 1;
    int moves = 0;
    while (moves < 9) {
        system("clear");
        printf("Player %d's turn\n", player);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        int x, y;
        scanf("%d %d", &x, &y);
        if (player == 1) {
            if (board[x][y]!= '-') {
                printf("Invalid move\n");
                continue;
            }
            board[x][y] = 'X';
        } else {
            if (board[x][y]!= '-') {
                printf("Invalid move\n");
                continue;
            }
            board[x][y] = 'O';
        }
        if (checkWin(board, player)) {
            printf("Player %d wins!\n", player);
            return 0;
        }
        player = (player == 1)? 2 : 1;
        moves++;
    }
    printf("Tie game\n");
    return 0;
}

int checkWin(char board[ROWS][COLS], int player) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
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