//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {{'-', '-', '-',},
    {'-', '-', '-',},
    {'-', '-', '-'},};

char player = 'X';

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

int isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin() {
    // Rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player) {
            return 1;
        }
    }

    // Columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == player) {
            return 1;
        }
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player) {
        return 1;
    }

    // Draw
    if (isBoardFull()) {
        return 2;
    }

    return 0;
}

void makeMove(int x, int y) {
    if (board[x][y] != '-') {
        return;
    }

    board[x][y] = player;
}

int main() {
    initializeBoard();

    // Play until someone wins or there is a draw
    while (!checkWin() && !isBoardFull()) {
        // Get the player's move
        int moveX;
        int moveY;

        printf("Enter your move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        // Make the move
        makeMove(moveX, moveY);

        // Print the board
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Print the winner or draw
    switch (checkWin()) {
        case 1:
            printf("You win!");
            break;
        case 2:
            printf("It's a draw!");
            break;
        default:
            printf("An error occurred!");
    }

    return 0;
}