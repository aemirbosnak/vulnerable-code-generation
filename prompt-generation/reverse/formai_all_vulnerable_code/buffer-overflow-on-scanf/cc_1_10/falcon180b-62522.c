//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[][COLS]) {
    int i, j;

    // Check horizontal lines
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS - 1; j++) {
            if (board[i][j]!= '-' && board[i][j] == board[i][j + 1]) {
                return 1;
            }
        }
    }

    // Check vertical lines
    for (i = 0; i < ROWS - 1; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j]!= '-' && board[i][j] == board[i + 1][j]) {
                return 1;
            }
        }
    }

    // Check diagonal lines
    for (i = 0; i < ROWS - 1; i++) {
        for (j = 0; j < COLS - 1; j++) {
            if (board[i][j]!= '-' && board[i][j] == board[i + 1][j + 1]) {
                return 1;
            }
        }
    }

    for (i = 1; i < ROWS; i++) {
        for (j = 0; j < COLS - 1; j++) {
            if (board[i][j]!= '-' && board[i][j] == board[i - 1][j + 1]) {
                return 1;
            }
        }
    }

    return 0;
}

void playGame(char board[][COLS]) {
    int player = 1;
    int x, y, validMove = 0;

    while (1) {
        printf("Player %d's turn.\n", player);
        printf("Enter your move (row col): ");
        scanf("%d %d", &x, &y);

        if (x >= 0 && x < ROWS && y >= 0 && y < COLS && board[x][y] == '-') {
            board[x][y] = (player == 1)? 'X' : 'O';
            validMove = 1;

            if (checkWin(board) == 1) {
                printf("Player %d wins!\n", player);
                break;
            } else if (validMove == 0) {
                printf("Invalid move. Skipping turn.\n");
            }

            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move. Skipping turn.\n");
        }
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    playGame(board);

    return 0;
}