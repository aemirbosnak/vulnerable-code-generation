//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_WIDTH 10
#define DUNGEON_HEIGHT 10
#define NUM_TREASURES 3
#define NUM_ENEMIES 5

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int health;
} Creature;

typedef struct {
    char grid[DUNGEON_HEIGHT][DUNGEON_WIDTH];
    Creature enemies[NUM_ENEMIES];
    Creature treasures[NUM_TREASURES];
} Dungeon;

void initializeDungeon(Dungeon *dungeon) {
    for (int i = 0; i < DUNGEON_HEIGHT; i++) {
        for (int j = 0; j < DUNGEON_WIDTH; j++) {
            dungeon->grid[i][j] = '.';
        }
    }
}

void placeTreasures(Dungeon *dungeon) {
    for (int i = 0; i < NUM_TREASURES; i++) {
        int x = rand() % DUNGEON_WIDTH;
        int y = rand() % DUNGEON_HEIGHT;

        dungeon->treasures[i].pos.x = x;
        dungeon->treasures[i].pos.y = y;
        dungeon->grid[y][x] = 'T';
    }
}

void placeEnemies(Dungeon *dungeon) {
    for (int i = 0; i < NUM_ENEMIES; i++) {
        int x = rand() % DUNGEON_WIDTH;
        int y = rand() % DUNGEON_HEIGHT;

        dungeon->enemies[i].pos.x = x;
        dungeon->enemies[i].pos.y = y;
        dungeon->enemies[i].health = rand() % 10 + 1; // Health between 1 and 10
        dungeon->grid[y][x] = 'E';
    }
}

void printDungeon(Dungeon *dungeon) {
    for (int i = 0; i < DUNGEON_HEIGHT; i++) {
        for (int j = 0; j < DUNGEON_WIDTH; j++) {
            printf("%c ", dungeon->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    Dungeon dungeon;
    initializeDungeon(&dungeon);
    placeTreasures(&dungeon);
    placeEnemies(&dungeon);
    
    printf("Welcome to the Rogue-like Dungeon Adventure!\n");
    printDungeon(&dungeon);

    // Game loop placeholder
    char command;
    while (1) {
        printf("Enter a command (q to quit): ");
        scanf(" %c", &command);
        if (command == 'q') break;

        // Implement more game logic for moving and interacting here
    }

    printf("Exiting game. Farewell, adventurer!\n");
    return 0;
}