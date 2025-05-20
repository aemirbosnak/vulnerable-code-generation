//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_SIZE 5
#define MAX_HEALTH 100
#define TREASURE_HEAL 20
#define MONSTER_DAMAGE 30

typedef struct {
    int x;
    int y;
} Player;

typedef struct {
    Player player;
    int health;
    int treasure;
    int monsters;
    char dungeon[DUNGEON_SIZE][DUNGEON_SIZE];
} GameState;

void initializeGame(GameState* game) {
    game->player.x = 0;
    game->player.y = 0;
    game->health = MAX_HEALTH;
    game->treasure = 0;
    game->monsters = 0;

    // Initialize the dungeon
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            if (rand() % 4 == 0) { // 25% chance to place a monster
                game->dungeon[i][j] = 'M';
                game->monsters++;
            } else if (rand() % 5 == 0) { // 20% chance to place treasure
                game->dungeon[i][j] = 'T';
            } else {
                game->dungeon[i][j] = '.';
            }
        }
    }
    game->dungeon[0][0] = 'P'; // Set player starting position
}

void printDungeon(const GameState* game) {
    system("clear");
    printf("Dungeon Escape!\n");
    printf("Health: %d | Treasure: %d\n", game->health, game->treasure);
    printf("You are at position (%d, %d)\n", game->player.x, game->player.y);
    printf("Dungeon Layout:\n");
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            if (i == game->player.x && j == game->player.y) {
                printf("P ");
            } else {
                printf("%c ", game->dungeon[i][j]);
            }
        }
        printf("\n");
    }
}

void movePlayer(GameState* game, int dx, int dy) {
    int newX = game->player.x + dx;
    int newY = game->player.y + dy;

    if (newX >= 0 && newX < DUNGEON_SIZE && newY >= 0 && newY < DUNGEON_SIZE) {
        game->player.x = newX;
        game->player.y = newY;

        // Check for treasures or monsters
        if (game->dungeon[newX][newY] == 'T') {
            game->treasure++;
            game->health += TREASURE_HEAL;
            printf("You found treasure! Restored health (+%d)\n", TREASURE_HEAL);
            game->dungeon[newX][newY] = '.'; // Remove treasure
        } else if (game->dungeon[newX][newY] == 'M') {
            game->health -= MONSTER_DAMAGE;
            printf("A monster attacked you! Lost health (-%d)\n", MONSTER_DAMAGE);
            game->dungeon[newX][newY] = '.'; // Remove monster
        }
    } else {
        printf("You can't move in that direction!\n");
    }
}

int checkGameOver(const GameState* game) {
    if (game->health <= 0) {
        printf("Game Over! You have lost all your health.\n");
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    GameState game;

    initializeGame(&game);

    while (1) {
        printDungeon(&game);
        char input;
        printf("Enter your move (W/A/S/D) or Q to quit: ");
        scanf(" %c", &input);

        switch (input) {
            case 'W': case 'w':
                movePlayer(&game, -1, 0);
                break;
            case 'S': case 's':
                movePlayer(&game, 1, 0);
                break;
            case 'A': case 'a':
                movePlayer(&game, 0, -1);
                break;
            case 'D': case 'd':
                movePlayer(&game, 0, 1);
                break;
            case 'Q': case 'q':
                printf("You decided to quit the game.\n");
                return 0;
            default:
                printf("Invalid input! Use W/A/S/D to move.\n");
        }

        if (checkGameOver(&game)) {
            break;
        }
    }

    return 0;
}