//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define TREASURE 'T'
#define PLAYER 'P'
#define OBSTACLE 'X'
#define EMPTY ' '

char grid[GRID_SIZE][GRID_SIZE];
int playerX = 0, playerY = 0;
int treasureX, treasureY;

void initializeGrid() {
    // Fill grid with empty spaces
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // Place the treasure randomly
    treasureX = rand() % GRID_SIZE;
    treasureY = rand() % GRID_SIZE;
    grid[treasureX][treasureY] = TREASURE;

    // Place some obstacles randomly
    for (int i = 0; i < (GRID_SIZE * GRID_SIZE) / 5; i++) {
        int obsX = rand() % GRID_SIZE;
        int obsY = rand() % GRID_SIZE;
        if ((obsX != treasureX || obsY != treasureY) && (obsX != playerX || obsY != playerY)) {
            grid[obsX][obsY] = OBSTACLE;
        }
    }
}

void displayGrid() {
    system("clear"); // Use "cls" on Windows
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    int newX = playerX;
    int newY = playerY;

    switch(direction) {
        case 'w': newX--; break; // Move Up
        case 's': newX++; break; // Move Down
        case 'a': newY--; break; // Move Left
        case 'd': newY++; break; // Move Right
    }

    // Check boundaries
    if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE) {
        if (grid[newX][newY] != OBSTACLE) {
            playerX = newX;
            playerY = newY;
            // Check if treasure is found
            if (grid[playerX][playerY] == TREASURE) {
                printf("Congratulations! You've found the treasure!\n");
                exit(0); // Exit the game
            }
        } else {
            printf("Oops! There's an obstacle there!\n");
        }
    } else {
        printf("Can't move outside the grid!\n");
    }
}

int main() {
    char input;

    srand(time(NULL));
    initializeGrid();
    
    // Start the player at the top left corner
    printf("Welcome to Treasure Quest!\n");
    printf("Use 'w', 'a', 's', 'd' to move around and find the treasure!\n");
    
    while (1) {
        displayGrid();
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &input);
        movePlayer(input);
    }

    return 0;
}