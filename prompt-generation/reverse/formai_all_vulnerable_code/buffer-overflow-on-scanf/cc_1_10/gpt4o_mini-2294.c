//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define NUM_TREASURES 3

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void placeTreasures(char grid[GRID_SIZE][GRID_SIZE]) {
    int treasuresPlaced = 0;
    while (treasuresPlaced < NUM_TREASURES) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '.') { // If the location is empty
            grid[x][y] = 'T';    // Place a treasure
            treasuresPlaced++;
        }
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE], int showTreasures) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (showTreasures || grid[i][j] == '.') {
                printf("%c ", grid[i][j]);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int playerX = 0, playerY = 0;
    int foundTreasures = 0;
    int maxTurns = 10;

    srand(time(NULL));
    initializeGrid(grid);
    placeTreasures(grid);

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("You have %d turns to find treasures.\n", maxTurns);
    printf("Find treasures (T) in a %dx%d grid!\n\n", GRID_SIZE, GRID_SIZE);

    while (maxTurns > 0 && foundTreasures < NUM_TREASURES) {
        printGrid(grid, 0); // Hide treasures
        printf("You are at (%d, %d). You have %d turns left.\n", playerX, playerY, maxTurns);
        printf("Move (WASD): ");
        
        char move;
        scanf(" %c", &move);

        switch (move) {
            case 'W':
            case 'w':
                if (playerX > 0) playerX--;
                break;
            case 'A':
            case 'a':
                if (playerY > 0) playerY--;
                break;
            case 'S':
            case 's':
                if (playerX < GRID_SIZE - 1) playerX++;
                break;
            case 'D':
            case 'd':
                if (playerY < GRID_SIZE - 1) playerY++;
                break;
            default:
                printf("Invalid move. Please use W, A, S, D.\n");
                continue;
        }

        maxTurns--;

        if (grid[playerX][playerY] == 'T') {
            foundTreasures++;
            printf("Congratulations! You found a treasure!\n");
            grid[playerX][playerY] = '.'; // Remove treasure from grid
        } else {
            printf("No treasure at this location.\n");
        }
    }

    printf("\nGame Over!\n");
    printf("You found %d treasures.\n", foundTreasures);
    printf("Here is the final grid:\n");
    printGrid(grid, 1); // Show treasures in final grid

    return 0;
}