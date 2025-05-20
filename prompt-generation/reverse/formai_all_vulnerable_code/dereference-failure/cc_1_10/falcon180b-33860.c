//Falcon-180B DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Character;

void print_character(Character *c) {
    printf("Name: %s\n", c->name);
    printf("Health: %d\n", c->health);
    printf("Attack: %d\n", c->attack);
    printf("Defense: %d\n", c->defense);
}

int main() {
    Character *player = malloc(sizeof(Character));
    strcpy(player->name, "Player");
    player->health = 100;
    player->attack = 10;
    player->defense = 5;

    Character *enemy = malloc(sizeof(Character));
    strcpy(enemy->name, "Enemy");
    enemy->health = 50;
    enemy->attack = 15;
    enemy->defense = 10;

    int player_attack_result = attack(player, enemy);
    int enemy_attack_result = attack(enemy, player);

    if (player_attack_result > enemy_attack_result) {
        printf("You have defeated the enemy!\n");
    } else if (enemy_attack_result > player_attack_result) {
        printf("You have been defeated by the enemy.\n");
    } else {
        printf("It's a tie!\n");
    }

    free(player);
    free(enemy);

    return 0;
}

int attack(Character *attacker, Character *defender) {
    int attack_power = attacker->attack - defender->defense;

    if (attack_power > 0) {
        defender->health -= attack_power;
        printf("%s attacks %s for %d damage!\n", attacker->name, defender->name, attack_power);
    } else {
        printf("%s's attack was blocked by %s's defense.\n", attacker->name, defender->name);
    }

    return attack_power;
}