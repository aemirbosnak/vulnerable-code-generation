//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define TRAPS 3
#define TREASURE 1

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void placeItems(char grid[GRID_SIZE][GRID_SIZE]);
void printGrid(char grid[GRID_SIZE][GRID_SIZE], int reveal);
int movePlayer(int *x, int *y, char direction);
void revealCell(char grid[GRID_SIZE][GRID_SIZE], int x, int y);

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    srand(time(NULL)); // Seed for random number generation

    initializeGrid(grid);
    placeItems(grid);

    int playerX = 0, playerY = 0;
    char move;

    printf("Welcome to Treasure Hunt!\n");
    printf("You are at (0, 0). Your goal is to find the treasure while avoiding traps.\n");

    while (1) {
        printGrid(grid, 0);
        printf("Move (w/a/s/d) or quit (q): ");
        scanf(" %c", &move);

        if (move == 'q') {
            printf("Thanks for playing!\n");
            break;
        }

        if (movePlayer(&playerX, &playerY, move)) {
            revealCell(grid, playerX, playerY);
            if (grid[playerX][playerY] == 'T') {
                printf("Congratulations! You found the treasure at (%d, %d)!\n", playerX, playerY);
                break;
            } else if (grid[playerX][playerY] == 'X') {
                printf("Oh no! You fell into a trap at (%d, %d). Game Over!\n", playerX, playerY);
                break;
            }
        } else {
            printf("Invalid move! Try again.\n");
        }
    }

    printGrid(grid, 1); // Reveal the entire grid before exiting
    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.'; // Use '.' to represent an empty cell
        }
    }
}

void placeItems(char grid[GRID_SIZE][GRID_SIZE]) {
    int count = 0;

    // Place traps
    while (count < TRAPS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '.') {
            grid[x][y] = 'X'; // 'X' represents a trap
            count++;
        }
    }

    // Place treasure
    count = 0;
    while (count < TREASURE) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == '.') {
            grid[x][y] = 'T'; // 'T' represents the treasure
            count++;
        }
    }
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE], int reveal) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (reveal || grid[i][j] == 'X' || grid[i][j] == 'T') {
                printf("%c ", grid[i][j]);
            } else {
                printf(". "); // Hide cells that are not revealed
            }
        }
        printf("\n");
    }
}

int movePlayer(int *x, int *y, char direction) {
    int newX = *x, newY = *y;

    switch (direction) {
        case 'w': newX--; break; // Move up
        case 's': newX++; break; // Move down
        case 'a': newY--; break; // Move left
        case 'd': newY++; break; // Move right
        default: return 0; // Invalid move
    }

    // Check for boundaries
    if (newX < 0 || newX >= GRID_SIZE || newY < 0 || newY >= GRID_SIZE) {
        return 0; // Invalid move
    }

    *x = newX; // Update player's position
    *y = newY;
    return 1; // Valid move
}

void revealCell(char grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    // This function can provide additional feedback about the cell if needed
    // For now, just demonstrate the feature by showing the coordinate
    printf("You moved to (%d, %d).\n", x, y);
}