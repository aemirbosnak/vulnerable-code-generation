//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int size;
    int rows;
    int cols;
    int num_occupied;
    int* grid;
} Grid;

int main() {
    int num_sites = 1000;
    int num_neighbors = 4;
    int seed = 1;
    srand(seed);

    Grid* grid = (Grid*)malloc(sizeof(Grid));
    grid->size = num_sites;
    grid->rows = 10;
    grid->cols = 10;
    grid->num_occupied = 0;
    grid->grid = (int*)malloc(grid->size * grid->size * sizeof(int));

    int* visited = (int*)malloc(grid->size * grid->size * sizeof(int));
    int* neighbors = (int*)malloc(grid->size * grid->size * sizeof(int));

    for (int i = 0; i < grid->size * grid->size; i++) {
        visited[i] = 0;
        neighbors[i] = 0;
    }

    for (int i = 0; i < grid->size * grid->size; i++) {
        int r = i / grid->cols;
        int c = i % grid->cols;

        if (rand() % 100 < 10) {
            grid->grid[i] = 1;
            grid->num_occupied++;
        }
    }

    for (int i = 0; i < grid->size * grid->size; i++) {
        if (grid->grid[i] == 1) {
            neighbors[i] = 0;
        } else {
            neighbors[i] = 0;
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    if (j == 0 && k == 0) {
                        continue;
                    }
                    int r = i + j;
                    int c = c + k;

                    if (r >= 0 && r < grid->rows && c >= 0 && c < grid->cols) {
                        if (grid->grid[i + j * grid->cols + k * grid->cols] == 1) {
                            neighbors[i]++;
                        }
                    }
                }
            }
        }
    }

    int percolation_threshold = 0;
    int num_connected = 0;

    for (int i = 0; i < grid->size * grid->size; i++) {
        if (visited[i] == 0 && neighbors[i] >= num_neighbors) {
            visited[i] = 1;
            num_connected++;
        }
    }

    percolation_threshold = num_connected / grid->num_occupied;

    printf("Percolation Threshold: %.2f\n", percolation_threshold);

    free(grid->grid);
    free(visited);
    free(neighbors);
    free(grid);

    return 0;
}