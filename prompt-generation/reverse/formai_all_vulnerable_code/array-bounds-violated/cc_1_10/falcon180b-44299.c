//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MOVES 10
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
int x = 0, y = 0;
int moves = 0;

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void moveRobot() {
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;

    if (dx == 0 && dy == 0) {
        printf("The robot is confused and stays put.\n");
    } else {
        x += dx;
        y += dy;

        if (board[x][y] == '#') {
            printf("The robot hits a wall and bounces back.\n");
            x -= dx;
            y -= dy;
        } else if (board[x][y] == '*') {
            printf("The robot finds a treasure!\n");
            moves++;
        } else {
            board[x][y] = 'R';
            printf("The robot moves to (%d, %d).\n", x, y);
        }
    }
}

int main() {
    srand(time(NULL));
    initBoard();

    while (moves < NUM_MOVES) {
        printBoard();
        moveRobot();
    }

    return 0;
}