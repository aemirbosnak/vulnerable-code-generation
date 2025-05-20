//GPT-4o-mini DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 5  // Size of the grid
#define TREASURE 'T'  // Treasure marker
#define PLAYER 'P'    // Player marker
#define EMPTY '.'     // Empty space
#define OBSTACLE '#'  // Obstacle marker

void initializeGrid(char grid[SIZE][SIZE]);
void displayGrid(char grid[SIZE][SIZE]);
bool movePlayer(char grid[SIZE][SIZE], int *playerX, int *playerY, char direction);
bool isGameOver(char grid[SIZE][SIZE]);

int main() {
    char grid[SIZE][SIZE];
    int playerX = 0, playerY = 0;  // Starting position of the player
    initializeGrid(grid);
    grid[playerX][playerY] = PLAYER;

    printf("Welcome to Treasure Hunt Adventure!\n");
    printf("You are represented as 'P'. Find the treasure 'T' and avoid obstacles '#'.\n");
    printf("Controls: 'w' (up), 'a' (left), 's' (down), 'd' (right), 'q' (quit)\n\n");

    while (!isGameOver(grid)) {
        displayGrid(grid);
        char move;
        printf("Enter your move: ");
        scanf(" %c", &move);  // Read user input

        if (move == 'q') {
            printf("Thanks for playing!\n");
            break;
        }

        // Move player if the move is valid
        if (!movePlayer(grid, &playerX, &playerY, move)) {
            printf("Invalid move! Try again.\n");
        }

        // Check if player found the treasure
        if (grid[playerX][playerY] == TREASURE) {
            displayGrid(grid);
            printf("Congratulations! You found the treasure!\n");
            break;
        }
    }

    return 0;
}

void initializeGrid(char grid[SIZE][SIZE]) {
    srand(time(0));  // Seed for random number generation

    // Fill the grid with empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // Place the treasure on the grid randomly
    int treasureX = rand() % SIZE;
    int treasureY = rand() % SIZE;
    grid[treasureX][treasureY] = TREASURE;

    // Place obstacles on the grid
    for (int i = 0; i < SIZE * SIZE / 4; i++) {  // Approximately 25% obstacles
        int obstacleX = rand() % SIZE;
        int obstacleY = rand() % SIZE;
        if (grid[obstacleX][obstacleY] == EMPTY) {
            grid[obstacleX][obstacleY] = OBSTACLE;
        }
    }
}

void displayGrid(char grid[SIZE][SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

bool movePlayer(char grid[SIZE][SIZE], int *playerX, int *playerY, char direction) {
    int newX = *playerX, newY = *playerY;

    // Determine new position based on input
    switch (direction) {
        case 'w': newX--; break;  // Up
        case 's': newX++; break;  // Down
        case 'a': newY--; break;  // Left
        case 'd': newY++; break;  // Right
        default: return false;     // Invalid move
    }

    // Check bounds and obstacles
    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE || grid[newX][newY] == OBSTACLE) {
        return false;  // Invalid move
    }

    // Move player to new position
    grid[*playerX][*playerY] = EMPTY;  // Clear previous position
    *playerX = newX;
    *playerY = newY;
    grid[*playerX][*playerY] = PLAYER;  // Set new position

    return true;  // Successful move
}

bool isGameOver(char grid[SIZE][SIZE]) {
    // Game over condition can be expanded to add more features
    // For now, just check if the treasure is reached
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == TREASURE) {
                return false;  // Game continues
            }
        }
    }
    return true;  // Game over
}