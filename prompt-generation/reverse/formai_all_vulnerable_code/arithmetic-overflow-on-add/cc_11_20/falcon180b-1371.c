//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int player_health = 100;
    int enemy_health = 100;
    int attack_power = 10;
    int defense_power = 10;
    int player_attack;
    int enemy_attack;
    int player_defense;
    int enemy_defense;
    int damage;
    int dodge;
    int hit;
    int miss;
    int critical_hit;
    int critical_miss;
    int status;

    srand(time(0));

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space warrior fighting against the evil alien!\n");
    printf("Let's begin the battle!\n");

    while (player_health > 0 && enemy_health > 0) {
        printf("Round %d\n", status+1);
        printf("Your health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);

        player_attack = rand() % 21 + 1;
        enemy_attack = rand() % 21 + 1;

        player_defense = rand() % 21 + 1;
        enemy_defense = rand() % 21 + 1;

        damage = (player_attack - enemy_defense) > 0? (player_attack - enemy_defense) : 0;
        dodge = (enemy_attack - player_defense) > 0? (enemy_attack - player_defense) : 0;
        hit = damage > dodge? 1 : 0;
        miss = hit == 0? 1 : 0;
        critical_hit = hit == 1 && rand() % 2 == 0? 1 : 0;
        critical_miss = miss == 1 && rand() % 2 == 0? 1 : 0;

        if (hit == 1 || critical_hit == 1) {
            enemy_health -= damage;
            printf("You hit the enemy and dealt %d damage!\n", damage);
        } else if (miss == 1 || critical_miss == 1) {
            printf("You missed the enemy!\n");
        }

        if (enemy_attack - player_defense > 0) {
            player_health -= (enemy_attack - player_defense);
            printf("The enemy hit you and dealt %d damage!\n", enemy_attack - player_defense);
        } else {
            printf("The enemy missed you!\n");
        }

        status++;
    }

    if (player_health <= 0) {
        printf("You have been defeated by the evil alien!\n");
    } else {
        printf("You have defeated the evil alien and saved the universe!\n");
    }

    return 0;
}