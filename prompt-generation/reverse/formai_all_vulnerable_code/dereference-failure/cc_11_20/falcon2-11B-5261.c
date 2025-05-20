//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define P 0.5

int main() {
    int **board;
    int i, j;
    int n, m;
    int count, total;

    // Initialize board
    board = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        board[i] = (int *)malloc(COLS * sizeof(int));
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Percolation simulation
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            count = 0;
            total = 0;

            for (n = 0; n < ROWS; n++) {
                for (m = 0; m < COLS; m++) {
                    if (board[n][m] == 1 && board[i][j] == 1) {
                        count++;
                    }
                }
            }

            if (count > (int)pow(P, total)) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }

            total++;
        }
    }

    // Print board
    printf("Percolation Simulation\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < ROWS; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}