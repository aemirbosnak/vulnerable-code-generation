//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
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

    // Check rows and columns
    for (i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

void makeMove(char board[SIZE][SIZE], int choice) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == '\0') {
                board[i][j] = (choice == 1)? 'X' : 'O';
                return;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int player = rand() % 2 + 1;
    char board[SIZE][SIZE] = { { '\0', '\0', '\0' }, { '\0', '\0', '\0' }, { '\0', '\0', '\0' } };

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);

        int choice;
        scanf("%d", &choice);

        makeMove(board, choice);

        if (checkWin(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}