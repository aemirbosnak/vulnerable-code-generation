//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define WIDTH (CELL_SIZE * 10)
#define HEIGHT (CELL_SIZE * 10)

typedef struct cell {
    int alive;
    int neighbors_alive[8];
} cell_t;

cell_t cells[WIDTH * HEIGHT];

void init_cells(void) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            cells[i * HEIGHT + j].alive = (i % 2 == 0) && (j % 2 == 0);
            cells[i * HEIGHT + j].neighbors_alive[0] = cells[i * HEIGHT + j].alive;
            cells[i * HEIGHT + j].neighbors_alive[1] = cells[i * HEIGHT + j - 1].alive;
            cells[i * HEIGHT + j].neighbors_alive[2] = cells[i * HEIGHT + j + 1].alive;
            cells[i * HEIGHT + j].neighbors_alive[3] = cells[i * HEIGHT + j - CELL_SIZE].alive;
            cells[i * HEIGHT + j].neighbors_alive[4] = cells[i * HEIGHT + j + CELL_SIZE].alive;
            cells[i * HEIGHT + j].neighbors_alive[5] = cells[i * HEIGHT + j - CELL_SIZE + 1].alive;
            cells[i * HEIGHT + j].neighbors_alive[6] = cells[i * HEIGHT + j + CELL_SIZE - 1].alive;
            cells[i * HEIGHT + j].neighbors_alive[7] = cells[i * HEIGHT + j - 2].alive;
            cells[i * HEIGHT + j].neighbors_alive[8] = cells[i * HEIGHT + j + 2].alive;
        }
    }
}

void update_cells(void) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (cells[i * HEIGHT + j].alive && cells[i * HEIGHT + j].neighbors_alive[0] &&
                    cells[i * HEIGHT + j].neighbors_alive[1] && cells[i * HEIGHT + j].neighbors_alive[2] &&
                    cells[i * HEIGHT + j].neighbors_alive[3] && cells[i * HEIGHT + j].neighbors_alive[4] &&
                    cells[i * HEIGHT + j].neighbors_alive[5] && cells[i * HEIGHT + j].neighbors_alive[6] &&
                    cells[i * HEIGHT + j].neighbors_alive[7]) {
                cells[i * HEIGHT + j].alive = 1;
            } else if (!cells[i * HEIGHT + j].alive && cells[i * HEIGHT + j].neighbors_alive[0] &&
                    cells[i * HEIGHT + j].neighbors_alive[1] && cells[i * HEIGHT + j].neighbors_alive[2] &&
                    cells[i * HEIGHT + j].neighbors_alive[3] && cells[i * HEIGHT + j].neighbors_alive[4] &&
                    cells[i * HEIGHT + j].neighbors_alive[5] && cells[i * HEIGHT + j].neighbors_alive[6] &&
                    cells[i * HEIGHT + j].neighbors_alive[7]) {
                cells[i * HEIGHT + j].alive = 0;
            } else {
                cells[i * HEIGHT + j].alive = 0;
            }
        }
    }
}

int main(void) {
    init_cells();
    update_cells();
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (cells[i].alive) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}