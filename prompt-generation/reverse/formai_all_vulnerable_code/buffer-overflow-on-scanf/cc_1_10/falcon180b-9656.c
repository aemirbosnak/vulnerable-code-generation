//Falcon-180B DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define NUM_SYMBOLS 2

char board[ROWS][COLS];
char symbols[NUM_SYMBOLS] = {'X', 'O'};

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int player = rand() % 2;
    int choice;
    int move = 0;

    initializeBoard();
    printBoard();

    while (1) {
        printf("Player %d's turn\n", player + 1);
        printf("Enter your move (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);
        move++;

        if (choice < 1 || choice > ROWS * COLS - 1) {
            printf("Invalid move\n");
            continue;
        }

        int row = choice / COLS;
        int col = choice % COLS;

        if (board[row][col]!= '-') {
            printf("Spot already taken\n");
            continue;
        }

        board[row][col] = symbols[player];

        if (checkWin()) {
            printf("Player %d wins!\n", player + 1);
            break;
        }

        player =!player;
        printBoard();
    }

    return 0;
}