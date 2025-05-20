//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define DUNGEON_SIZE 5
#define MAX_TRAPS 3
#define MAX_KEYS 2

typedef enum { EMPTY, TRAP, KEY, EXIT } Cell;

typedef struct {
    int x;
    int y;
} Position;

Cell dungeon[DUNGEON_SIZE][DUNGEON_SIZE];
Position player;
int keysCollected = 0;

void initializeDungeon() {
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            dungeon[i][j] = EMPTY;
        }
    }
    
    // Set traps
    for (int i = 0; i < MAX_TRAPS; i++) {
        int x, y;
        do {
            x = rand() % DUNGEON_SIZE;
            y = rand() % DUNGEON_SIZE;
        } while (dungeon[x][y] != EMPTY);
        dungeon[x][y] = TRAP;
    }
    
    // Set keys
    for (int i = 0; i < MAX_KEYS; i++) {
        int x, y;
        do {
            x = rand() % DUNGEON_SIZE;
            y = rand() % DUNGEON_SIZE;
        } while (dungeon[x][y] != EMPTY);
        dungeon[x][y] = KEY;
    }
    
    // Set exit
    int exitX, exitY;
    do {
        exitX = rand() % DUNGEON_SIZE;
        exitY = rand() % DUNGEON_SIZE;
    } while (dungeon[exitX][exitY] != EMPTY);
    dungeon[exitX][exitY] = EXIT;

    // Set player starting position
    player.x = 0;
    player.y = 0;
}

void displayDungeon() {
    printf("Dungeon Layout:\n");
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf(" P ");
            } else if (dungeon[i][j] == TRAP) {
                printf(" T ");
            } else if (dungeon[i][j] == KEY) {
                printf(" K ");
            } else if (dungeon[i][j] == EXIT) {
                printf(" E ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("Keys collected: %d\n", keysCollected);
}

bool movePlayer(char direction) {
    int newX = player.x;
    int newY = player.y;

    switch (direction) {
        case 'w': newX--; break; // up
        case 's': newX++; break; // down
        case 'a': newY--; break; // left
        case 'd': newY++; break; // right
        default: return false; // invalid input
    }

    // Check boundaries
    if (newX < 0 || newX >= DUNGEON_SIZE || newY < 0 || newY >= DUNGEON_SIZE) {
        printf("Can't move in that direction!\n");
        return false;
    }

    // Check cell contents
    switch (dungeon[newX][newY]) {
        case TRAP:
            printf("You stepped on a trap! Game over.\n");
            return false;
        case KEY:
            printf("You found a key!\n");
            keysCollected++;
            break;
        case EXIT:
            if (keysCollected == MAX_KEYS) {
                printf("You've escaped the dungeon! You win!\n");
                return false;
            } else {
                printf("You need more keys to escape!\n");
                break;
            }
        default:
            break;
    }

    // Move player
    player.x = newX;
    player.y = newY;
    return true;
}

int main() {
    srand(time(NULL));
    initializeDungeon();
    
    char input;
    while (true) {
        displayDungeon();
        printf("Use w (up), s (down), a (left), d (right) to move: ");
        scanf(" %c", &input);
        if (!movePlayer(input)) {
            break;
        }
    }
    
    return 0;
}