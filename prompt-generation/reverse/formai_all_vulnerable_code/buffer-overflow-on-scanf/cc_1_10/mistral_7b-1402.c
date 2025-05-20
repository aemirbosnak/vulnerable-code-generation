//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIDE 10
#define SQUARE(x) ((x) * (x))

typedef struct {
    int x, y;
} point;

bool grid[SIDE][SIDE];
int open_sites;

point neighbors[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

bool in_bounds(point p) {
    return p.x >= 0 && p.x < SIDE && p.y >= 0 && p.y < SIDE;
}

void print_grid() {
    int i, j;

    for (i = 0; i < SIDE; ++i) {
        for (j = 0; j < SIDE; ++j) {
            printf(grid[i][j] ? "#" : ".");
        }
        printf("\n");
    }
}

void open_site(point p) {
    if (in_bounds(p) && !grid[p.x][p.y]) {
        grid[p.x][p.y] = true;
        open_sites++;

        for (int i = 0; i < 8; ++i) {
            point neighbor = neighbors[i];
            open_site((point){p.x + neighbor.x, p.y + neighbor.y});
        }
    }
}

int main() {
    int x, y;
    point seed;

    memset(grid, 0, sizeof(grid));
    open_sites = 0;

    printf("Enter seed coordinates (x y): ");
    scanf("%d %d", &x, &y);
    seed.x = x;
    seed.y = y;

    open_site(seed);

    print_grid();
    printf("\nOpen sites: %d\n", open_sites);

    return 0;
}