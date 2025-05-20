//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_DROPS 1000
#define MAX_TIME 1000

int percolation(int size, int drops) {
    int **grid = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }

    int top = 0;
    int bottom = size - 1;
    int left = 0;
    int right = size - 1;

    for (int i = 0; i < drops; i++) {
        int x = rand() % size;
        int y = rand() % size;

        if (x == left) {
            grid[0][y] = 1;
            top--;
        } else if (x == right) {
            grid[size - 1][y] = 1;
            bottom++;
        } else if (y == top) {
            grid[x][0] = 1;
            left++;
        } else if (y == bottom) {
            grid[x][size - 1] = 1;
            right--;
        } else {
            if (grid[x][y - 1] == 1) {
                grid[x][y] = 1;
            } else if (grid[x - 1][y] == 1) {
                grid[x][y] = 1;
            }
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

    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return count;
}

int main() {
    srand(time(NULL));

    int size = MAX_SIZE;
    int drops = MAX_DROPS;
    int time = MAX_TIME;

    int count = 0;
    int start_time = clock();

    while (count < time) {
        int result = percolation(size, drops);
        count += result;
    }

    double end_time = (double)clock() - start_time;
    double seconds = end_time / CLOCKS_PER_SEC;

    printf("Time taken: %.2f seconds\n", seconds);

    return 0;
}