//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define BOUNDARY 0
#define VISITED 1
#define PATH 2
#define DROP 3
#define TOTAL_DROPS 500
#define DROP_DELAY 50

int main() {
    int **board = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        board[i] = (int *)malloc(COLS * sizeof(int));
        for (int j = 0; j < COLS; j++) {
            board[i][j] = BOUNDARY;
        }
    }
    int drops = 0;
    srand(time(NULL));
    while (drops < TOTAL_DROPS) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        if (board[x][y] == BOUNDARY) {
            board[x][y] = VISITED;
            drops++;
            if (drops % DROP_DELAY == 0) {
                printf("Dropping water at (%d,%d)\n", x, y);
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == VISITED) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < ROWS; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}