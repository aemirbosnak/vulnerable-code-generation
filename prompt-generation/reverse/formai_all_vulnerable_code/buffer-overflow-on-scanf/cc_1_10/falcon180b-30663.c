//Falcon-180B DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void initBoard(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
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
        if (board[i][0]!= '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < SIZE; j++) {
        if (board[0][j]!= '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0]!= '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2]!= '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    char board[SIZE][SIZE];
    int player = 1;
    initBoard(board);
    printBoard(board);

    while (1) {
        int row, col;
        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d%d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col]!= '-') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = (player % 2 == 0)? 'X' : 'O';
        printBoard(board);

        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }

        player++;
        if (player > 2) {
            player = 1;
        }
    }

    return 0;
}