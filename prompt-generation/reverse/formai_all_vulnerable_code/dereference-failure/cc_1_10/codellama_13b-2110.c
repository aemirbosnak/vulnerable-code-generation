//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int x;
    int y;
} Cell;

Cell* cells;

void print_cells(Cell* cells, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (cells[y * width + x].x == 1 && cells[y * width + x].y == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void update_cells(Cell* cells, int width, int height) {
    Cell* new_cells = malloc(width * height * sizeof(Cell));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int alive_neighbors = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dy == 0 && dx == 0) {
                        continue;
                    }
                    int neighbor_x = (x + dx + width) % width;
                    int neighbor_y = (y + dy + height) % height;
                    if (cells[neighbor_y * width + neighbor_x].x == 1 && cells[neighbor_y * width + neighbor_x].y == 1) {
                        alive_neighbors++;
                    }
                }
            }
            if (alive_neighbors == 3) {
                new_cells[y * width + x].x = 1;
                new_cells[y * width + x].y = 1;
            } else if (alive_neighbors == 2 && cells[y * width + x].x == 1 && cells[y * width + x].y == 1) {
                new_cells[y * width + x].x = 1;
                new_cells[y * width + x].y = 1;
            } else {
                new_cells[y * width + x].x = 0;
                new_cells[y * width + x].y = 0;
            }
        }
    }
    memcpy(cells, new_cells, width * height * sizeof(Cell));
    free(new_cells);
}

int main() {
    srand(time(NULL));
    cells = malloc(WIDTH * HEIGHT * sizeof(Cell));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        cells[i].x = 0;
        cells[i].y = 0;
    }
    for (int i = 0; i < 1000000; i++) {
        update_cells(cells, WIDTH, HEIGHT);
    }
    print_cells(cells, WIDTH, HEIGHT);
    free(cells);
    return 0;
}