//Falcon-180B DATASET v1.0 Category: Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][3], char mark) {
    for (int i = 0; i < 3; i++) {
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
    srand(time(0));
    char board[3][3];
    initBoard(board);
    int player = 1;
    while (1) {
        int row, col;
        printf("Player %d's turn\n", player);
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 2 || col < 1 || col > 2) {
            printf("Invalid move\n");
            continue;
        }
        if (board[row - 1][col - 1]!= '-') {
            printf("Cell already taken\n");
            continue;
        }
        board[row - 1][col - 1] = (player == 1)? 'X' : 'O';
        printBoard(board);
        if (checkWin(board, (player == 1)? 'X' : 'O')) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}