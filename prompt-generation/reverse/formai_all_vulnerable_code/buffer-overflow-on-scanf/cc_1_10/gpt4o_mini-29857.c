//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 5
#define TREASURE 'T'
#define MONSTER 'M'
#define EMPTY '.'

// Structure for the game map
typedef struct {
    char grid[SIZE][SIZE];
    int playerX;
    int playerY;
} GameMap;

// Function to initialize the game map
void initializeMap(GameMap *map) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            map->grid[i][j] = EMPTY;
        }
    }
    map->playerX = SIZE / 2;
    map->playerY = SIZE / 2;

    // Place the treasure
    srand(time(NULL));
    int treasureX = rand() % SIZE;
    int treasureY = rand() % SIZE;
    while ((treasureX == map->playerX && treasureY == map->playerY)) {
        treasureX = rand() % SIZE;
        treasureY = rand() % SIZE;
    }
    map->grid[treasureX][treasureY] = TREASURE;

    // Place a monster
    int monsterX = rand() % SIZE;
    int monsterY = rand() % SIZE;
    while ((monsterX == map->playerX && monsterY == map->playerY) || 
           (monsterX == treasureX && monsterY == treasureY)) {
        monsterX = rand() % SIZE;
        monsterY = rand() % SIZE;
    }
    map->grid[monsterX][monsterY] = MONSTER;
}

// Function to print the game map
void printMap(GameMap *map) {
    system("clear"); // Clear the screen
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == map->playerX && j == map->playerY) {
                printf("P ");
            } else {
                printf("%c ", map->grid[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to move the player
void movePlayer(GameMap *map, char direction) {
    int newX = map->playerX;
    int newY = map->playerY;

    switch (direction) {
        case 'w': // Move up
            newX--;
            break;
        case 's': // Move down
            newX++;
            break;
        case 'a': // Move left
            newY--;
            break;
        case 'd': // Move right
            newY++;
            break;
        default:
            printf("Invalid move! Use 'w', 'a', 's', 'd' to move.\n");
            return;
    }

    // Check for boundaries
    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
        printf("You cannot move outside the dungeon!\n");
        return;
    }

    // Update player position
    map->playerX = newX;
    map->playerY = newY;

    // Check for treasure or monster
    if (map->grid[newX][newY] == TREASURE) {
        printf("Congratulations! You've found the treasure!\n");
        exit(0);
    } else if (map->grid[newX][newY] == MONSTER) {
        printf("Oh no! You've encountered a monster! Game Over.\n");
        exit(0);
    }
}

// Main game loop
int main() {
    GameMap gameMap;
    initializeMap(&gameMap);
    char move;

    printf("Welcome to Dungeon Escape!\n");
    printf("Your goal is to find the treasure (T) while avoiding monsters (M).\n");
    printf("You are represented by 'P'. Use 'w' to move up, 's' to move down,\n");
    printf("'a' to move left, and 'd' to move right.\n");
    printf("Good luck!\n");

    while (1) {
        printMap(&gameMap);
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);
        movePlayer(&gameMap, move);
    }

    return 0;
}