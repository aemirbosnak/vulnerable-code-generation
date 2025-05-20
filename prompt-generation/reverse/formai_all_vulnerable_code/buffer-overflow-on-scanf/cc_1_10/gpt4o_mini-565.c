//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50
#define WALL 'W'
#define PATH ' '
#define WATER 'WATER'
#define SOURCE 'S'
#define SINK 'D'

typedef struct {
    char grid[MAX_SIZE][MAX_SIZE];
    int size;
    int sourceRow, sourceCol;
    int sinkRow, sinkCol;
} Kingdom;

// Function prototypes
void initializeKingdom(Kingdom *k, int size);
void displayKingdom(Kingdom *k);
void createSourceSink(Kingdom *k);
void simulatePercolation(Kingdom *k);
void spreadWater(Kingdom *k, int row, int col);
int isValidPosition(Kingdom *k, int row, int col);

// Main function
int main() {
    srand(time(NULL));
    Kingdom kingdom;
    int size;

    printf("Enter the size of the kingdom (between 5 and 50): ");
    scanf("%d", &size);

    if (size < 5 || size > MAX_SIZE) {
        printf("The size must be between 5 and 50.\n");
        return 1;
    }

    initializeKingdom(&kingdom, size);
    createSourceSink(&kingdom);
    displayKingdom(&kingdom);
    simulatePercolation(&kingdom);
    displayKingdom(&kingdom);

    return 0;
}

// Initializes the kingdom with walls and paths
void initializeKingdom(Kingdom *k, int size) {
    k->size = size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (rand() % 4 == 0) {
                k->grid[i][j] = WALL; // 25% chance to place a wall
            } else {
                k->grid[i][j] = PATH; // Place a path
            }
        }
    }
}

// Displays the current state of the kingdom
void displayKingdom(Kingdom *k) {
    printf("\nKingdom State:\n");
    for (int i = 0; i < k->size; i++) {
        for (int j = 0; j < k->size; j++) {
            printf("%c ", k->grid[i][j]);
        }
        printf("\n");
    }
}

// Creates a water source and a destination in the kingdom
void createSourceSink(Kingdom *k) {
    k->sourceRow = rand() % (k->size / 2);
    k->sourceCol = rand() % k->size;
    k->sinkRow = (k->size / 2) + (rand() % (k->size / 2));
    k->sinkCol = rand() % k->size;

    k->grid[k->sourceRow][k->sourceCol] = SOURCE;
    k->grid[k->sinkRow][k->sinkCol] = SINK;

    printf("Source created at (%d, %d) and Sink created at (%d, %d)\n", k->sourceRow, k->sourceCol, k->sinkRow, k->sinkCol);
}

// Simulates the percolation process
void simulatePercolation(Kingdom *k) {
    printf("Water begins its journey...\n");
    spreadWater(k, k->sourceRow, k->sourceCol);
}

// Spreads water through the kingdom
void spreadWater(Kingdom *k, int row, int col) {
    if (!isValidPosition(k, row, col) || k->grid[row][col] != PATH) {
        return;
    }

    k->grid[row][col] = WATER;

    // Recursive call for adjacent cells
    spreadWater(k, row - 1, col); // Up
    spreadWater(k, row + 1, col); // Down
    spreadWater(k, row, col - 1); // Left
    spreadWater(k, row, col + 1); // Right
}

// Checks if the position is within the kingdom's bounds and not a wall
int isValidPosition(Kingdom *k, int row, int col) {
    return (row >= 0 && row < k->size && col >= 0 && col < k->size && k->grid[row][col] != WALL);
}