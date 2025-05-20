//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int width;
    int height;
    int n;
    int* grid;
} Percolation;

void init_percolation(Percolation* perc, int width, int height) {
    perc->width = width;
    perc->height = height;
    perc->n = width * height;
    perc->grid = (int*)malloc(perc->n * sizeof(int));
    for (int i = 0; i < perc->n; i++) {
        perc->grid[i] = 0;
    }
}

void free_percolation(Percolation* perc) {
    free(perc->grid);
}

void set_position(Percolation* perc, Position pos, int value) {
    perc->grid[pos.y * perc->width + pos.x] = value;
}

int get_position(Percolation* perc, Position pos) {
    return perc->grid[pos.y * perc->width + pos.x];
}

void random_fill(Percolation* perc) {
    srand(time(NULL));
    for (int i = 0; i < perc->n; i++) {
        perc->grid[i] = rand() % 2;
    }
}

void percolation_simulation(Percolation* perc, int steps) {
    for (int i = 0; i < steps; i++) {
        for (int j = 0; j < perc->n; j++) {
            Position pos;
            pos.x = j % perc->width;
            pos.y = j / perc->width;
            if (get_position(perc, pos) == 1) {
                set_position(perc, pos, 0);
                if (pos.y == 0) {
                    set_position(perc, pos, 1);
                } else if (pos.y == perc->height - 1) {
                    set_position(perc, pos, 1);
                } else {
                    Position up, down;
                    up.x = pos.x;
                    up.y = pos.y - 1;
                    down.x = pos.x;
                    down.y = pos.y + 1;
                    if (get_position(perc, up) == 1 || get_position(perc, down) == 1) {
                        set_position(perc, pos, 1);
                    }
                }
            }
        }
    }
}

int main() {
    Percolation perc;
    init_percolation(&perc, 10, 10);
    random_fill(&perc);
    percolation_simulation(&perc, 100);
    free_percolation(&perc);
    return 0;
}