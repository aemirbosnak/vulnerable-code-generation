//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 10

void initialize_grid(int grid[HEIGHT][WIDTH]);
void display_grid(int grid[HEIGHT][WIDTH]);
void update_grid(int grid[HEIGHT][WIDTH]);
int count_neighbors(int grid[HEIGHT][WIDTH], int x, int y);
void copy_grid(int src[HEIGHT][WIDTH], int dest[HEIGHT][WIDTH]);

int main() {
    int grid[HEIGHT][WIDTH];
    int temp_grid[HEIGHT][WIDTH];
    char choice;

    // Inquiring about the initial state of the grid
    printf("Welcome to the Game of Life!\n");
    printf("Would you like to initialize the grid randomly or manually? (r/m): ");
    scanf(" %c", &choice);

    if (choice == 'r') {
        // Random initialization
        printf("Initializing grid randomly...\n");
        srand(time(0));
        initialize_grid(grid);
    } else if (choice == 'm') {
        // Manual initialization
        printf("Initializing grid manually...\n");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("Cell (%d,%d) - Alive (1) or Dead (0)? ", i, j);
                scanf("%d", &grid[i][j]);
            }
        }
    } else {
        printf("Invalid choice, defaulting to random initialization.\n");
        srand(time(0));
        initialize_grid(grid);
    }

    // Start the simulation
    while (1) {
        printf("\nCurrent Generation:\n");
        display_grid(grid);
        update_grid(grid);
        sleep(1); // Pause for better viewing
    }

    return 0;
}

void initialize_grid(int grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2; // Randomly assign cells alive or dead
        }
    }
}

void display_grid(int grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1)
                printf("▓ "); // Alive cell representation
            else
                printf("░ "); // Dead cell representation
        }
        printf("\n");
    }
}

void update_grid(int grid[HEIGHT][WIDTH]) {
    int new_grid[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] == 1) {
                // Any live cell with two or three live neighbors survives
                new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0; 
            } else {
                // Any dead cell with exactly three live neighbors becomes a live cell
                new_grid[i][j] = (neighbors == 3) ? 1 : 0; 
            }
        }
    }
    
    // Copy new grid state to the original grid
    copy_grid(new_grid, grid);
}

int count_neighbors(int grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int nx = x + i, ny = y + j;
            if (nx >= 0 && ny >= 0 && nx < HEIGHT && ny < WIDTH) {
                count += grid[nx][ny];
            }
        }
    }
    return count;
}

void copy_grid(int src[HEIGHT][WIDTH], int dest[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            dest[i][j] = src[i][j];
        }
    }
}