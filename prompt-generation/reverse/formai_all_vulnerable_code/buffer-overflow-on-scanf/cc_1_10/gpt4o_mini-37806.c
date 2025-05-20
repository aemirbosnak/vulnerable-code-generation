//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DUNGEON_SIZE 5
#define MAX_HEALTH 100
#define TREASURE_VALUE 20
#define TRAP_DAMAGE 30

typedef struct {
    int x;
    int y;
    int health;
    int treasures;
} Player;

void initializeDungeon(char dungeon[DUNGEON_SIZE][DUNGEON_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            int randNum = rand() % 10;
            if (randNum < 3) {
                dungeon[i][j] = 'T'; // Trap
            } else if (randNum < 6) {
                dungeon[i][j] = 'X'; // Treasure
            } else {
                dungeon[i][j] = '.'; // Empty space
            }
        }
    }
    dungeon[rand() % DUNGEON_SIZE][rand() % DUNGEON_SIZE] = 'S'; // Starting point
}

void printDungeon(char dungeon[DUNGEON_SIZE][DUNGEON_SIZE], Player player) {
    printf("Dungeon Map:\n");
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf("P "); // Player's position
            } else {
                printf("%c ", dungeon[i][j]);
            }
        }
        printf("\n");
    }
    printf("Health: %d | Treasures: %d\n", player.health, player.treasures);
}

void movePlayer(char dungeon[DUNGEON_SIZE][DUNGEON_SIZE], Player *player, char input) {
    int newX = player->x;
    int newY = player->y;

    switch (input) {
        case 'w': newX--; break; // Move up
        case 's': newX++; break; // Move down
        case 'a': newY--; break; // Move left
        case 'd': newY++; break; // Move right
        default: printf("Invalid move! Use 'w', 'a', 's', 'd' to move.\n"); return;
    }

    if (newX < 0 || newX >= DUNGEON_SIZE || newY < 0 || newY >= DUNGEON_SIZE) {
        printf("You can't move outside the dungeon!\n");
        return;
    }

    player->x = newX;
    player->y = newY;

    // Check the encountered cell
    char encountered = dungeon[newX][newY];
    if (encountered == 'T') {
        player->health -= TRAP_DAMAGE;
        printf("You stepped on a trap! You lost %d health!\n", TRAP_DAMAGE);
    } else if (encountered == 'X') {
        player->treasures++;
        printf("You found a treasure! Total treasures: %d\n", player->treasures);
        // Remove the treasure from the dungeon
        dungeon[newX][newY] = '.';
    }
}

int main() {
    char dungeon[DUNGEON_SIZE][DUNGEON_SIZE];
    Player player = {0, 0, MAX_HEALTH, 0};

    initializeDungeon(dungeon);
    // Find player's starting position
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            if (dungeon[i][j] == 'S') {
                player.x = i;
                player.y = j;
                break;
            }
        }
    }

    char input;
    while (player.health > 0) {
        printDungeon(dungeon, player);
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &input);
        movePlayer(dungeon, &player, input);
    }
    
    printf("Game Over! You collected %d treasures.\n", player.treasures);
    return 0;
}