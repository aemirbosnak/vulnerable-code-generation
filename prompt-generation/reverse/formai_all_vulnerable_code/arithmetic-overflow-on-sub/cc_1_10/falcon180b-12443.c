//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '0' + (i * COLS + j);
        }
    }
}

void printBoard(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool checkWin(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3]) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i]) {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return true;
    }
    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
        return true;
    }
    return false;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int player = 1;
    while (true) {
        printBoard(board);
        int row, col;
        if (player % 2 == 1) {
            printf("Player 1's turn. Enter row and column: ");
            scanf("%d%d", &row, &col);
            row--; col--;
            if (board[row][col]!= '0' && board[row][col]!= '1' && board[row][col]!= '2') {
                printf("Invalid move.\n");
                continue;
            }
            board[row][col] = (char)(player + '0');
            player++;
        } else {
            int count = 0;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (board[i][j] == '0') {
                        board[i][j] = (char)(player + '0');
                        count++;
                    }
                }
            }
            if (count == 0) {
                printf("Player %c wins!\n", '1' + (player - 1));
                break;
            }
            player++;
        }
        if (checkWin(board)) {
            printf("Player %c wins!\n", '1' + (player - 1));
            break;
        }
    }
    return 0;
}