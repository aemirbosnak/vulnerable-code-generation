//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

int board[MAX][MAX]; // the board
int num_filled; // number of filled cells
int num_iterations; // number of iterations
int threshold; // number of filled neighbors required to fill a cell

void init_board() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int i, int j) {
    int count = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if ((x + i) >= 0 && (x + i) < MAX && (y + j) >= 0 && (y + j) < MAX) {
                if (board[(i + x) / 2][(j + y) / 2] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void percolate() {
    srand(time(NULL));
    int x, y;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (board[i][j] == 0) {
                if (count_neighbors(i, j) >= threshold) {
                    board[i][j] = 1;
                    num_filled++;
                }
            }
        }
    }
    num_iterations++;
    print_board();
    if (num_filled == (MAX * MAX / 2)) {
        printf("The system has percolated!\n");
        exit(0);
    }
}

int main() {
    printf("Welcome to the Percolation Simulator!\n");
    printf("Please enter the threshold number of filled neighbors required to fill a cell: ");
    scanf("%d", &threshold);
    init_board();
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (rand() % 2 == 0) {
                board[i][j] = 1;
                num_filled++;
            }
        }
    }
    num_iterations = 0;
    while (num_filled < (MAX * MAX / 2)) {
        percolate();
    }
    return 0;
}