//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30
#define DROPS 1000

int board[HEIGHT][WIDTH];
int drops = 0;

void initBoard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int countAdjacentDrops(int x, int y) {
    int count = 0;
    if (board[x - 1][y] == 1) {
        count++;
    }
    if (board[x + 1][y] == 1) {
        count++;
    }
    if (board[x][y - 1] == 1) {
        count++;
    }
    if (board[x][y + 1] == 1) {
        count++;
    }
    return count;
}

int main() {
    srand(time(NULL));
    initBoard();
    for (int i = 0; i < DROPS; i++) {
        int x = rand() % HEIGHT;
        int y = rand() % WIDTH;
        if (board[x][y] == 0 && countAdjacentDrops(x, y) == 1) {
            board[x][y] = 1;
            drops++;
        }
    }
    printBoard();
    printf("Total drops: %d\n", drops);
    return 0;
}