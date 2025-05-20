//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROWS][COLS]) {
    int i, j;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2]!= '-') {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j]!= '-') {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2]!= '-') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!= '-') {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    int player = 1;
    int moves = 0;

    initBoard(board);

    while (1) {
        printBoard(board);
        int x, y;
        if (player % 2 == 1) {
            printf("Player 1's turn. Enter your move: ");
            scanf("%d%d", &x, &y);
            x--; y--;
            if (board[x][y] == '-') {
                board[x][y] = 'X';
                moves++;
                if (checkWin(board)) {
                    printf("Player 1 wins!\n");
                    break;
                } else if (moves == 9) {
                    printf("It's a draw.\n");
                    break;
                }
            } else {
                printf("Invalid move.\n");
            }
        } else {
            int found = 0;
            while (!found) {
                x = rand() % ROWS;
                y = rand() % COLS;
                if (board[x][y] == '-') {
                    board[x][y] = 'O';
                    found = 1;
                }
            }
            moves++;
            if (checkWin(board)) {
                printf("Player 2 wins!\n");
                break;
            } else if (moves == 9) {
                printf("It's a draw.\n");
                break;
            }
        }
        player++;
    }

    return 0;
}