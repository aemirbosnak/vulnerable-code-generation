//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE 'T'
#define TRAP 'X'
#define EMPTY ' '
#define START 'P'

void initializeGrid(char grid[SIZE][SIZE]);
void printGrid(char grid[SIZE][SIZE]);
void placeItems(char grid[SIZE][SIZE], int treasures, int traps);
void movePlayer(char grid[SIZE][SIZE], int *playerX, int *playerY);
int checkCell(char cell);
void gameLoop(char grid[SIZE][SIZE]);

int main() {
    char grid[SIZE][SIZE];
    int playerX = 0, playerY = 0;
    
    printf("Welcome to the Mystery Treasure Hunt!\n");
    
    initializeGrid(grid);
    placeItems(grid, 3, 2); // Place 3 treasures and 2 traps
    grid[playerX][playerY] = START;

    gameLoop(grid);
    
    return 0;
}

void initializeGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
}

void printGrid(char grid[SIZE][SIZE]) {
    printf("\nYour current position:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", grid[i][j]);
        }
        printf("\n");
    }
}

void placeItems(char grid[SIZE][SIZE], int treasures, int traps) {
    int placed = 0;
    srand(time(0));

    while (placed < treasures) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (grid[x][y] == EMPTY) {
            grid[x][y] = TREASURE;
            placed++;
        }
    }

    placed = 0;
    while (placed < traps) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (grid[x][y] == EMPTY) {
            grid[x][y] = TRAP;
            placed++;
        }
    }
}

void movePlayer(char grid[SIZE][SIZE], int *playerX, int *playerY) {
    char direction;
    printf("Move your Player (W/A/S/D): ");
    scanf(" %c", &direction);
    
    int newX = *playerX;
    int newY = *playerY;

    switch (direction) {
        case 'W': // Up
            newX--;
            break;
        case 'A': // Left
            newY--;
            break;
        case 'S': // Down
            newX++;
            break;
        case 'D': // Right
            newY++;
            break;
        default:
            printf("Invalid move! Try again.\n");
            return;
    }
    
    if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
        grid[*playerX][*playerY] = EMPTY; // Clear old position
        *playerX = newX;
        *playerY = newY;
        grid[newX][newY] = START; // Set new position
    } else {
        printf("Out of bounds! Stay inside the grid.\n");
    }
}

int checkCell(char cell) {
    switch (cell) {
        case TREASURE:
            printf("Surprise! You found a treasure!\n");
            return 1; // Return treasure found
        case TRAP:
            printf("Oh no! You fell into a trap!\n");
            return -1; // Return trap hit
        case EMPTY:
            printf("Nothing here, keep looking!\n");
            return 0; // Return nothing found
    }
    return 0;
}

void gameLoop(char grid[SIZE][SIZE]) {
    int playerX = 0, playerY = 0;
    int score = 0;

    while (1) {
        printGrid(grid);
        movePlayer(grid, &playerX, &playerY);
        int result = checkCell(grid[playerX][playerY]);

        if (result > 0) {
            score += 10; // Adding score for treasure
        } else if (result < 0) {
            printf("Game Over! Your final score was: %d\n", score);
            break; // End game on trap
        }
        printf("Current Score: %d\n", score);
    }
}