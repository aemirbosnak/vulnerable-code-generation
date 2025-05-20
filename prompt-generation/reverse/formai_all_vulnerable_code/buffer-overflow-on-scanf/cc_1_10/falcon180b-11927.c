//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;
    int choice;
    int damage;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to defeat the enemy ship.\n");
    printf("Your health: %d\n", player_health);
    printf("Enemy health: %d\n", enemy_health);

    while (player_health > 0 && enemy_health > 0) {
        printf("What would you like to do?\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Heal\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                damage = rand() % 10 + 1;
                printf("You attacked the enemy and dealt %d damage!\n", damage);
                enemy_health -= damage;
                break;
            case 2:
                damage = rand() % 10 + 1;
                printf("You defended against the enemy and took %d damage!\n", damage);
                player_health -= damage;
                break;
            case 3:
                printf("You healed yourself and gained 10 health!\n");
                player_health += 10;
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Your health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);
    }

    if (player_health <= 0) {
        printf("You have been defeated by the enemy ship.\n");
    } else {
        printf("Congratulations! You have defeated the enemy ship.\n");
    }

    return 0;
}