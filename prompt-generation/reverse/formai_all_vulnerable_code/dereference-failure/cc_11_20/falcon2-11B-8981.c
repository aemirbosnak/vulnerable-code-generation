//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int percolationSimulator(int n, int p) {
    int** board = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        board[i] = (int*)malloc(n * sizeof(int));
    }
    
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = rand() % 2;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    if (board[i][j] == 1) {
                        board[i][j] = 2;
                    } else {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }

    int connected = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                connected++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                board[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                connected++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                connected++;
            }
        }
    }

    free(board);

    return connected * (1 - p) + (1 - connected) * p;
}

int main() {
    int n = 20;
    int p = 0.3;
    int result = percolationSimulator(n, p);
    printf("The probability of percolation is %f\n", result);
    return 0;
}