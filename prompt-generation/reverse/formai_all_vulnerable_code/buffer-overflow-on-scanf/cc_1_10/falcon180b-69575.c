//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void drawBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    int i;

    // Check rows
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < SIZE; i++) {
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
    char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char currentPlayer = 'X';
    int i, j, validMove = 0;

    drawBoard(board);

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nCurrent player: %c\n", currentPlayer);

        validMove = 0;
        scanf("%d%d", &i, &j);

        if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && board[i][j] == '\0') {
            board[i][j] = currentPlayer;
            validMove = 1;

            if (checkWin(board)) {
                printf("\nPlayer %c wins!\n", currentPlayer);
                break;
            }

            if (!validMove) {
                printf("\nInvalid move. Try again.\n");
            } else {
                currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
            }
        } else {
            printf("\nInvalid move. Try again.\n");
        }
    }

    return 0;
}