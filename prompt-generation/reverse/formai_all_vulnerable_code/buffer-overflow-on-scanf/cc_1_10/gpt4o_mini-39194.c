//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void printGrid(char grid[SIZE][SIZE], int playerX, int playerY) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("P "); // Player's position
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

void resetGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void placeTreasure(int *treasureX, int *treasureY) {
    *treasureX = rand() % SIZE; // Random position for treasure
    *treasureY = rand() % SIZE;
}

int calculateDistance(int playerX, int playerY, int treasureX, int treasureY) {
    return abs(playerX - treasureX) + abs(playerY - treasureY);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    char grid[SIZE][SIZE];
    int playerX = 0, playerY = 0;
    int treasureX, treasureY;
    
    resetGrid(grid);
    placeTreasure(&treasureX, &treasureY);

    printf("Welcome to the Treasure Hunt!\n"
           "Find the hidden treasure on the grid.\n"
           "You can move using the commands W (up), A (left), S (down), D (right).\n");

    while (1) {
        printGrid(grid, playerX, playerY);
        int distance = calculateDistance(playerX, playerY, treasureX, treasureY);
        
        if (distance == 0) {
            printf("Congratulations! You found the treasure at (%d, %d)!\n", treasureX, treasureY);
            break;
        }

        if (distance <= 2) {
            printf("You're getting hot! Distance to treasure: %d\n", distance);
        } else {
            printf("You're getting cold. Distance to treasure: %d\n", distance);
        }
        
        char move;
        printf("Enter your move (W/A/S/D): ");
        scanf(" %c", &move);

        switch (move) {
            case 'w':
            case 'W':
                if (playerX > 0) playerX--;
                break;
            case 'a':
            case 'A':
                if (playerY > 0) playerY--;
                break;
            case 's':
            case 'S':
                if (playerX < SIZE - 1) playerX++;
                break;
            case 'd':
            case 'D':
                if (playerY < SIZE - 1) playerY++;
                break;
            default:
                printf("Invalid move! Use W, A, S, or D.\n");
                break;
        }
    }

    return 0;
}