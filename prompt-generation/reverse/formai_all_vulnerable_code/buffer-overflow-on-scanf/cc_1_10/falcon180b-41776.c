//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ENEMIES 20

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Player;

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
} Enemy;

void generatePlayer(Player* player) {
    srand(time(NULL));
    player->health = rand() % 100 + 1;
    player->attack = rand() % 50 + 1;
    player->defense = rand() % 50 + 1;
    strcpy(player->name, "Player");
}

void generateEnemy(Enemy* enemy) {
    srand(time(NULL));
    enemy->health = rand() % 100 + 1;
    enemy->attack = rand() % 50 + 1;
    enemy->defense = rand() % 50 + 1;
    strcpy(enemy->name, "Enemy");
}

void battle(Player* player, Enemy* enemy) {
    int attackResult = rand() % 100 + 1;
    int defenseResult = rand() % 100 + 1;

    if (attackResult > defenseResult) {
        printf("%s attacks %s for %d damage!\n", player->name, enemy->name, player->attack);
        enemy->health -= player->attack;
    } else {
        printf("%s defends against %s's attack.\n", enemy->name, player->name);
    }

    if (enemy->health <= 0) {
        printf("%s has defeated %s!\n", player->name, enemy->name);
    } else if (player->health <= 0) {
        printf("%s has been defeated by %s.\n", player->name, enemy->name);
    }
}

int main() {
    Player player;
    Enemy enemy;

    generatePlayer(&player);
    generateEnemy(&enemy);

    int choice;
    while (1) {
        printf("1. Attack\n2. Defend\n");
        scanf("%d", &choice);

        if (choice == 1) {
            battle(&player, &enemy);
        } else if (choice == 2) {
            battle(&enemy, &player);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}