//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//A wrapper around calloc
void* calloc2D(int m, int n, int size){
    int* p = calloc(m*n, size);
    if(p == NULL){
        exit(1);
    }
    return p;
}

int main() {
    //Initialize random number generator
    srand(time(NULL));

    //Board dimensions
    int m = 20, n = 20;

    //Initialize board and copy
    int *board = calloc2D(m, n, sizeof(int));
    int *copy = calloc2D(m, n, sizeof(int));

    //Assign initial random values (0 or 1)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i * n + j] = rand() % 2;
        }
    }

    //Game loop
    int max_iter=1000;
    while(max_iter--){
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Get the number of alive neighbors
                int alive_neighbors = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            alive_neighbors += board[x * n + y];
                        }
                    }
                }
                // Apply the rules of the game of life
                if (board[i * n + j] == 1) {
                    if (alive_neighbors < 2 || alive_neighbors > 3) {
                        copy[i * n + j] = 0;
                    } else {
                        copy[i * n + j] = 1;
                    }
                } else {
                    if (alive_neighbors == 3) {
                        copy[i * n + j] = 1;
                    } else {
                        copy[i * n + j] = 0;
                    }
                }
            }
        }
        //Copy the new board to the original board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i * n + j] = copy[i * n + j];
            }
        }
    }

    //Print the final board
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i * n + j]);
        }
        printf("\n");
    }

    //Free memory
    free(board);
    free(copy);
    return 0;
}