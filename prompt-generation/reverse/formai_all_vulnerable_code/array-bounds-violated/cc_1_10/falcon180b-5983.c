//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define DROPS 1000

int board[ROWS][COLS];
int drops = 0;

void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

void drawBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int countAdjDrops(int x, int y) {
    int count = 0;
    if (x > 0 && board[x-1][y] == 1) {
        count++;
    }
    if (x < COLS-1 && board[x+1][y] == 1) {
        count++;
    }
    if (y > 0 && board[x][y-1] == 1) {
        count++;
    }
    if (y < ROWS-1 && board[x][y+1] == 1) {
        count++;
    }
    return count;
}

void percolate(int x, int y) {
    if (x < 0 || x >= COLS || y < 0 || y >= ROWS) {
        return;
    }
    if (board[y][x] == 0 && countAdjDrops(x, y) == 1) {
        board[y][x] = 1;
        drops++;
    }
}

void simulate() {
    srand(time(NULL));
    initBoard();
    for (int i = 0; i < DROPS; i++) {
        int x = rand() % COLS;
        int y = rand() % ROWS;
        percolate(x, y);
    }
    drawBoard();
    printf("Total drops: %d\n", drops);
}

int main() {
    simulate();
    return 0;
}