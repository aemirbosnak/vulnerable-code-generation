//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
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
    int i, j;

    // Check rows
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < SIZE; j++) {
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

int getValidMove(char board[SIZE][SIZE], int player) {
    int x, y;
    char c;

    printf("Player %d's turn:\n", player + 1);
    printf("Enter your move (row, column): ");
    scanf("%d%d", &x, &y);

    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == '\0') {
        board[x][y] = (player == 1)? 'X' : 'O';
        return 1;
    }

    printf("Invalid move. Try again.\n");
    return 0;
}

void playGame(char board[SIZE][SIZE]) {
    int player = 1;
    int validMove;

    while (1) {
        drawBoard(board);
        validMove = getValidMove(board, player);

        if (!validMove) {
            continue;
        }

        if (checkWin(board)) {
            drawBoard(board);
            printf("Player %d wins!\n", player + 1);
            break;
        }

        player = (player == 1)? 2 : 1;
    }
}

int main() {
    char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

    playGame(board);

    return 0;
}