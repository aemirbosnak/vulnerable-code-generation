//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS] = { { '0', '1', '2' }, { '3', '4', '5' }, { '6', '7', '8' } };
char player = 'X';

void drawBoard() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
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

void changePlayer() {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

int main() {
    srand(time(NULL));
    int playerChoice;
    int validMove = 0;

    while (1) {
        system("clear");
        drawBoard();

        printf("\nPlayer %c's turn. Enter a number between 1 and 9: ", player);
        scanf("%d", &playerChoice);

        if (playerChoice < 1 || playerChoice > 9) {
            printf("\nInvalid move. Try again.\n");
            continue;
        }

        int row = playerChoice / 3;
        int col = playerChoice % 3;

        if (board[row][col]!= 'X' && board[row][col]!= 'O') {
            board[row][col] = player;
            validMove = 1;
        } else {
            printf("\nInvalid move. Try again.\n");
        }

        if (checkWin()) {
            printf("\n%c wins!\n", player);
            break;
        }

        if (!validMove) {
            continue;
        }

        changePlayer();
    }

    return 0;
}