//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define TREASURES 3
#define TRAPS 2

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '-';
        }
    }
}

void placeItems(char grid[GRID_SIZE][GRID_SIZE], char item, int count) {
    int placed = 0;
    while (placed < count) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '-') {
            grid[x][y] = item;
            placed++;
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("Current Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    int playerX = 0, playerY = 0;
    int treasuresFound = 0;

    srand(time(NULL)); // Seed random number generator
    initializeGrid(grid);
    placeItems(grid, 'T', TREASURES); // Place treasures
    placeItems(grid, 'X', TRAPS);      // Place traps

    while (1) {
        displayGrid(grid);
        printf("You are at (%d, %d). Treasures found: %d\n", playerX, playerY, treasuresFound);
        printf("Enter your move (W/A/S/D): ");
        
        char move;
        scanf(" %c", &move);

        // Update player position based on input
        int newX = playerX, newY = playerY;
        if (move == 'W' || move == 'w') newX--;
        else if (move == 'A' || move == 'a') newY--;
        else if (move == 'S' || move == 's') newX++;
        else if (move == 'D' || move == 'd') newY++;
        else {
            printf("Invalid move! Use W/A/S/D to move.\n");
            continue;
        }

        // Check boundaries
        if (newX < 0 || newX >= GRID_SIZE || newY < 0 || newY >= GRID_SIZE) {
            printf("Move out of bounds! Try again.\n");
            continue;
        }

        playerX = newX;
        playerY = newY;

        // Check the new grid position
        char currentCell = grid[playerX][playerY];
        if (currentCell == 'T') {
            printf("You found a treasure!\n");
            treasuresFound++;
            grid[playerX][playerY] = '-'; // Remove the treasure from grid
        } else if (currentCell == 'X') {
            printf("Oops! You hit a trap! Game Over.\n");
            break;
        } else {
            printf("Nothing interesting here...\n");
        }

        // Check for win condition
        if (treasuresFound == TREASURES) {
            printf("Congratulations! You found all the treasures!\n");
            break;
        }
    }

    printf("Game over! You found %d treasures.\n", treasuresFound);
    return 0;
}