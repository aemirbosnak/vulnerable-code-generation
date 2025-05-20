//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define NUM_RUNS 10

int main() {
    srand(time(NULL));

    int size = rand() % MAX_SIZE + 1;
    int runs = rand() % NUM_RUNS + 1;

    int **grid = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *) malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    for (int run = 0; run < runs; run++) {
        int top = 0;
        int bottom = size - 1;
        while (top < bottom) {
            int rand_row = rand() % size;
            int rand_col = rand() % size;

            if (grid[rand_row][rand_col] == 1) {
                grid[rand_row][rand_col] = 0;
                if (rand_row > top) {
                    top = rand_row;
                }
            } else {
                grid[rand_row][rand_col] = 1;
                if (rand_row < bottom) {
                    bottom = rand_row;
                }
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}