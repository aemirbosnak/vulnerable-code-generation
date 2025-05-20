//Falcon-180B DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void generateBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = (i + j) % 2? 'X' : 'O';
        }
    }
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    char board[SIZE][SIZE];
    generateBoard(board);

    int player = 1;
    while (1) {
        system("clear");
        printBoard(board);
        printf("\nPlayer %d's turn\n", player);

        int row, col;
        printf("Enter row and column: ");
        scanf("%d%d", &row, &col);

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == 'X' || board[row][col] == 'O') {
            board[row][col] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move\n");
        }

        if (checkWin(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }
    }

    return 0;
}