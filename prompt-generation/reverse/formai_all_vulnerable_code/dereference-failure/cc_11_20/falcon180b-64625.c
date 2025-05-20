//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50
#define P 0.5
#define NUM_TRIALS 100

int main() {
    int i, j, k, count = 0;
    int **grid;
    int top = 0, bottom = SIZE - 1;
    int left = 0, right = SIZE - 1;

    srand(time(0));

    grid = (int **)malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        grid[i] = (int *)malloc(SIZE * sizeof(int));
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    for (k = 0; k < NUM_TRIALS; k++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (grid[x][y] == 0 && y > 0 && grid[x][y - 1] == 1) {
            grid[x][y] = 1;
            count++;
        }
    }

    printf("Number of sites: %d\n", count);

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}