//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROWS][COLS]) {
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

    char board[ROWS][COLS];
    initBoard(board);

    int player = 1;
    while (1) {
        int row, col;
        if (player % 2 == 1) {
            printf("Player 1's turn.\n");
            printf("Enter your move (row and column): ");
            scanf("%d %d", &row, &col);
            row--; col--;
            if (board[row][col]!= '-') {
                printf("Invalid move.\n");
                continue;
            }
            board[row][col] = 'X';
            if (checkWin(board)) {
                printf("Player 1 wins!\n");
                break;
            }
            player++;
        } else {
            printf("Player 2's turn.\n");
            int validMove = 0;
            while (!validMove) {
                int moveRow, moveCol;
                printf("Enter your move (row and column): ");
                scanf("%d %d", &moveRow, &moveCol);
                moveRow--; moveCol--;
                if (board[moveRow][moveCol] == '-') {
                    board[moveRow][moveCol] = 'O';
                    validMove = 1;
                } else {
                    printf("Invalid move.\n");
                }
            }
            if (checkWin(board)) {
                printf("Player 2 wins!\n");
                break;
            }
            player++;
        }
    }

    return 0;
}