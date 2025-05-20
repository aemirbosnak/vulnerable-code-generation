//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
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
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[i][0] == board[i][2] && board[i][2] == board[i][1])) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < SIZE; i++) {
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
            (board[0][i] == board[2][i] && board[2][i] == board[1][i])) {
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

void aiMove(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

void playerMove(char board[SIZE][SIZE]) {
    int i, j;
    char move;

    printf("Enter your move (row col): ");
    scanf("%d %c", &i, &move);
    j = move - '0';

    if (board[i][j] == '-') {
        board[i][j] = 'X';
    } else {
        printf("Invalid move.\n");
    }
}

int main() {
    srand(time(0));
    char board[SIZE][SIZE] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'} };
    int player = 0;
    int aiTurn = 0;

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player + 1);

        playerMove(board);

        if (checkWin(board) == 1) {
            printf("\nPlayer %d wins!\n", player + 1);
            break;
        }

        aiTurn++;
        if (aiTurn == 3) {
            aiMove(board);
            aiTurn = 0;
        }

        if (checkWin(board) == 1) {
            printf("\nAI wins!\n");
            break;
        }

        player++;
        if (player == 2) {
            player = 0;
        }
    }

    return 0;
}