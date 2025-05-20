//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void drawBoard(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS]) {
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

int getPlayerMove(int board[ROWS][COLS]) {
    int x, y;
    printf("Enter your move (row, column): ");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && board[x][y] == 0) {
        board[x][y] = 1;
        return 1;
    }

    return 0;
}

int main() {
    int board[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1; // Player 1 starts
    int i, j;

    while (1) {
        drawBoard(board);
        printf("Player %d's turn\n", player);

        if (!getPlayerMove(board)) {
            printf("Invalid move, try again.\n");
            continue;
        }

        if (checkWin(board)) {
            drawBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }

        player =!player; // Switch to other player
    }

    return 0;
}