//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CELLS 1000

int main() {
    int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int i = 0; i < MAX_CELLS; i++) {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game board
    for (int i = 0; i < MAX_CELLS; i++) {
        for (int j = 0; j < MAX_CELLS; j++) {
            cells[i][j] = rand() % 2;
        }
    }

    // Simulate the game of life
    int generations = 0;
    while ( generations < 10) {
        // Calculate the next generation of cells
        for (int i = 0; i < MAX_CELLS; i++) {
            for (int j = 0; j < MAX_CELLS; j++) {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;
                        if (cells[i + x][j + y] == 1) neighbors++;
                    }
                }
                cells[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            }
        }

        // Print the game board
        for (int i = 0; i < MAX_CELLS; i++) {
            for (int j = 0; j < MAX_CELLS; j++) {
                printf("%d ", cells[i][j]);
            }
            printf("\n");
        }

        // Increment the number of generations
        generations++;
    }

    // Free the memory
    for (int i = 0; i < MAX_CELLS; i++) {
        free(cells[i]);
    }
    free(cells);

    return 0;
}