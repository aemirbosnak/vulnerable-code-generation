//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 20

char grid[HEIGHT][WIDTH];

void initialize_grid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = '.';
        }
    }

    // Add some knights (alive cells)
    grid[1][1] = 'K';
    grid[1][2] = 'K';
    grid[2][1] = 'K';
    grid[5][5] = 'K';
    grid[6][5] = 'K';
    grid[7][5] = 'K';
}

void print_grid() {
    printf("\n--- Kingdom of Life ---\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(grid[y][x]);
        }
        putchar('\n');
    }
    printf("-----------------------\n");
}

int count_neighbors(int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue; // skip itself
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < WIDTH && ny < HEIGHT) {
                if (grid[ny][nx] == 'K') count++;
            }
        }
    }
    return count;
}

void update_grid() {
    char new_grid[HEIGHT][WIDTH];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = count_neighbors(x, y);

            if (grid[y][x] == 'K') {
                // A knight with two or three neighbors survives
                new_grid[y][x] = (neighbors == 2 || neighbors == 3) ? 'K' : '.';
            } else {
                // A dead cell becomes a knight if exactly three neighbors
                new_grid[y][x] = (neighbors == 3) ? 'K' : '.';
            }
        }
    }

    // Update the grid to the new configuration
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = new_grid[y][x];
        }
    }
}

int main() {
    int generations;
    printf("Welcome to the Kingdom of Life!\n");
    printf("Enter number of generations to simulate: ");
    scanf("%d", &generations);

    initialize_grid();
    
    for (int gen = 0; gen < generations; gen++) {
        print_grid();
        update_grid();
        usleep(500000); // Delay for half a second
    }

    printf("The kingdom has prospered!\n");
    return 0;
}