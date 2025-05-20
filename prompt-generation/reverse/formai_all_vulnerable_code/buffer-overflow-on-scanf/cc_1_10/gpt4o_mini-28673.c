//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 20
#define HEIGHT 20

// Define states for each cell
#define BLOCKED 0
#define OPEN 1
#define FILLED 2

// Function prototypes
void display_grid(int grid[HEIGHT][WIDTH]);
void initialize_grid(int grid[HEIGHT][WIDTH]);
bool percolates(int grid[HEIGHT][WIDTH]);
void fill(int grid[HEIGHT][WIDTH], int x, int y);
void randomize_grid(int grid[HEIGHT][WIDTH], float density);

int main() {
    srand(time(NULL));  // Seed for random number generation
    int grid[HEIGHT][WIDTH];
    float density;

    printf("Welcome to Cyberpunk Percolation Simulator!\n");
    printf("Enter density (0.0 - 1.0): ");
    scanf("%f", &density);

    // Validate density
    while (density < 0.0f || density > 1.0f) {
        printf("Invalid input. Density should be between 0.0 - 1.0. Please re-enter: ");
        scanf("%f", &density);
    }

    // Initialize grid
    initialize_grid(grid);

    // Randomize grid with the given density
    randomize_grid(grid, density);
    
    // Display the grid
    display_grid(grid);

    // Check if the grid percolates
    if (percolates(grid)) {
        printf("The grid percolates! Water flows through the neon-lit streets!\n");
    } else {
        printf("The grid does not percolate. The system is blocked like the alleyways of the megacities.\n");
    }

    return 0;
}

// Display the grid state
void display_grid(int grid[HEIGHT][WIDTH]) {
    printf("\nCurrent Grid State:\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            switch (grid[y][x]) {
                case BLOCKED: printf("▓ "); break;
                case OPEN: printf("░ "); break;
                case FILLED: printf("★ "); break;
            }
        }
        printf("\n");
    }
}

// Initialize the grid to a blocked state
void initialize_grid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = BLOCKED;
        }
    }
}

// Randomly fill the grid based on density
void randomize_grid(int grid[HEIGHT][WIDTH], float density) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            float random_value = (float)rand() / RAND_MAX;
            if (random_value < density) {
                grid[y][x] = OPEN;
            }
        }
    }
}

// Check if the grid percolates from top to bottom
bool percolates(int grid[HEIGHT][WIDTH]) {
    for (int x = 0; x < WIDTH; x++) {
        if (grid[0][x] == OPEN) {  // Start a flood fill for every open cell in the first row
            fill(grid, 0, x);
        }
    }

    // Check if any cell in the last row has been filled
    for (int x = 0; x < WIDTH; x++) {
        if (grid[HEIGHT - 1][x] == FILLED) {
            return true;
        }
    }
    return false;
}

// Flood fill algorithm to fill connected open cells
void fill(int grid[HEIGHT][WIDTH], int x, int y) {
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT) return;       // Out of bounds
    if (grid[y][x] != OPEN) return; // Not an open cell

    grid[y][x] = FILLED; // Mark cell as filled

    // Fill area by recursively checking all adjacent cells
    fill(grid, x + 1, y);
    fill(grid, x - 1, y);
    fill(grid, x, y + 1);
    fill(grid, x, y - 1);
}