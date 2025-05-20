//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10
#define OPEN 1
#define BLOCKED 0

char grid[SIZE][SIZE];
int visited[SIZE][SIZE];

void initializeGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = BLOCKED;
            visited[i][j] = 0;
        }
    }
}

void randomizeGrid(float probability) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((float) rand() / RAND_MAX < probability) {
                grid[i][j] = OPEN; 
            } else {
                grid[i][j] = BLOCKED; 
            }
        }
    }
}

void printGrid() {
    printf("Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == OPEN) {
                printf(" O "); // Open site
            } else {
                printf(" X "); // Blocked site
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isValid(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && !visited[x][y] && grid[x][y] == OPEN);
}

void percolate(int x, int y) {
    // Mark the current site as visited
    visited[x][y] = 1;

    // Check if we've reached the bottom row
    if (x == SIZE - 1) {
        printf("Water has reached the bottom at (%d, %d)!\n", x, y);
        return;
    }

    // Directions for right, down, left, up
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    // Explore neighbors
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        
        if (isValid(newX, newY)) {
            percolate(newX, newY);
        }
    }
}

void startPercolation() {
    // Try to start from every open site in the first row
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] == OPEN) {
            printf("Starting percolation from (0, %d)\n", j);
            percolate(0, j);
            // Reset the visited array for new percolation trials
            for (int x = 0; x < SIZE; x++) {
                for (int y = 0; y < SIZE; y++) {
                    visited[x][y] = 0; 
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to the C Percolation Simulator!\n");
    float openProbability;
    printf("Enter the open site probability (0.0 - 1.0): ");
    scanf("%f", &openProbability);

    initializeGrid();
    randomizeGrid(openProbability);
    printGrid();
    startPercolation();

    return 0;
}