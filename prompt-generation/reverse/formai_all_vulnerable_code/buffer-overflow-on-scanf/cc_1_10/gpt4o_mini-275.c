//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_ENEMIES 3
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int attack;
} Enemy;

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int attack;
    int gold;
    int treasures[MAX_ITEMS];
    int treasure_count;
} Player;

void initPlayer(Player *player) {
    player->health = 100;
    player->attack = 10;
    player->gold = 0;
    player->treasure_count = 0;
    printf("Enter your character name: ");
    scanf("%s", player->name);
}

void initEnemies(Enemy enemies[]) {
    strcpy(enemies[0].name, "Goblin");
    enemies[0].health = 30;
    enemies[0].attack = 5;

    strcpy(enemies[1].name, "Orc");
    enemies[1].health = 50;
    enemies[1].attack = 10;

    strcpy(enemies[2].name, "Dragon");
    enemies[2].health = 100;
    enemies[2].attack = 20;
}

void printStatus(Player player) {
    printf("\n--- Player Status ---\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Gold: %d\n", player.gold);
    printf("---------------------\n");
}

void printEnemyStatus(Enemy enemy) {
    printf("--- Enemy: %s ---\n", enemy.name);
    printf("Health: %d\n", enemy.health);
    printf("-------------------\n");
}

void attackEnemy(Player *player, Enemy *enemy) {
    printf("%s attacks %s for %d damage!\n", player->name, enemy->name, player->attack);
    enemy->health -= player->attack;
}

void attackPlayer(Player *player, Enemy *enemy) {
    printf("%s attacks %s for %d damage!\n", enemy->name, player->name, enemy->attack);
    player->health -= enemy->attack;
}

void collectTreasure(Player *player, int treasure) {
    if (player->treasure_count < MAX_ITEMS) {
        player->treasures[player->treasure_count++] = treasure;
        player->gold += treasure;
        printf("You collected a treasure worth %d gold!\n", treasure);
    } else {
        printf("Your treasure inventory is full!\n");
    }
}

void gameLoop(Player *player, Enemy enemies[]) {
    char command[10];
    int enemyIndex, treasure;

    while (player->health > 0) {
        printStatus(*player);
        printf("What would you like to do? [explore / quit]: ");
        scanf("%s", command);

        if (strcmp(command, "explore") == 0) {
            enemyIndex = rand() % MAX_ENEMIES;
            Enemy *currentEnemy = &enemies[enemyIndex];
            printf("\nYou encountered a %s!\n", currentEnemy->name);
            printEnemyStatus(*currentEnemy);

            while (currentEnemy->health > 0 && player->health > 0) {
                attackEnemy(player, currentEnemy);
                if (currentEnemy->health > 0) {
                    attackPlayer(player, currentEnemy);
                }
                if (player->health <= 0) {
                    printf("You have been defeated by %s!\n", currentEnemy->name);
                } else if (currentEnemy->health <= 0) {
                    printf("You defeated %s!\n", currentEnemy->name);
                    treasure = (rand() % 50) + 10; // Random treasure value between 10-60
                    collectTreasure(player, treasure);
                }
            }
        } else if (strcmp(command, "quit") == 0) {
            printf("Thank you for playing!\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }
}

int main() {
    srand(time(0));
    Player player;
    Enemy enemies[MAX_ENEMIES];

    initPlayer(&player);
    initEnemies(enemies);
    gameLoop(&player, enemies);
    
    return 0;
}