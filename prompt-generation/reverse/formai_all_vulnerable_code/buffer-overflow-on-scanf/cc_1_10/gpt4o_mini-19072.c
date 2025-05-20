//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100
#define OPEN 1
#define BLOCKED 0

typedef struct {
    int width;
    int height;
    int grid[MAX_SIZE][MAX_SIZE];
} Percolation;

void initializePercolation(Percolation *p, int width, int height) {
    p->width = width;
    p->height = height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            p->grid[i][j] = rand() % 2; // Randomly assigns OPEN or BLOCKED
        }
    }
}

void printGrid(Percolation *p) {
    for (int i = 0; i < p->height; i++) {
        for (int j = 0; j < p->width; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

bool isSiteOpen(Percolation *p, int row, int col) {
    return row >= 0 && row < p->height && col >= 0 && col < p->width && p->grid[row][col] == OPEN;
}

bool checkPercolation(Percolation *p, int row, int col, bool **visited) {
    if (row == p->height - 1) {
        return true; // Reached the bottom
    }
    visited[row][col] = true;

    // Up, Down, Left, Right directions
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    for (int i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (isSiteOpen(p, newRow, newCol) && !visited[newRow][newCol]) {
            if (checkPercolation(p, newRow, newCol, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool percolates(Percolation *p) {
    bool **visited = malloc(p->height * sizeof(bool *));
    for (int i = 0; i < p->height; i++) {
        visited[i] = malloc(p->width * sizeof(bool));
        for (int j = 0; j < p->width; j++) {
            visited[i][j] = false; // Initialize visited array
        }
    }

    // Start from all open sites at the top row
    for (int col = 0; col < p->width; col++) {
        if (p->grid[0][col] == OPEN && !visited[0][col]) {
            if (checkPercolation(p, 0, col, visited)) {
                // Free memory before return
                for (int i = 0; i < p->height; i++) {
                    free(visited[i]);
                }
                free(visited);
                return true;
            }
        }
    }

    // Free memory before return
    for (int i = 0; i < p->height; i++) {
        free(visited[i]);
    }
    free(visited);
    
    return false;
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    Percolation p;
    int width, height;

    printf("Enter the width of the grid: ");
    scanf("%d", &width);
    printf("Enter the height of the grid: ");
    scanf("%d", &height);

    if (width > MAX_SIZE || height > MAX_SIZE || width <= 0 || height <= 0) {
        printf("Invalid dimensions! Please use values between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    initializePercolation(&p, width, height);
    printf("Generated Percolation Grid:\n");
    printGrid(&p);

    if (percolates(&p)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}