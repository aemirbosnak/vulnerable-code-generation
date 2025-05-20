//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 30
#define HEIGHT 15

void initialize_grid(int grid[HEIGHT][WIDTH]);
void display_grid(int grid[HEIGHT][WIDTH]);
void update_grid(int grid[HEIGHT][WIDTH], int new_grid[HEIGHT][WIDTH]);
int count_neighbors(int grid[HEIGHT][WIDTH], int x, int y);
void pause_execution();

int main() {
    int grid[HEIGHT][WIDTH];
    int new_grid[HEIGHT][WIDTH];
    char choice;

    printf("Welcome to the Game of Life!\n");
    printf("Here, cells live, die, and interact.\n");
    printf("Press 'G' to begin a new random game, or 'Q' to quit: ");
    scanf(" %c", &choice);

    if (choice == 'G' || choice == 'g') {
        initialize_grid(grid);
        display_grid(grid);

        while (1) {
            update_grid(grid, new_grid);
            display_grid(new_grid);

            // Copy new_grid back to grid for the next iteration
            for (int i = 0; i < HEIGHT; ++i) {
                for (int j = 0; j < WIDTH; ++j) {
                    grid[i][j] = new_grid[i][j];
                }
            }
            pause_execution();
        }
    } else {
        printf("Exiting the Game of Life. Remember, life goes on...\n");
        return 0;
    }

    return 0;
}

void initialize_grid(int grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            grid[i][j] = rand() % 2; // Randomly assign 0 or 1
        }
    }
}

void display_grid(int grid[HEIGHT][WIDTH]) {
    system("clear"); // Clear the console
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%c", grid[i][j] ? 'O' : '.'); // Alive cell is 'O', dead cell is '.'
        }
        printf("\n");
    }
}

void update_grid(int grid[HEIGHT][WIDTH], int new_grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int alive_neighbors = count_neighbors(grid, i, j);

            if (grid[i][j] == 1) { // Cell is alive
                new_grid[i][j] = (alive_neighbors == 2 || alive_neighbors == 3) ? 1 : 0;
            } else { // Cell is dead
                new_grid[i][j] = (alive_neighbors == 3) ? 1 : 0;
            }
        }
    }
}

int count_neighbors(int grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int ni = (x + i + HEIGHT) % HEIGHT; // Wrapping around the grid
            int nj = (y + j + WIDTH) % WIDTH; // Wrapping around the grid
            count += grid[ni][nj];
        }
    }
    return count;
}

void pause_execution() {
    usleep(300000); // Pause for 300 milliseconds
}