//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
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

void placeMark(char board[SIZE][SIZE], char mark) {
    int x, y;
    printf("Enter the coordinates of your move (row and column): ");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == '\0') {
        board[x][y] = mark;
    } else {
        printf("Invalid move. Try again.\n");
    }
}

int main() {
    char board[SIZE][SIZE];
    int i, j;

    // Initialize board
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '\0';
        }
    }

    // Start the game
    int player = 1;
    while (1) {
        drawBoard(board);
        printf("Player %d's turn.\n", player);
        placeMark(board, player == 1? 'X' : 'O');

        if (checkWin(board)) {
            drawBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }

        player =!player;
    }

    return 0;
}