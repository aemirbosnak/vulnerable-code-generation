//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 64
#define CELL_SIZE (sizeof(char) * WIDTH)

typedef struct {
    char alive;
    char x, y;
} Cell;

Cell* grid;

void print_grid() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (grid[y * WIDTH + x].alive)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

int count_neighbours(int x, int y) {
    int counter = 0;

    for (int i = y - 1; i <= y + 1; ++i) {
        for (int j = x - 1; j <= x + 1; ++j) {
            if (i == y && j == x)
                continue;

            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH) {
                if (grid[i * WIDTH + j].alive)
                    ++counter;
            }
        }
    }

    return counter;
}

void next_generation() {
    Cell temp_grid[WIDTH * HEIGHT];

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int neighbours = count_neighbours(x, y);

            if (grid[y * WIDTH + x].alive) {
                if (neighbours < 2 || neighbours > 3)
                    temp_grid[y * WIDTH + x].alive = 0;
            } else {
                if (neighbours == 3)
                    temp_grid[y * WIDTH + x].alive = 1;
            }
        }
    }

    grid = temp_grid;
}

int main() {
    int seed;
    printf("Enter a seed for random initialization: ");
    scanf("%d", &seed);
    srand(seed);

    grid = mmap(NULL, WIDTH * CELL_SIZE * HEIGHT, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            grid[y * WIDTH + x].alive = rand() % 2;
        }
    }

    clock_t start = clock();

    for (int i = 0; i < 50; ++i) {
        print_grid();
        next_generation();
        usleep(100000); // 100ms delay between generations
    }

    munmap(grid, WIDTH * CELL_SIZE * HEIGHT);

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nGame of Life simulation completed in %.2f seconds.\n", time_taken);

    return 0;
}