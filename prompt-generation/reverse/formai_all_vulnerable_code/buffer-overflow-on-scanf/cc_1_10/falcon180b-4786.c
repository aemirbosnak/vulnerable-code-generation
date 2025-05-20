//Falcon-180B DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define MAX_MOVES 9

void drawBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROWS][COLS]) {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
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
    char board[ROWS][COLS] = { { '0', '1', '2' }, { '3', '4', '5' }, { '6', '7', '8' } };
    int player = 1;
    int moves = 0;

    while (moves < MAX_MOVES) {
        drawBoard(board);
        printf("Player %d's turn. Enter your move: ", player);
        scanf("%d", &player);

        if (player > 2 || board[player - 1][moves % 3]!= '0') {
            printf("Invalid move!\n");
            continue;
        }

        board[player - 1][moves % 3] = (char) (player + '0');
        moves++;

        if (checkWin(board)) {
            drawBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }

        player++;
        if (player > 2) {
            player = 1;
        }
    }

    return 0;
}