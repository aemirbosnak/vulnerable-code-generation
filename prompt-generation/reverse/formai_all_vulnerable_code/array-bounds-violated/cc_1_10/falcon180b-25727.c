//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define WHITE 1
#define BLACK -1

char board[SIZE][SIZE];
int turn;

void initBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = '.';
        }
    }
    turn = WHITE;
}

void drawBoard() {
    printf("+---+---+---+\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("|   |   |   |\n");
        for (int j = 0; j < SIZE; ++j) {
            printf("|%c |%c |%c |\n", board[i][j], board[i][j+1], board[i][j+2]);
        }
        printf("|   |   |   |\n");
        printf("+---+---+---+\n");
    }
}

int checkWin() {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
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

int checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

void makeMove(int row, int col) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '.') {
        board[row][col] = (turn == WHITE)? 'X' : 'O';
        turn = (turn == WHITE)? BLACK : WHITE;
    }
}

int main() {
    initBoard();
    while (1) {
        drawBoard();
        int x, y;
        printf("Enter your move (row col): ");
        scanf("%d%d", &x, &y);
        makeMove(x, y);
        if (checkWin()) {
            printf("Player %d wins!\n", (turn == WHITE)? 1 : 2);
            break;
        } else if (checkDraw()) {
            printf("It's a draw.\n");
            break;
        }
        turn = (turn == WHITE)? BLACK : WHITE;
    }
    return 0;
}