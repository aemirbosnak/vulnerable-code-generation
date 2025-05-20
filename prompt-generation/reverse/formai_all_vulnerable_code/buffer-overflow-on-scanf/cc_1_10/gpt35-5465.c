//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define grid size
#define GRID_SIZE 10

// Define function to initialize grid with random values
void init_grid(int grid[GRID_SIZE][GRID_SIZE], int p) {
    srand(time(NULL));
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            int random_num = rand() % 100;
            if (random_num < p) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// Define function to print grid
void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

// Define function to check if site is open
int is_open(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (grid[row][col] == 0) {
        return 0;
    }

    // Check if site is connected to the top row
    int visited[GRID_SIZE][GRID_SIZE] = {0};
    int stack[GRID_SIZE*GRID_SIZE][2];
    int top = 0;
    stack[top][0] = row;
    stack[top][1] = col;
    visited[row][col] = 1;
    while (top >= 0) {
        int r = stack[top][0];
        int c = stack[top][1];
        top--;
        if (r == 0) {
            return 1;
        }
        if (r-1 >= 0 && grid[r-1][c] == 1 && !visited[r-1][c]) {
            visited[r-1][c] = 1;
            top++;
            stack[top][0] = r-1;
            stack[top][1] = c;
        }
        if (c-1 >= 0 && grid[r][c-1] == 1 && !visited[r][c-1]) {
            visited[r][c-1] = 1;
            top++;
            stack[top][0] = r;
            stack[top][1] = c-1;
        }
        if (c+1 < GRID_SIZE && grid[r][c+1] == 1 && !visited[r][c+1]) {
            visited[r][c+1] = 1;
            top++;
            stack[top][0] = r;
            stack[top][1] = c+1;
        }
        if (r+1 < GRID_SIZE && grid[r+1][c] == 1 && !visited[r+1][c]) {
            visited[r+1][c] = 1;
            top++;
            stack[top][0] = r+1;
            stack[top][1] = c;
        }
    }
    return 0;
}

// Define function to simulate percolation
int simulate_percolation(int grid[GRID_SIZE][GRID_SIZE], int p) {
    init_grid(grid, p);
    for (int i=0; i<GRID_SIZE; i++) {
        if (is_open(grid, GRID_SIZE-1, i)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Initialize grid
    int grid[GRID_SIZE][GRID_SIZE] = {0};

    // Get probability from each player
    float prob[2];
    printf("Player 1, enter probability (0-100): ");
    scanf("%f", &prob[0]);
    printf("Player 2, enter probability (0-100): ");
    scanf("%f", &prob[1]);

    // Simulate percolation
    int winner, is_percolated;
    for (int i=0; i<2; i++) {
        is_percolated = simulate_percolation(grid, (int)prob[i]);
        if (is_percolated) {
            winner = i+1;
            break;
        }
    }

    // Print grid and winner
    printf("Final grid:\n");
    print_grid(grid);
    printf("Player %d wins!\n", winner);

    return 0;
}