//GPT-4o-mini DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5

void printGrid(char grid[GRID_SIZE][GRID_SIZE], int playerX, int playerY) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("[P] "); // Player
            } else {
                printf("[%c] ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '*'; // Mark all positions with '*'
        }
    }
}

void placeTreasure(int *treasureX, int *treasureY) {
    *treasureX = rand() % GRID_SIZE;
    *treasureY = rand() % GRID_SIZE;
}

int calculateDistance(int playerX, int playerY, int treasureX, int treasureY) {
    return abs(playerX - treasureX) + abs(playerY - treasureY);
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int playerX = 0, playerY = 0;
    int treasureX, treasureY;
    int maxAttempts = 10;

    srand(time(NULL)); // Seed for random treasure location

    initializeGrid(grid);
    placeTreasure(&treasureX, &treasureY); // Randomly place treasure

    printf("Welcome to the Treasure Hunt game!\n");
    printf("You have %d attempts to find the treasure hidden on a 5x5 grid.\n", maxAttempts);

    for (int attempts = 0; attempts < maxAttempts; attempts++) {
        printGrid(grid, playerX, playerY);
        printf("Enter your next move (W/A/S/D for up/left/down/right): ");
        
        char move;
        scanf(" %c", &move);

        // Update player position according to move
        if (move == 'W' || move == 'w') {
            if (playerX > 0) playerX--;
        } else if (move == 'S' || move == 's') {
            if (playerX < GRID_SIZE - 1) playerX++;
        } else if (move == 'A' || move == 'a') {
            if (playerY > 0) playerY--;
        } else if (move == 'D' || move == 'd') {
            if (playerY < GRID_SIZE - 1) playerY++;
        } else {
            printf("Invalid move! Use W/A/S/D.\n");
            attempts--; // Don't count invalid attempts
            continue;
        }

        // Calculate distance from treasure
        int distance = calculateDistance(playerX, playerY, treasureX, treasureY);
        if (distance == 0) {
            printf("Congratulations! You found the treasure at (%d, %d)!\n", treasureX, treasureY);
            printGrid(grid, playerX, playerY);
            return 0; // Game ends
        } else {
            printf("You are %d step(s) away from the treasure.\n", distance);
        }
    }

    printf("Out of attempts! The treasure was at (%d, %d).\n", treasureX, treasureY);
    return 0;
}