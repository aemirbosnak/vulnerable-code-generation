//Code Llama-13B DATASET v1.0 Category: Game of Life ; Style: multivariable
/*
 * Game of Life in a multivariable style
 *
 * Usage: ./game_of_life [rows] [columns] [delay]
 *
 * Runs the Game of Life simulation on a grid with the specified
 * dimensions and delay between generations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define DELAY 100000

typedef enum { DEAD, ALIVE } cell_state;

void print_grid(cell_state grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", grid[i][j] == ALIVE ? '*' : ' ');
        }
        printf("\n");
    }
}

void simulate(cell_state grid[HEIGHT][WIDTH], int rows, int cols) {
    cell_state new_grid[HEIGHT][WIDTH];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < rows && j + l >= 0 && j + l < cols) {
                        neighbors += grid[i + k][j + l] == ALIVE;
                    }
                }
            }
            if (neighbors == 3 || (neighbors == 2 && grid[i][j] == ALIVE)) {
                new_grid[i][j] = ALIVE;
            } else {
                new_grid[i][j] = DEAD;
            }
        }
    }
    memcpy(grid, new_grid, sizeof(cell_state) * rows * cols);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int delay = atoi(argv[3]);

    cell_state grid[HEIGHT][WIDTH];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2 ? ALIVE : DEAD;
        }
    }

    print_grid(grid);
    while (1) {
        simulate(grid, rows, cols);
        usleep(delay);
        system("clear");
        print_grid(grid);
    }

    return 0;
}