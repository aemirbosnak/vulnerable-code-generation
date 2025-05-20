//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE 'T'
#define TRAP 'X'
#define EMPTY '.'
#define PLAYER 'P'

void initializeGrid(char grid[SIZE][SIZE]);
void printGrid(char grid[SIZE][SIZE], int playerX, int playerY);
void movePlayer(char grid[SIZE][SIZE], int* playerX, int* playerY, char direction);
int checkGameStatus(char grid[SIZE][SIZE]);

int main() {
    char grid[SIZE][SIZE];
    int playerX = 0, playerY = 0;
    char move;
    int gameOver = 0;

    srand(time(NULL));
    initializeGrid(grid);

    while (!gameOver) {
        printGrid(grid, playerX, playerY);
        printf("Enter your move (W/A/S/D): ");
        scanf(" %c", &move);
        
        move = toupper(move);
        
        movePlayer(grid, &playerX, &playerY, move);
        gameOver = checkGameStatus(grid);
    }

    printGrid(grid, playerX, playerY);
    printf("Game Over!\n");
    
    return 0;
}

void initializeGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // Place treasures and traps randomly
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int randNum = rand() % 100;
            if (randNum < 15) {
                grid[i][j] = TREASURE; // 15% chance of treasure
            } else if (randNum < 30) {
                grid[i][j] = TRAP; // 15% chance of trap
            }
        }
    }
    grid[0][0] = PLAYER; // Starting position of the player
}

void printGrid(char grid[SIZE][SIZE], int playerX, int playerY) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

void movePlayer(char grid[SIZE][SIZE], int* playerX, int* playerY, char direction) {
    int newX = *playerX;
    int newY = *playerY;

    switch (direction) {
        case 'W':
            newX--; // Move up
            break;
        case 'S':
            newX++; // Move down
            break;
        case 'A':
            newY--; // Move left
            break;
        case 'D':
            newY++; // Move right
            break;
        default:
            printf("Invalid move! Use W/A/S/D to move.\n");
            return;
    }

    // Check boundaries
    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
        printf("Can't move there! Out of bounds.\n");
        return;
    }

    // Move the player
    grid[*playerX][*playerY] = EMPTY;
    *playerX = newX;
    *playerY = newY;

    // Check what the player encountered
    if (grid[*playerX][*playerY] == TREASURE) {
        printf("You found a treasure!\n");
    } else if (grid[*playerX][*playerY] == TRAP) {
        printf("You fell into a trap!\n");
    }
    grid[*playerX][*playerY] = PLAYER; // Place player in the new location
}

int checkGameStatus(char grid[SIZE][SIZE]) {
    int treasureCount = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == TREASURE) {
                treasureCount++;
            }
            if (grid[i][j] == TRAP) {
                return 1; // Game Over if the player hits a trap
            }
        }
    }
    if (treasureCount == 0) {
        printf("You've collected all treasures! You win!\n");
        return 1; // Game Over if all treasures are found
    }
    return 0; // Game continues
}