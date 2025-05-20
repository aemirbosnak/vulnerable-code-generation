//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 20

void initializeGrid(int grid[HEIGHT][WIDTH]);
void displayGrid(int grid[HEIGHT][WIDTH]);
void updateGrid(int grid[HEIGHT][WIDTH]);
int countNeighbors(int grid[HEIGHT][WIDTH], int x, int y);

int main() {
    int grid[HEIGHT][WIDTH];
    char command = 'c';  // Default to 'c' for continue.
    
    printf("Conway's Game of Life\n");
    printf("Enter a starting pattern (b for blinker, g for glider, c for custom input): ");
    
    command = getchar();
    getchar();  // Clear newline

    if (command == 'b') {
        // Initialize a blinker
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
                grid[i][j] = 0;

        grid[HEIGHT / 2][WIDTH / 2 - 1] = 1;
        grid[HEIGHT / 2][WIDTH / 2] = 1;
        grid[HEIGHT / 2][WIDTH / 2 + 1] = 1;
    } else if (command == 'g') {
        // Initialize a glider
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
                grid[i][j] = 0;

        grid[HEIGHT / 2][WIDTH / 2] = 1;
        grid[HEIGHT / 2 + 1][WIDTH / 2 + 1] = 1;
        grid[HEIGHT / 2 + 1][WIDTH / 2 - 1] = 1;
        grid[HEIGHT / 2 + 2][WIDTH / 2] = 1;
        grid[HEIGHT / 2 + 2][WIDTH / 2 + 1] = 1;
    } else {
        // Custom input
        printf("Enter your custom pattern (width %d, height %d)\n", WIDTH, HEIGHT);
        initializeGrid(grid);
    }

    while (1) {
        displayGrid(grid);
        updateGrid(grid);
        usleep(500000); // Sleep for 500 milliseconds for better visibility
    }

    return 0;
}

void initializeGrid(int grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("Cell (%d, %d) alive (1) or dead (0)? ", i, j);
            scanf("%d", &grid[i][j]);
        }
    }
}

void displayGrid(int grid[HEIGHT][WIDTH]) {
    system("clear"); // Use `system("cls")` for Windows
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

void updateGrid(int grid[HEIGHT][WIDTH]) {
    int nextGen[HEIGHT][WIDTH] = {0};

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(grid, i, j);

            if (grid[i][j] == 1) {
                nextGen[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                nextGen[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            grid[i][j] = nextGen[i][j];
}

int countNeighbors(int grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int ni = (x + i + HEIGHT) % HEIGHT; // Wrap around
            int nj = (y + j + WIDTH) % WIDTH;   // Wrap around
            count += grid[ni][nj];
        }
    }

    return count;
}