//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void getMove(char board[SIZE][SIZE], int player) {
    int x, y;
    do {
        printf("Player %d, enter your move (row [0-2] and column [0-2]): ", player);
        scanf("%d%d", &x, &y);
        x--;
        y--;
    } while (board[x][y]!= '\0');

    board[x][y] = (player == 1)? 'X' : 'O';
}

int main() {
    srand(time(0));
    char board[SIZE][SIZE];

    // Initialize board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '\0';
        }
    }

    int player = rand() % 2 + 1;
    while (1) {
        drawBoard(board);
        printf("Player %d's turn\n", player);
        getMove(board, player);

        if (checkWin(board)) {
            drawBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}