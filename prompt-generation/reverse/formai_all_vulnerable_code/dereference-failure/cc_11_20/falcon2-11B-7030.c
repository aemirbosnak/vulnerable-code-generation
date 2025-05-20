//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate percolation
void percolate(int** board, int width, int height) {
    int i, j, k;
    srand(time(NULL));

    // Initialize board
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Percolation simulation
    for (k = 0; k < 100000; k++) {
        // Check for neighboring cells
        for (i = 1; i < height - 1; i++) {
            for (j = 1; j < width - 1; j++) {
                if (board[i - 1][j - 1] == 1 && board[i - 1][j] == 1 && board[i - 1][j + 1] == 1 && board[i][j - 1] == 1 && board[i][j + 1] == 1 && board[i + 1][j - 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1) {
                    board[i][j] = 1;
                }
            }
        }

        // Check for cells with no neighbors
        for (i = 1; i < height - 1; i++) {
            for (j = 1; j < width - 1; j++) {
                if (board[i - 1][j - 1] == 0 && board[i - 1][j] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 1] == 0 && board[i][j + 1] == 0 && board[i + 1][j - 1] == 0 && board[i + 1][j] == 0 && board[i + 1][j + 1] == 0) {
                    board[i][j] = 1;
                }
            }
        }

        // Check for isolated cells
        for (i = 1; i < height - 1; i++) {
            for (j = 1; j < width - 1; j++) {
                if (board[i - 1][j - 1] == 0 && board[i - 1][j] == 0 && board[i - 1][j + 1] == 0 && board[i][j - 1] == 0 && board[i][j + 1] == 0 && board[i + 1][j - 1] == 0 && board[i + 1][j] == 0 && board[i + 1][j + 1] == 0) {
                    board[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    int width = 10;
    int height = 10;

    int** board = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        board[i] = malloc(width * sizeof(int));
    }

    percolate(board, width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}