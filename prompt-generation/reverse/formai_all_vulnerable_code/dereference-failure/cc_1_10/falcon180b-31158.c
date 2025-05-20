//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10
#define MAX_PLAYERS 4
#define INITIAL_HEALTH 100
#define ATTACK_DAMAGE 10
#define DEFENSE_BONUS 5

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

void generate_player(Player* player) {
    strcpy(player->name, "Sir ");
    strcat(player->name, rand() % 1000 + 1);
    player->health = INITIAL_HEALTH;
    player->attack = rand() % 50 + 1;
    player->defense = rand() % 50 + 1;
}

void generate_enemy(Enemy* enemy, int difficulty) {
    strcpy(enemy->name, "Evil ");
    strcat(enemy->name, rand() % 1000 + 1);
    enemy->health = INITIAL_HEALTH + difficulty * 10;
    enemy->attack = rand() % 50 + 1 + difficulty * 5;
    enemy->defense = rand() % 50 + 1 + difficulty * 5;
}

void fight(Player* player, Enemy* enemy) {
    int player_damage = player->attack - enemy->defense;
    int enemy_damage = enemy->attack - player->defense;

    if (player_damage > 0) {
        enemy->health -= player_damage;
        printf("%s deals %d damage to %s.\n", player->name, player_damage, enemy->name);
    } else {
        printf("%s misses %s.\n", player->name, enemy->name);
    }

    if (enemy_damage > 0) {
        player->health -= enemy_damage;
        printf("%s deals %d damage to %s.\n", enemy->name, enemy_damage, player->name);
    } else {
        printf("%s misses %s.\n", enemy->name, player->name);
    }

    if (player->health <= 0) {
        printf("%s has been defeated by %s.\n", player->name, enemy->name);
        exit(0);
    } else if (enemy->health <= 0) {
        printf("%s has defeated %s.\n", player->name, enemy->name);
        return;
    }
}

int main() {
    srand(time(NULL));

    Player player;
    generate_player(&player);

    Enemy enemy;
    generate_enemy(&enemy, 1);

    fight(&player, &enemy);

    return 0;
}