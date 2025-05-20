//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define TREASURE_COUNT 3
#define MONSTER_COUNT 1

typedef struct {
    int x, y;
} Position;

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE], Position treasure[], Position monster, Position *player) {
    // Fill grid with empty spaces
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    
    // Place treasures
    for (int i = 0; i < TREASURE_COUNT; i++) {
        treasure[i].x = rand() % GRID_SIZE;
        treasure[i].y = rand() % GRID_SIZE;
        grid[treasure[i].x][treasure[i].y] = 'T';
    }
    
    // Place monster
    monster.x = rand() % GRID_SIZE;
    monster.y = rand() % GRID_SIZE;
    while (grid[monster.x][monster.y] != '.') {
        monster.x = rand() % GRID_SIZE;
        monster.y = rand() % GRID_SIZE;
    }
    grid[monster.x][monster.y] = 'M';

    // Set player starting position
    player->x = 0;
    player->y = 0;
    grid[player->x][player->y] = 'P'; // P represents Player
}

void printGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int movePlayer(char grid[GRID_SIZE][GRID_SIZE], Position *player, char direction) {
    int newX = player->x;
    int newY = player->y;
    
    switch (direction) {
        case 'w': newX--; break; // Up
        case 's': newX++; break; // Down
        case 'a': newY--; break; // Left
        case 'd': newY++; break; // Right
        default: return 0; // Invalid move
    }
    
    // Check boundaries
    if (newX < 0 || newX >= GRID_SIZE || newY < 0 || newY >= GRID_SIZE) {
        return 0; // Move out of bounds
    }
    
    // Move player
    grid[player->x][player->y] = '.'; // Clear old position
    player->x = newX;
    player->y = newY;

    // Check if landing on treasure or monster
    if (grid[player->x][player->y] == 'T') {
        grid[player->x][player->y] = 'P'; // Player moves to treasure
        return 1; // Found treasure
    } else if (grid[player->x][player->y] == 'M') {
        return -1; // Caught by monster
    }
    
    grid[player->x][player->y] = 'P'; // Update player position
    return 0; // Normal move
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    Position treasure[TREASURE_COUNT];
    Position monster;
    Position player;
    int collectedTreasures = 0;

    srand(time(NULL)); // Seed random number generator
    initializeGrid(grid, treasure, monster, &player);

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Find all the treasures and avoid the monster!\n");

    while (1) {
        printGrid(grid);
        printf("Collected Treasures: %d\n", collectedTreasures);
        printf("Move (w/a/s/d): ");
        
        char move;
        scanf(" %c", &move);
        int result = movePlayer(grid, &player, move);
        
        if (result == 1) {
            collectedTreasures++;
            if (collectedTreasures == TREASURE_COUNT) {
                printf("Congratulations! You've found all the treasures!\n");
                break;
            }
        } else if (result == -1) {
            printf("Oh no! You've been caught by the monster! Game Over!\n");
            break;
        } else {
            printf("Invalid Move! Try again.\n");
        }
    }

    return 0;
}