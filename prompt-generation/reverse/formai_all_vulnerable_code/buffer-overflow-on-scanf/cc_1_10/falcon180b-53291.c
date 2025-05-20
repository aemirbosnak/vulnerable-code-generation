//Falcon-180B DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int board[SIZE][SIZE] = {{0,0,0},{0,0,0},{0,0,0}};

void drawBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    // check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void playGame() {
    int player = 1;
    int choice;
    while (1) {
        drawBoard();
        printf("Player %d's turn\n", player);
        printf("Enter your move (row and column): ");
        scanf("%d%d", &choice, &choice);
        if (choice < 0 || choice > 2) {
            printf("Invalid move\n");
            continue;
        }
        if (board[choice][0]!= 0 || board[choice][1]!= 0 || board[choice][2]!= 0) {
            printf("Spot already taken\n");
            continue;
        }
        board[choice][0] = player;
        if (checkWin()) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
}

int main() {
    playGame();
    return 0;
}