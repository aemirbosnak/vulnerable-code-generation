//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 100

void initialize_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols);
void print_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols);
void update_grid(int grid[MAX_SIZE][MAX_SIZE], int new_grid[MAX_SIZE][MAX_SIZE], int rows, int cols);
int count_live_neighbors(int grid[MAX_SIZE][MAX_SIZE], int x, int y, int rows, int cols);
void clear_screen();

int main() {
    int rows, cols;
    int grid[MAX_SIZE][MAX_SIZE];
    int new_grid[MAX_SIZE][MAX_SIZE];
    
    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    if (rows > MAX_SIZE || cols > MAX_SIZE || rows < 1 || cols < 1) {
        printf("Invalid input! Exiting...\n");
        return 1;
    }

    initialize_grid(grid, rows, cols);
    printf("Initial Grid:\n");
    print_grid(grid, rows, cols);
    
    char command;
    printf("Press 'r' to run the simulation or 'q' to quit: ");
    while ((command = getchar()) == '\n'); // clear buffer
    if (command == 'q') return 0;

    while(1) {
        clear_screen();
        update_grid(grid, new_grid, rows, cols);
        memcpy(grid, new_grid, sizeof(new_grid));
        print_grid(grid, rows, cols);
        usleep(500000); // sleep for half a second
        printf("Press 'q' to quit or any other key to continue: ");
        if ((command = getchar()) == 'q') break; // exit on 'q'
    }

    return 0;
}

void initialize_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter your initial grid (0 for dead, 1 for alive):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

void print_grid(int grid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j] ? 'O' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

void update_grid(int grid[MAX_SIZE][MAX_SIZE], int new_grid[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int live_neighbors = count_live_neighbors(grid, i, j, rows, cols);
            if (grid[i][j] == 1) {
                new_grid[i][j] = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (live_neighbors == 3) ? 1 : 0;
            }
        }
    }
}

int count_live_neighbors(int grid[MAX_SIZE][MAX_SIZE], int x, int y, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int new_x = x + i;
            int new_y = y + j;
            if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                count += grid[new_x][new_y];
            }
        }
    }
    return count;
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
    fflush(stdout);
}