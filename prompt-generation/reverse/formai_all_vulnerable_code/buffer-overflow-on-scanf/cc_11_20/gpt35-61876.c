//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void printBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool checkWin(char board[][COLS], char player) {
    //check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    //check columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    //check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    char board[ROWS][COLS];
    //initialize board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
    int turn = 1;
    char player1 = 'X';
    char player2 = 'O';
    int row, col;
    bool winFlag = false;
    bool drawFlag = false;
    while (!winFlag && !drawFlag) {
        if (turn % 2 == 1) {
            printf("Player 1 (X) Turn: \n");
        } else {
            printf("Player 2 (O) Turn: \n");
        }
        printf("Enter row and column (0-4): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '-') {
            if (turn % 2 == 1) {
                board[row][col] = player1;
            } else {
                board[row][col] = player2;
            }
            printBoard(board);
            if (checkWin(board, player1)) {
                printf("Player 1 (X) Wins!\n");
                winFlag = true;
            } else if (checkWin(board, player2)) {
                printf("Player 2 (O) Wins!\n");
                winFlag = true;
            } else if (turn == ROWS * COLS) {
                printf("Draw!\n");
                drawFlag = true;
            }
            turn++;
        } else {
            printf("Invalid Move!\n");
        }
    }
    return 0;
}