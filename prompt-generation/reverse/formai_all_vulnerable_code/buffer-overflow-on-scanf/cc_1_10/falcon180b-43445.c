//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void drawBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkForWinner(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 1;
    }
    return 0;
}

void getMove(int board[SIZE][SIZE], int player) {
    int row, col;
    printf("Player %d's turn:\n", player + 1);
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);
    while (board[row - 1][col - 1]!= 0) {
        printf("Invalid move. Try again:\n");
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);
    }
    board[row - 1][col - 1] = player;
}

int main() {
    int board[SIZE][SIZE] = {0};
    int player = 0;
    while (1) {
        system("clear");
        drawBoard(board);
        printf("Player %d's turn.\n", player + 1);
        getMove(board, player);
        if (checkForWinner(board)) {
            printf("Player %d wins!\n", player + 1);
            break;
        }
        player =!player;
    }
    return 0;
}