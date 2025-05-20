//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURES 3

typedef struct {
    int x;
    int y;
} Position;

void initializeGrid(char grid[SIZE][SIZE], Position treasures[TREASURES]) {
    // Fill grid with empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Randomly place treasures on the grid
    for (int i = 0; i < TREASURES; i++) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (grid[x][y] == 'T'); // Check if there is already a treasure
        grid[x][y] = 'T'; // Place the treasure
        treasures[i].x = x;
        treasures[i].y = y;
    }
}

void printGrid(char grid[SIZE][SIZE], Position player) {
    // Print the grid with player position
    printf("Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf("P "); // Player's current position
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int checkTreasure(char grid[SIZE][SIZE], Position player) {
    return grid[player.x][player.y] == 'T';
}

void movePlayer(Position *player, char direction) {
    switch (direction) {
        case 'w': // Move up
            if (player->x > 0) player->x--;
            break;
        case 's': // Move down
            if (player->x < SIZE - 1) player->x++;
            break;
        case 'a': // Move left
            if (player->y > 0) player->y--;
            break;
        case 'd': // Move right
            if (player->y < SIZE - 1) player->y++;
            break;
        default:
            printf("Invalid move! Use 'w', 'a', 's', 'd' to move.\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random treasure placement

    char grid[SIZE][SIZE];
    Position treasures[TREASURES];
    Position player = {0, 0}; // Starting position of the player
    int foundTreasures = 0;
    char move;
    
    initializeGrid(grid, treasures);

    printf("Welcome to Treasure Hunt!\n");
    printf("You are Player 1. Find the hidden treasures marked 'T' on the grid.\n");
    
    while (foundTreasures < TREASURES) {
        printGrid(grid, player);
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        movePlayer(&player, move);

        if (checkTreasure(grid, player)) {
            printf("You found a treasure!\n");
            foundTreasures++;
            grid[player.x][player.y] = '.'; // Remove the treasure from the grid
        }
    }

    printf("Congratulations! You found all the treasures!\n");
    return 0;
}