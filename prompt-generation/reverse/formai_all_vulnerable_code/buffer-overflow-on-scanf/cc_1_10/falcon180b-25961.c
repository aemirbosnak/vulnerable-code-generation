//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int ship_health = 100;
    int alien_health = 100;
    int turn = 0;

    srand(time(NULL));

    printf("Welcome to Space Adventure!\n");
    printf("You are a space pilot on a mission to defeat the alien invasion.\n");
    printf("Your spaceship has %d health points.\n", ship_health);
    printf("The alien has %d health points.\n", alien_health);

    while (ship_health > 0 && alien_health > 0) {
        printf("\nTurn %d\n", ++turn);
        printf("Your spaceship has %d health points left.\n", ship_health);
        printf("The alien has %d health points left.\n", alien_health);

        printf("\nWhat do you want to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Repair\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int attack_damage = rand() % 10 + 1;
            printf("You attack the alien and deal %d damage!\n", attack_damage);
            alien_health -= attack_damage;
        } else if (choice == 2) {
            int defend_effect = rand() % 3;
            if (defend_effect == 0) {
                printf("You defend yourself and reduce the incoming damage by half!\n");
                alien_health -= ship_health / 2;
            } else if (defend_effect == 1) {
                printf("You defend yourself and negate the incoming damage!\n");
            } else {
                printf("You defend yourself but it has no effect.\n");
            }
        } else if (choice == 3) {
            int repair_amount = rand() % 10 + 1;
            printf("You repair your spaceship and regain %d health points!\n", repair_amount);
            ship_health += repair_amount;
        } else {
            printf("Invalid choice. Skipping turn.\n");
        }

        if (ship_health <= 0) {
            printf("\nGame over! You have been defeated by the alien.\n");
            break;
        } else if (alien_health <= 0) {
            printf("\nCongratulations! You have defeated the alien.\n");
            break;
        }
    }

    return 0;
}