//Falcon-180B DATASET v1.0 Category: Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS]; // game board
int player = 1; // current player
int winner = 0; // game winner

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard() {
    printf("-------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("| ");
        for (int j = 0; j < COLS; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

int checkWin() {
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
    srand(time(0));
    initBoard();
    int moves = 0;

    while (winner == 0 && moves < 9) {
        drawBoard();
        int x, y;
        printf("Player %d's turn. Enter your move: ", player);
        scanf("%d %d", &x, &y);

        if (board[x - 1][y - 1] == '-') {
            board[x - 1][y - 1] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;
            moves++;
        } else {
            printf("Invalid move. Try again.\n");
        }

        winner = checkWin();
    }

    if (winner == 1) {
        printf("Player 1 wins!\n");
    } else if (winner == 2) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a draw.\n");
    }

    return 0;
}