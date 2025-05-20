//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define PROBABILITY 0.5
#define MAX_TRIALS 100000

int main() {
    int i, j, trials = 0;
    int **grid;
    int top, bottom, left, right;
    int percolated = 0;
    srand(time(NULL));

    grid = (int **) malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        grid[i] = (int *) malloc(SIZE * sizeof(int));
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < SIZE; i++) {
        top = rand() % SIZE;
        bottom = rand() % SIZE;
        left = rand() % SIZE;
        right = rand() % SIZE;

        if (grid[i][top] == 0 && grid[i][bottom] == 0) {
            grid[i][top] = 1;
            grid[i][bottom] = 1;
            percolated = 1;
        }

        if (grid[i][left] == 0 && grid[i][right] == 0) {
            grid[i][left] = 1;
            grid[i][right] = 1;
            percolated = 1;
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                trials++;
                if (trials <= MAX_TRIALS) {
                    while (trials <= MAX_TRIALS) {
                        if (rand() % 2 == 1) {
                            grid[i][j] = 1;
                            percolated = 1;
                            break;
                        }
                        trials++;
                    }
                }
            }
        }
    }

    printf("Percolation occurred: %s\n", percolated? "Yes" : "No");

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}