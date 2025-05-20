//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE 'T'
#define TRAP 'X'
#define PLAYER 'P'
#define EMPTY '.'

void initializeGrid(char grid[SIZE][SIZE], int *treasureX, int *treasureY, int *trapX, int *trapY) {
    // Fill the grid with empty spaces
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = EMPTY;

    // Place treasure
    *treasureX = rand() % SIZE;
    *treasureY = rand() % SIZE;
    grid[*treasureX][*treasureY] = TREASURE;

    // Place trap
    do {
        *trapX = rand() % SIZE;
        *trapY = rand() % SIZE;
    } while (*trapX == *treasureX && *trapY == *treasureY);
    grid[*trapX][*trapY] = TRAP;

    // Place player
    grid[0][0] = PLAYER;
}

void displayGrid(char grid[SIZE][SIZE]) {
    printf("\nGrid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char grid[SIZE][SIZE], int *playerX, int *playerY, char direction) {
    // Calculate new player position based on direction
    int newX = *playerX;
    int newY = *playerY;

    if (direction == 'w') newX--; // Move up
    else if (direction == 's') newX++; // Move down
    else if (direction == 'a') newY--; // Move left
    else if (direction == 'd') newY++; // Move right

    // Check boundaries
    if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
        // Move player
        grid[*playerX][*playerY] = EMPTY; // Clear old position
        *playerX = newX;
        *playerY = newY;
        
        if (grid[newX][newY] == TREASURE) {
            printf("Congratulations! You found the treasure!\n");
        } else if (grid[newX][newY] == TRAP) {
            printf("Oh no! You fell into a trap!\n");
        }
        
        grid[newX][newY] = PLAYER; // Update new position
    } else {
        printf("You can't move that way!\n");
    }
}

int main() {
    char grid[SIZE][SIZE];
    int playerX = 0, playerY = 0;
    int treasureX, treasureY, trapX, trapY;
    char command;

    srand(time(0)); // Seed for random number generation
    initializeGrid(grid, &treasureX, &treasureY, &trapX, &trapY);

    while (1) {
        displayGrid(grid);
        printf("Enter a command (w/a/s/d to move, q to quit): ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Thanks for playing!\n");
            break;
        }

        movePlayer(grid, &playerX, &playerY, command);

        if (grid[playerX][playerY] == TREASURE || grid[playerX][playerY] == TRAP) {
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}