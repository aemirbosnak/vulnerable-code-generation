//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_TRIES 5

char board[ROWS][COLS];
int tries = 0;

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '*';
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

void placeShip(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        board[row][col] = 'S';
        printf("Ship placed at (%d,%d)\n", row, col);
    } else {
        printf("Invalid position\n");
    }
}

int checkHit(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == 'S') {
        printf("Hit!\n");
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    initBoard();
    placeShip(0, 0);
    int playerRow, playerCol;
    while (tries < MAX_TRIES) {
        printBoard();
        printf("Enter your guess (row,col): ");
        scanf("%d,%d", &playerRow, &playerCol);
        if (checkHit(playerRow, playerCol)) {
            printf("You win!\n");
            break;
        } else {
            printf("Miss.\n");
            tries++;
        }
    }
    if (tries == MAX_TRIES) {
        printf("Game over. You lose.\n");
    }
    return 0;
}