//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    int width, height, num_drops;
    Point top_left, bottom_right;
    int **grid;
    int x, y, count = 0;
    int i, j;

    srand(time(NULL));
    printf("Enter the width of the grid: ");
    scanf("%d", &width);
    printf("Enter the height of the grid: ");
    scanf("%d", &height);
    printf("Enter the number of drops: ");
    scanf("%d", &num_drops);

    top_left.x = 0;
    top_left.y = 0;
    bottom_right.x = width - 1;
    bottom_right.y = height - 1;

    grid = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        grid[i] = (int *)malloc(width * sizeof(int));
        for (j = 0; j < width; j++) {
            grid[i][j] = 0;
        }
    }

    for (i = 0; i < num_drops; i++) {
        x = rand() % width;
        y = rand() % height;
        while (grid[y][x] == 1) {
            x = rand() % width;
            y = rand() % height;
        }
        grid[y][x] = 1;
        count++;
    }

    printf("The grid has %d occupied cells.\n", count);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    free(grid[0]);
    free(grid);

    return 0;
}