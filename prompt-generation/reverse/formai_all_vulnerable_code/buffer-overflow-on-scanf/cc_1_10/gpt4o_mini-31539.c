//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 5
#define MAX_TRAPS 3

char grid[GRID_SIZE][GRID_SIZE];
int playerX, playerY, treasureX, treasureY;
int traps[MAX_TRAPS][2];

void initializeGrid() {
    // Initialize grid with empty spaces
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Place the player
    playerX = rand() % GRID_SIZE;
    playerY = rand() % GRID_SIZE;
    grid[playerX][playerY] = 'P';

    // Place the treasure
    treasureX = rand() % GRID_SIZE;
    treasureY = rand() % GRID_SIZE;

    // Ensure the treasure is not placed at the same position as the player
    while (treasureX == playerX && treasureY == playerY) {
        treasureX = rand() % GRID_SIZE;
        treasureY = rand() % GRID_SIZE;
    }

    grid[treasureX][treasureY] = 'T';

    // Place traps
    for (int i = 0; i < MAX_TRAPS; i++) {
        do {
            traps[i][0] = rand() % GRID_SIZE;
            traps[i][1] = rand() % GRID_SIZE;
        } while ((traps[i][0] == playerX && traps[i][1] == playerY) ||
                 (traps[i][0] == treasureX && traps[i][1] == treasureY));
        grid[traps[i][0]][traps[i][1]] = 'X';
    }
}

void printGrid() {
    printf("Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int movePlayer(char direction[]) {
    int newX = playerX;
    int newY = playerY;

    // Calculate new position based on direction
    if (strcmp(direction, "up") == 0) {
        newX--;
    } else if (strcmp(direction, "down") == 0) {
        newX++;
    } else if (strcmp(direction, "left") == 0) {
        newY--;
    } else if (strcmp(direction, "right") == 0) {
        newY++;
    }

    // Check for boundaries
    if (newX < 0 || newX >= GRID_SIZE || newY < 0 || newY >= GRID_SIZE) {
        printf("You hit the wall! Try another direction.\n");
        return 0;
    }

    // Check for traps
    for (int i = 0; i < MAX_TRAPS; i++) {
        if (newX == traps[i][0] && newY == traps[i][1]) {
            printf("You fell into a trap! Game over.\n");
            return -1;
        }
    }

    // Move player
    grid[playerX][playerY] = '.';
    playerX = newX;
    playerY = newY;
    grid[playerX][playerY] = 'P';

    // Check for treasure
    if (playerX == treasureX && playerY == treasureY) {
        printf("Congratulations! You found the treasure!\n");
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    
    initializeGrid();
    printf("Welcome to Treasure Hunt!\n");
    
    int result;
    char direction[10];
    
    while (1) {
        printGrid();
        printf("Enter your move (up, down, left, right): ");
        scanf("%s", direction);
        
        result = movePlayer(direction);
        
        if (result == 1) {
            break;  // Player found treasure
        } else if (result == -1) {
            break;  // Player fell into trap
        }
    }
    
    return 0;
}