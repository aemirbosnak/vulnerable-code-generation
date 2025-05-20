//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 20

void initializeGrid(int grid[HEIGHT][WIDTH]);
void printGrid(int grid[HEIGHT][WIDTH]);
void updateGrid(int grid[HEIGHT][WIDTH]);
int countNeighbors(int grid[HEIGHT][WIDTH], int x, int y);

int main() {
    int grid[HEIGHT][WIDTH];

    initializeGrid(grid);
    while (1) {
        system("clear"); // Clear the console; works in Linux
        printGrid(grid);
        updateGrid(grid);
        usleep(200000); // Sleep for 200 milliseconds to slow down the simulation
    }

    return 0;
}

void initializeGrid(int grid[HEIGHT][WIDTH]) {
    printf("Welcome to Conway's Game of Life\n");
    printf("Please enter the initial configuration (20x20 grid, 1 for alive, 0 for dead):\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

void printGrid(int grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j] ? 'O' : '.');
        }
        printf("\n");
    }
}

void updateGrid(int grid[HEIGHT][WIDTH]) {
    int newGrid[HEIGHT][WIDTH] = {0};
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(grid, i, j);
            
            // Apply the Game of Life rules
            if (grid[i][j] == 1) {
                newGrid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0; // Survival
            } else {
                newGrid[i][j] = (neighbors == 3) ? 1 : 0; // Birth
            }
        }
    }

    // Update the original grid
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int countNeighbors(int grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int nx = x + i;
            int ny = y + j;
            // Wrap around edges
            if (nx < 0) nx += HEIGHT;
            if (ny < 0) ny += WIDTH;
            if (nx >= HEIGHT) nx -= HEIGHT;
            if (ny >= WIDTH) ny -= WIDTH;

            count += grid[nx][ny];
        }
    }
    return count;
}