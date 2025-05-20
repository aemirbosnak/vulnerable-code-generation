//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5  // Size of the board
#define TREASURE_COUNT 3

// Function to print the game board
void printBoard(char board[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Main game function
int main() {
    char board[SIZE][SIZE];
    int playerX = SIZE / 2;  // Initial player position (center of the board)
    int playerY = SIZE / 2;
    int treasures[TREASURE_COUNT][2];  // Array to hold treasure locations
    int foundTreasures = 0;  // Counter for found treasures
    char move;
    srand(time(NULL));  // Seed the random number generator

    // Initialize the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
    board[playerX][playerY] = 'P';  // Place the player on the board

    // Place treasures randomly on the board
    for (int i = 0; i < TREASURE_COUNT; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (board[x][y] != '.');  // Ensure treasure is not placed on top of another
        treasures[i][0] = x;  // Store the treasure's position
        treasures[i][1] = y;
        board[x][y] = 'T';  // Place treasure on board
    }
    
    // Game loop
    while (foundTreasures < TREASURE_COUNT) {
        printBoard(board);
        printf("Move (W/A/S/D): ");
        scanf(" %c", &move);
        
        int newX = playerX;
        int newY = playerY;

        // Determine new player position based on input
        if (move == 'w' || move == 'W') newX--; // Up
        else if (move == 's' || move == 'S') newX++; // Down
        else if (move == 'a' || move == 'A') newY--; // Left
        else if (move == 'd' || move == 'D') newY++; // Right
        
        // Check boundaries
        if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
            // Check for treasure
            if (board[newX][newY] == 'T') {
                foundTreasures++;
                printf("You found a treasure! Treasures found: %d/%d\n", foundTreasures, TREASURE_COUNT);
            }
            // Update board: move player
            board[playerX][playerY] = '.';  // Clear old position
            playerX = newX;
            playerY = newY;
            board[playerX][playerY] = 'P';  // Update new position
        } else {
            printf("Invalid move! You hit the boundary of the board.\n");
        }
    }

    printf("Congratulations! You've found all the treasures!\n");
    return 0;
}