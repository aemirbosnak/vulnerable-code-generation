//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

void drawBoard(int board[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROW][COL]) {
    int i, j;

    // Check rows
    for (i = 0; i < ROW; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < COL; j++) {
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

void takeTurn(int board[ROW][COL], int player) {
    int x, y;
    printf("Player %d's turn:\n", player + 1);
    printf("Enter your move (row col): ");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < ROW && y >= 0 && y < COL && board[x][y] == 0) {
        board[x][y] = player;
    } else {
        printf("Invalid move.\n");
        takeTurn(board, player);
    }
}

int main() {
    int board[ROW][COL] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
    int player = 0;
    int i, j;

    srand(time(NULL));

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = rand() % 2;
        }
    }

    drawBoard(board);

    while (!checkWin(board)) {
        takeTurn(board, player);
        player =!player;
        drawBoard(board);
    }

    return 0;
}