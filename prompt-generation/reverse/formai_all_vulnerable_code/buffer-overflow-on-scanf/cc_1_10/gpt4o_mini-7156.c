//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5 // Grid size
#define TREASURE 'T' // Treasure representation
#define TRAP 'X' // Trap representation
#define EMPTY '.' // Empty cell representation

void initializeGrid(char grid[SIZE][SIZE], int treasures, int traps) {
    // Fill the grid with empty cells
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = EMPTY;

    // Place treasures
    while (treasures > 0) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = TREASURE;
            treasures--;
        }
    }

    // Place traps
    while (traps > 0) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = TRAP;
            traps--;
        }
    }
}

void printGrid(char grid[SIZE][SIZE], int reveal) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == EMPTY || reveal)
                printf("%c ", grid[i][j]);
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char grid[SIZE][SIZE];
    int treasures = 3; // Total number of treasures
    int traps = 2;      // Total number of traps
    int score = 0, totalMoves = 0;
    int x, y;
    int gameOver = 0;

    initializeGrid(grid, treasures, traps);
    
    while (!gameOver) {
        printGrid(grid, 0);
        printf("Score: %d\n", score);
        printf("Enter your move (row and column): ");
        scanf("%d %d", &x, &y);

        // Validate input
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        totalMoves++;
        
        // Check the cell selected by the player
        if (grid[x][y] == TREASURE) {
            printf("You found a treasure!\n");
            score++;
            grid[x][y] = EMPTY; // Remove the treasure
        } else if (grid[x][y] == TRAP) {
            printf("Oh no! You hit a trap. Game Over!\n");
            gameOver = 1;
            printGrid(grid, 1); // Reveal the grid
        } else {
            printf("You found nothing. Try again!\n");
        }

        // Check for win condition
        if (score == treasures) {
            printf("Congratulations! You found all the treasures in %d moves!\n", totalMoves);
            gameOver = 1;
            printGrid(grid, 1); // Reveal the grid
        }
    }

    return 0;
}