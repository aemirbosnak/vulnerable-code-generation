//Falcon-180B DATASET v1.0 Category: Table Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void drawBoard(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(int board[ROWS][COLS]) {
    int i, j;

    // Check horizontal lines
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check vertical lines
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonal lines
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    int board[ROWS][COLS] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    srand(time(NULL));

    while (1) {
        system("clear");
        printf("Player 1: X, Player 2: O\n");
        printf("Player %d's turn.\n", player);
        drawBoard(board);

        printf("\nEnter your move (1-%d): ", ROWS*COLS-1);
        scanf("%d", &choice);

        if (choice < 1 || choice > ROWS*COLS-1) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (board[choice/COLS][choice%COLS]!= 0) {
            printf("Spot already taken. Try again.\n");
            continue;
        }

        board[choice/COLS][choice%COLS] = player;

        if (checkWin(board)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}