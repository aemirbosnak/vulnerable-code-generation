//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 64
#define HEIGHT 64

typedef struct {
    int alive;
    int x, y;
} cell;

cell grid[HEIGHT][WIDTH];

int count_neighbors(int x, int y) {
    int count = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i < 0 || i >= WIDTH || j < 0 || j >= HEIGHT) continue;
            if (i == x && j == y) continue;
            count += grid[j][i].alive;
        }
    }

    return count;
}

void next_generation() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = count_neighbors(j, i);

            if (grid[i][j].alive) {
                if (neighbors < 2 || neighbors > 3) {
                    grid[i][j].alive = 0;
                }
            } else {
                if (neighbors == 3) {
                    grid[i][j].alive = 1;
                }
            }
        }
    }
}

void print_grid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j].alive) printf("#");
            else printf(".");
        }
        printf("\n");
    }
}

int main() {
    memset(grid, 0, sizeof(grid));

    int x, y;
    scanf("%d %d", &x, &y);

    grid[y][x].alive = 1;

    for (int i = 0; i < 10; i++) {
        next_generation();
        print_grid();
        printf("\n");
    }

    return 0;
}