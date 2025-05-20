//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_SIZE 5
#define NUM_MONSTERS 3
#define TREASURE_VALUE 100
#define MAX_HEALTH 100

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int health;
    int gold;
} Player;

typedef struct {
    Position pos;
    int strength;
} Monster;

void initializeDungeon(Player *player, Monster monsters[], int *treasureX, int *treasureY) {
    player->pos.x = rand() % DUNGEON_SIZE;
    player->pos.y = rand() % DUNGEON_SIZE;
    player->health = MAX_HEALTH;
    player->gold = 0;

    for (int i = 0; i < NUM_MONSTERS; i++) {
        monsters[i].pos.x = rand() % DUNGEON_SIZE;
        monsters[i].pos.y = rand() % DUNGEON_SIZE;
        monsters[i].strength = (rand() % 20) + 1;
    }

    *treasureX = rand() % DUNGEON_SIZE;
    *treasureY = rand() % DUNGEON_SIZE;
}

void displayDungeon(Player player, Monster monsters[], int treasureX, int treasureY) {
    printf("Dungeon Layout:\n");
    for (int y = 0; y < DUNGEON_SIZE; y++) {
        for (int x = 0; x < DUNGEON_SIZE; x++) {
            if (player.pos.x == x && player.pos.y == y) {
                printf("P ");
            } else if (treasureX == x && treasureY == y) {
                printf("T ");
            } else {
                int monsterFound = 0;
                for (int i = 0; i < NUM_MONSTERS; i++) {
                    if (monsters[i].pos.x == x && monsters[i].pos.y == y) {
                        printf("M ");
                        monsterFound = 1;
                        break;
                    }
                }
                if (!monsterFound) {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}

void movePlayer(Player *player, char direction, Monster monsters[], int treasureX, int treasureY) {
    switch (direction) {
        case 'w': player->pos.y = (player->pos.y > 0) ? player->pos.y - 1 : 0; break;
        case 's': player->pos.y = (player->pos.y < DUNGEON_SIZE - 1) ? player->pos.y + 1 : DUNGEON_SIZE - 1; break;
        case 'a': player->pos.x = (player->pos.x > 0) ? player->pos.x - 1 : 0; break;
        case 'd': player->pos.x = (player->pos.x < DUNGEON_SIZE - 1) ? player->pos.x + 1 : DUNGEON_SIZE - 1; break;
        default: printf("Invalid direction! Use 'w', 'a', 's', or 'd'.\n"); return;
    }

    // Check for treasure
    if (player->pos.x == treasureX && player->pos.y == treasureY) {
        player->gold += TREASURE_VALUE;
        printf("You found treasure! Gold: %d\n", player->gold);
        // Move treasure to a new random location
        treasureX = rand() % DUNGEON_SIZE;
        treasureY = rand() % DUNGEON_SIZE;
    }

    // Check for monsters
    for (int i = 0; i < NUM_MONSTERS; i++) {
        if (player->pos.x == monsters[i].pos.x && player->pos.y == monsters[i].pos.y) {
            printf("You encountered a monster with strength %d!\n", monsters[i].strength);
            player->health -= monsters[i].strength;
            if (player->health <= 0) {
                printf("You have died! Game Over.\n");
                exit(0);
            } else {
                printf("You survived! Health: %d\n", player->health);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Player player;
    Monster monsters[NUM_MONSTERS];
    int treasureX, treasureY;

    initializeDungeon(&player, monsters, &treasureX, &treasureY);

    char move;
    while (1) {
        displayDungeon(player, monsters, treasureX, treasureY);
        printf("Move (w/a/s/d): ");
        scanf(" %c", &move);
        movePlayer(&player, move, monsters, treasureX, treasureY);
    }

    return 0;
}