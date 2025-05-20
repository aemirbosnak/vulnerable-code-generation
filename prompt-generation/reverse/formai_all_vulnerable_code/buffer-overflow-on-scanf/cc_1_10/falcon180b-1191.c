//Falcon-180B DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define EMPTY '.'
#define PLAYER1 'X'
#define PLAYER2 'O'

void drawBoard(char board[ROWS][COLS]) {
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
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
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
    char board[ROWS][COLS] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    int player = 1;
    int choice;
    int x, y;

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your move (row col): ");
        scanf("%d %d", &x, &y);

        if (x < 1 || x > ROWS || y < 1 || y > COLS) {
            printf("Invalid move.\n");
            continue;
        }

        if (board[x - 1][y - 1]!= EMPTY) {
            printf("Spot taken.\n");
            continue;
        }

        board[x - 1][y - 1] = (player % 2 == 0)? PLAYER1 : PLAYER2;
        player++;

        if (checkWin(board)) {
            printf("\nPlayer %d wins!\n", player - 1);
            break;
        }

        if (player > 2) {
            printf("\nTie game.\n");
            break;
        }
    }

    return 0;
}