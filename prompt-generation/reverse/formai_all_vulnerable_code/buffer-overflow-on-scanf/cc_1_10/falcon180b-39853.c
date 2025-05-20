//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_health = 100;
    int enemy_health = 50;
    int player_attack = 10;
    int enemy_attack = 5;
    int choice;
    int random_number;
    int damage;

    srand(time(NULL));

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space warrior with %d health points.\n", player_health);
    printf("You have encountered an enemy with %d health points.\n", enemy_health);

    while (player_health > 0 && enemy_health > 0) {
        printf("What would you like to do?\n");
        printf("1. Attack\n2. Defend\n");
        scanf("%d", &choice);

        random_number = rand() % 2;

        if (random_number == 0) {
            damage = player_attack - enemy_attack;
            if (damage > 0) {
                printf("You attacked the enemy and dealt %d damage!\n", damage);
                enemy_health -= damage;
            } else {
                printf("Your attack was not effective.\n");
            }
        } else {
            damage = enemy_attack - player_attack;
            if (damage > 0) {
                printf("The enemy attacked you and dealt %d damage!\n", damage);
                player_health -= damage;
            } else {
                printf("The enemy's attack was not effective.\n");
            }
        }

        if (player_health <= 0) {
            printf("You have been defeated by the enemy.\n");
            break;
        } else if (enemy_health <= 0) {
            printf("You have defeated the enemy!\n");
            break;
        }
    }

    return 0;
}