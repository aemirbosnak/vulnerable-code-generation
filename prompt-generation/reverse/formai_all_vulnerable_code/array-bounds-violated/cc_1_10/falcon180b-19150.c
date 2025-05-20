//Falcon-180B DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[3][3], int player) {
    int i, j;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int player = rand() % 2 + 1; // 1 for X, 2 for O
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int i, j;

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player %d, your turn.\n", player);

    while (1) {
        printBoard(board);
        int choice;
        printf("Enter your move (1-9): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            printf("Invalid move, try again.\n");
            continue;
        }
        i = choice / 3;
        j = choice % 3;
        if (board[i][j]!= 0) {
            printf("Spot already taken, try again.\n");
            continue;
        }
        board[i][j] = player;
        if (checkWin(board, player)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1; // Switch player
    }

    return 0;
}