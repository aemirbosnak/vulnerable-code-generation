//Falcon-180B DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void drawBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    char mark;

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);
        scanf("%c", &mark);

        int row, col;
        if (mark == '1' || mark == '2' || mark == '3') {
            row = mark - '1';
        } else if (mark == '4' || mark == '5' || mark == '6') {
            col = mark - '4';
        } else {
            continue;
        }

        if (board[row][col]!= 0) {
            continue;
        }

        board[row][col] = player;

        if (checkWin(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player = (player % 2)? 1 : 2;
    }

    return 0;
}