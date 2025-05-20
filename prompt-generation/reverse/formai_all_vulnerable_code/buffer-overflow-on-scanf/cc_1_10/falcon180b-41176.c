//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;
    int choice;
    int attack_roll;
    int defense_roll;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to defeat the evil alien.\n");
    printf("You have %d health points.\n", player_health);
    printf("The alien has %d health points.\n", enemy_health);

    while (player_health > 0 && enemy_health > 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Attack\n2. Defend\n");
        scanf("%d", &choice);

        if (choice == 1) {
            attack_roll = rand() % 6 + 1;
            defense_roll = rand() % 6 + 1;

            if (attack_roll > defense_roll) {
                enemy_health -= 10;
                printf("You attacked the alien and dealt 10 damage!\n");
            } else {
                printf("Your attack missed.\n");
            }
        } else if (choice == 2) {
            attack_roll = rand() % 6 + 1;
            defense_roll = rand() % 6 + 1;

            if (defense_roll > attack_roll) {
                printf("You successfully defended against the alien's attack!\n");
            } else {
                player_health -= 10;
                printf("The alien attacked you and dealt 10 damage!\n");
            }
        } else {
            printf("Invalid choice.\n");
        }
    }

    if (player_health <= 0) {
        printf("\nYou have been defeated by the alien.\n");
    } else {
        printf("\nYou have defeated the alien!\n");
    }

    return 0;
}