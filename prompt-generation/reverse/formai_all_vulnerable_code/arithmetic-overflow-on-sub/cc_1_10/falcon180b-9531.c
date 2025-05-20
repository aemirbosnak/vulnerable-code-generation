//Falcon-180B DATASET v1.0 Category: Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int board[ROWS][COLS];

void initBoard() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
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
    initBoard();
    printBoard();

    int player = 1;
    int choice;
    while (1) {
        printf("Player %d's turn\n", player);
        printf("Enter your choice (1-%d): ", ROWS * COLS - 1);
        scanf("%d", &choice);
        choice--;

        if (choice < 0 || choice >= ROWS * COLS) {
            printf("Invalid choice\n");
            continue;
        }

        if (board[choice / COLS][choice % COLS]!= 0) {
            printf("Cell already occupied\n");
            continue;
        }

        board[choice / COLS][choice % COLS] = player;
        printBoard();

        if (checkWin()) {
            printf("Player %d wins!\n", player);
            break;
        }

        player =!player;
    }

    return 0;
}