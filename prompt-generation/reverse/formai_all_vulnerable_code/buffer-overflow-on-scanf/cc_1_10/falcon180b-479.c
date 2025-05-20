//Falcon-180B DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void generateBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = (i + j) % 3 + 1;
        }
    }
}

int checkWin(char board[ROWS][COLS]) {
    int i;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return 0;
}

void printBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];

    generateBoard(board);

    int player = 1;
    int choice;
    int win = 0;

    while (!win) {
        printf("Player %d's turn.\n", player);
        printf("Enter your move (1-9): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            printf("Invalid move.\n");
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col]!= 0) {
            printf("Spot taken.\n");
            continue;
        }

        board[row][col] = player;

        win = checkWin(board);

        if (win) {
            printf("Player %d wins!\n", player);
            break;
        }

        player =!player;
    }

    printBoard(board);

    return 0;
}