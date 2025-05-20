//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_STEPS 1000
#define DROP_PROB 0.5
#define DROP_THRESHOLD 0.1

int main() {
    int size, steps, i, j, k, num_dropped, num_threshold;
    int **grid;
    double drop_prob, drop_threshold;

    // initialize random seed
    srand(time(NULL));

    // get user input
    printf("Enter grid size (1-100): ");
    scanf("%d", &size);
    printf("Enter number of steps: ");
    scanf("%d", &steps);

    // allocate memory for grid
    grid = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // initialize grid with random values
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // get user input for drop probability and threshold
    printf("Enter drop probability (0-1): ");
    scanf("%lf", &drop_prob);
    printf("Enter drop threshold (0-1): ");
    scanf("%lf", &drop_threshold);

    // set initial number of dropped balls
    num_dropped = 0;

    // run simulation
    for (k = 0; k < steps; k++) {
        // check for threshold
        num_threshold = 0;
        for (i = 0; i < size; i++) {
            if (grid[i][0] == 1) {
                num_threshold++;
            }
        }
        if (num_threshold >= (size * drop_threshold)) {
            break;
        }

        // check for drops
        for (i = 0; i < size; i++) {
            if (grid[i][0] == 1) {
                for (j = 0; j < size; j++) {
                    if (grid[i][j] == 1 && rand() % 100 < DROP_PROB) {
                        grid[i][j] = 0;
                        num_dropped++;
                    }
                }
            }
        }
    }

    // print results
    printf("Dropped %d balls in %d steps.\n", num_dropped, k);

    // free memory
    for (i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}