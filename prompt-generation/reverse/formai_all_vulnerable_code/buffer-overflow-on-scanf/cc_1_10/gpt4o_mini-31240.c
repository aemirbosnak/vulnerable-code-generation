//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE_COUNT 3
#define OBSTACLE_COUNT 5

enum tile {
    EMPTY,
    TREASURE,
    OBSTACLE
};

// Struct to define player position
typedef struct {
    int x;
    int y;
} Player;

// Function to initialize the game grid
void initializeGrid(enum tile grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
}

// Function to place treasures randomly on the grid
void placeTreasures(enum tile grid[SIZE][SIZE], int treasureCount) {
    int placed = 0;
    while (placed < treasureCount) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = TREASURE;
            placed++;
        }
    }
}

// Function to place obstacles randomly on the grid
void placeObstacles(enum tile grid[SIZE][SIZE], int obstacleCount) {
    int placed = 0;
    while (placed < obstacleCount) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = OBSTACLE;
            placed++;
        }
    }
}

// Function to display the grid
void displayGrid(enum tile grid[SIZE][SIZE], Player player) {
    printf("Current Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf("[P] ");
            } else if (grid[i][j] == TREASURE) {
                printf("[T] ");
            } else if (grid[i][j] == OBSTACLE) {
                printf("[O] ");
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

// Function to handle player movement
void movePlayer(Player *player, char direction) {
    switch (direction) {
        case 'w': if (player->x > 0) player->x--; break;  // Up
        case 's': if (player->x < SIZE - 1) player->x++; break;  // Down
        case 'a': if (player->y > 0) player->y--; break;  // Left
        case 'd': if (player->y < SIZE - 1) player->y++; break;  // Right
        default: printf("Invalid movement! Use w/a/s/d to move.\n");
    }
}

// Function to check the game state
int checkGameState(enum tile grid[SIZE][SIZE], Player player) {
    if (grid[player.x][player.y] == TREASURE) {
        printf("Congratulations! You've found a treasure!\n");
        return 1; // Found a treasure
    } else if (grid[player.x][player.y] == OBSTACLE) {
        printf("Oops! You hit an obstacle! Game over!\n");
        return -1; // Hit an obstacle
    }
    return 0; // Continue playing
}

// Function to start the game
void startGame() {
    srand(time(NULL));
    enum tile grid[SIZE][SIZE];
    initializeGrid(grid);
    placeTreasures(grid, TREASURE_COUNT);
    placeObstacles(grid, OBSTACLE_COUNT);

    Player player = {0, 0}; // Player starts at top-left corner
    int gameResult = 0;

    while (gameResult == 0) {
        displayGrid(grid, player);
        printf("Move (w/a/s/d): ");
        char move;
        scanf(" %c", &move);
        movePlayer(&player, move);
        gameResult = checkGameState(grid, player);
    }
}

int main() {
    printf("Welcome to the Mind-Bending Treasure Hunt!\n");
    startGame();
    return 0;
}