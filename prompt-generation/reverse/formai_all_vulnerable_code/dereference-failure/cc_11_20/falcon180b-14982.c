//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define DROP_PROB 0.5
#define DROP_COUNT 100

int main() {
    int size = MAX_SIZE;
    int **grid = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    int drops = 0;
    while (drops < DROP_COUNT) {
        int x = rand() % size;
        int y = rand() % size;

        if (grid[x][y] == 0) {
            grid[x][y] = 1;
            drops++;
        }
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }

    printf("Grid has %d drops and %d total sites.\n", drops, count);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}