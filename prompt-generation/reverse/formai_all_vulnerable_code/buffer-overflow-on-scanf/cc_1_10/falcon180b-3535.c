//Falcon-180B DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void createBoard(char board[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][COL], char mark) {
    int i, j;

    // Check rows
    for (i = 0; i < ROW; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < COL; j++) {
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
        return 1;
    }
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
        return 1;
    }

    return 0;
}

int main() {
    char board[ROW][COL];
    int i, j, player = 1;
    char mark;

    srand(time(0));
    mark = (rand() % 2)? 'X' : 'O';

    createBoard(board);
    drawBoard(board);

    while (1) {
        printf("Player %d's turn.\n", player);
        printf("Enter row and column: ");
        scanf("%d%d", &i, &j);

        if (board[i - 1][j - 1]!= '-') {
            printf("Invalid move.\n");
            continue;
        }

        board[i - 1][j - 1] = mark;

        drawBoard(board);

        if (checkWin(board, mark)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
        mark = (mark == 'X')? 'O' : 'X';
    }

    return 0;
}