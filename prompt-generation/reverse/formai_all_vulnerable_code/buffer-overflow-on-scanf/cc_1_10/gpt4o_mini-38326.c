//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE 'T'
#define TRAP 'X'
#define EMPTY ' '
#define PLAYER 'P'

char grid[SIZE][SIZE];
int playerX = 0, playerY = 0;

void initializeGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
    // Place Treasures and Traps randomly
    int treasures = 3, traps = 5;
    srand(time(NULL));

    while (treasures > 0) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = TREASURE;
            treasures--;
        }
    }
    
    while (traps > 0) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = TRAP;
            traps--;
        }
    }
    grid[playerX][playerY] = PLAYER;
}

void displayGrid() {
    printf("Current Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int movePlayer(int newX, int newY) {
    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
        printf("Move out of bounds!\n");
        return 0;
    }
    if (grid[newX][newY] == TRAP) {
        printf("Oh no! You hit a trap!\n");
        return -1;
    } else if (grid[newX][newY] == TREASURE) {
        printf("Congratulations! You found a treasure!\n");
        return 1;
    } else {
        // Move the player
        grid[playerX][playerY] = EMPTY; // Leaving the old spot
        playerX = newX;
        playerY = newY;
        grid[playerX][playerY] = PLAYER; // New spot
        return 0;
    }
}

int main() {
    initializeGrid();
    char command;
    int gameStatus = 0;
    printf("Welcome to the Treasure Hunt!\n");
    
    while (gameStatus >= 0) {
        displayGrid();
        printf("Enter your move (w/a/s/d for up/left/down/right): ");
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                gameStatus = movePlayer(playerX - 1, playerY);
                break;
            case 'a':
                gameStatus = movePlayer(playerX, playerY - 1);
                break;
            case 's':
                gameStatus = movePlayer(playerX + 1, playerY);
                break;
            case 'd':
                gameStatus = movePlayer(playerX, playerY + 1);
                break;
            default:
                printf("Invalid move! Use 'w', 'a', 's', or 'd'.\n");
        }

        if (gameStatus == 1) {
            // Check for more treasures
            int treasures = 0;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (grid[i][j] == TREASURE) {
                        treasures++;
                    }
                }
            }
            if (treasures == 0) {
                printf("You found all the treasures! You win!\n");
                break;
            }
        }
    }

    if (gameStatus == -1) {
        printf("Game Over! Better luck next time!\n");
    }

    return 0;
}