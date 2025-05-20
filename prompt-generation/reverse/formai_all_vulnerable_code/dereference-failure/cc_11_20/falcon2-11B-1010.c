//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

typedef struct {
    int alive;
    int x;
    int y;
} Cell;

int main(int argc, char *argv[]) {
    Cell *cells = malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(Cell));
    for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
        cells[i].alive = 0;
        cells[i].x = i % MAX_WIDTH;
        cells[i].y = i / MAX_WIDTH;
    }

    int gen = 0;
    while (gen < 100) {
        for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
            int neighbours = 0;
            for (int j = i - 1; j < i + 2; j++) {
                if (j >= 0 && j < MAX_WIDTH * MAX_HEIGHT && cells[j].alive == 1) {
                    neighbours++;
                }
            }
            if (cells[i].alive == 1 && (neighbours < 2 || neighbours > 3)) {
                cells[i].alive = 0;
            } else if (cells[i].alive == 0 && neighbours == 3) {
                cells[i].alive = 1;
            }
        }
        gen++;
    }

    for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
        if (cells[i].alive == 1) {
            printf("X ");
        } else {
            printf("  ");
        }
    }
    printf("\n");

    free(cells);

    return 0;
}