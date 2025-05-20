//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void initializeGrid(char grid[SIZE][SIZE], int* treasureX, int* treasureY) {
    // Fill grid with empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Randomly place the treasure
    *treasureX = rand() % SIZE;
    *treasureY = rand() % SIZE;
    grid[*treasureX][*treasureY] = 'T'; // 'T' for Treasure
}

void printGrid(char grid[SIZE][SIZE], int playerX, int playerY) {
    // Print the grid with player position represented as 'P'
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("P "); // P represents the Player
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    char grid[SIZE][SIZE];
    int treasureX, treasureY;
    int playerX = 0, playerY = 0; // Player starts at the top-left corner
    char move;

    initializeGrid(grid, &treasureX, &treasureY);
    
    printf("Welcome to the Treasure Hunt Game!\n");
    printf("You need to find the treasure (T) hidden in the grid.\n");
    printf("You can move using WASD keys (W=up, A=left, S=down, D=right).\n");

    while (1) {
        printGrid(grid, playerX, playerY);

        // Check if player has found the treasure
        if (playerX == treasureX && playerY == treasureY) {
            printf("Congratulations! You've found the treasure!\n");
            break;
        }

        // Get user input
        printf("Your move (WASD): ");
        scanf(" %c", &move);
        
        // Process the movement
        switch (move) {
            case 'w': 
                if (playerX > 0) playerX--; // Move up
                break;
            case 's': 
                if (playerX < SIZE - 1) playerX++; // Move down
                break;
            case 'a': 
                if (playerY > 0) playerY--; // Move left
                break;
            case 'd': 
                if (playerY < SIZE - 1) playerY++; // Move right
                break;
            default:
                printf("Invalid move! Use W (up), A (left), S (down), D (right).\n");
                break;
        }
    }

    printf("Thank you for playing!\n");
    return 0;
}