//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char board[ROWS][COLS];

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
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

void placeShip(int row, int col, char shipSize) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '.') {
        board[row][col] = shipSize;
    } else {
        printf("Invalid placement.\n");
    }
}

void placeShips() {
    int shipCount;
    printf("How many ships do you have? ");
    scanf("%d", &shipCount);

    for (int i = 0; i < shipCount; i++) {
        printf("Enter the size of ship %d: ", i + 1);
        char size;
        scanf(" %c", &size);

        printf("Enter the row for ship %c: ", size);
        int row;
        scanf("%d", &row);

        printf("Enter the column for ship %c: ", size);
        int col;
        scanf("%d", &col);

        placeShip(row, col, size);
    }
}

void attack(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col]!= '.') {
        if (board[row][col] == 'X') {
            printf("You missed!\n");
        } else if (board[row][col] == 'S') {
            printf("You sunk a ship!\n");
            board[row][col] = 'X';
        } else {
            printf("You hit a ship.\n");
            board[row][col] = '.';
        }
    } else {
        printf("Invalid attack.\n");
    }
}

int main() {
    srand(time(NULL));

    initBoard();
    placeShips();

    int playerTurns = 0;
    while (playerTurns < 10) {
        printBoard();
        printf("Enter your attack (row col): ");
        int row, col;
        scanf("%d %d", &row, &col);
        attack(row, col);

        playerTurns++;
    }

    return 0;
}