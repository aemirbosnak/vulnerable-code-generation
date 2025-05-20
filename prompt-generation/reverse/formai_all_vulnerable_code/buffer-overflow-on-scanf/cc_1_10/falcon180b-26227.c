//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_health = 100;
    int enemy_health = 50;
    int choice = 0;
    int random_number = 0;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to defeat the evil aliens.\n");
    printf("You have %d health points.\n", player_health);
    printf("The aliens have %d health points.\n", enemy_health);

    while(player_health > 0 && enemy_health > 0) {
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Attack
                printf("You attack the aliens and deal %d damage!\n", random_number);
                enemy_health -= random_number;
                break;
            case 2: // Defend
                printf("You defend yourself and reduce the damage by %d!\n", random_number);
                player_health += random_number;
                break;
            case 3: // Heal
                printf("You use a healing potion and gain %d health points!\n", random_number);
                player_health += random_number;
                break;
            default:
                printf("Invalid choice.\n");
        }

        random_number = rand() % 10 + 1;
    }

    if(player_health <= 0) {
        printf("You have been defeated by the aliens.\n");
    } else {
        printf("You have defeated the aliens and completed your mission!\n");
    }

    return 0;
}