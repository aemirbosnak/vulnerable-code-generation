//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 5
#define TREASURE_COUNT 3
#define TRAP_COUNT 2

typedef struct {
    int x;
    int y;
} Position;

char grid[SIZE][SIZE];
Position treasures[TREASURE_COUNT];
Position traps[TRAP_COUNT];

void initializeGrid();
void placeTreasures();
void placeTraps();
void displayGrid(Position playerPos);
bool isGameOver(Position playerPos);
void playerMove(Position *playerPos, char move);
bool isMoveValid(Position playerPos);
void playGame();

int main() {
    srand(time(NULL)); // Seed for randomness
    playGame();
    return 0;
}

void initializeGrid() {
    // Clear the grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    
    // Place treasures and traps
    placeTreasures();
    placeTraps();
}

void placeTreasures() {
    for (int i = 0; i < TREASURE_COUNT; i++) {
        while (true) {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            if (grid[x][y] == '.') {
                grid[x][y] = 'T'; // T for Treasure
                treasures[i].x = x;
                treasures[i].y = y;
                break;
            }
        }
    }
}

void placeTraps() {
    for (int i = 0; i < TRAP_COUNT; i++) {
        while (true) {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            if (grid[x][y] == '.') {
                grid[x][y] = 'X'; // X for Trap
                traps[i].x = x;
                traps[i].y = y;
                break;
            }
        }
    }
}

void displayGrid(Position playerPos) {
    printf("Current Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerPos.x && j == playerPos.y) {
                printf("P "); // P for Player
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

bool isGameOver(Position playerPos) {
    for (int i = 0; i < TRAP_COUNT; i++) {
        if (playerPos.x == traps[i].x && playerPos.y == traps[i].y) {
            printf("You stepped on a trap! Game Over.\n");
            return true;
        }
    }
    return false;
}

void playerMove(Position *playerPos, char move) {
    Position newPos = *playerPos;
    
    switch (move) {
        case 'w': newPos.x--; break; // Up
        case 's': newPos.x++; break; // Down
        case 'a': newPos.y--; break; // Left
        case 'd': newPos.y++; break; // Right
        default: printf("Invalid Move!\n"); return;
    }
    
    if (isMoveValid(newPos)) {
        *playerPos = newPos;
    } else {
        printf("Invalid Move! Out of bounds.\n");
    }
}

bool isMoveValid(Position playerPos) {
    return playerPos.x >= 0 && playerPos.x < SIZE &&
           playerPos.y >= 0 && playerPos.y < SIZE;
}

void playGame() {
    Position playerPos = {0, 0}; // Start position
    initializeGrid();
    int treasuresFound = 0;

    while (true) {
        displayGrid(playerPos);
        if (isGameOver(playerPos)) {
            break;
        }

        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);
        playerMove(&playerPos, move);

        // Check if player found treasure
        for (int i = 0; i < TREASURE_COUNT; i++) {
            if (playerPos.x == treasures[i].x && playerPos.y == treasures[i].y) {
                treasuresFound++;
                grid[treasures[i].x][treasures[i].y] = '.'; // Remove treasure from grid
                printf("You found a treasure! Total treasures found: %d\n", treasuresFound);
            }
        }

        if (treasuresFound == TREASURE_COUNT) {
            printf("Congratulations! You found all the treasures!\n");
            break;
        }
    }
}