//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_health = 100;
    int enemy_health = 50;
    int attack_damage = 10;
    int defense_power = 5;
    int choice;
    int random_number;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space warrior with %d health points.\n", player_health);
    printf("Your enemy has %d health points.\n", enemy_health);
    printf("Choose your attack or defense:\n");
    printf("1. Attack with %d damage\n", attack_damage);
    printf("2. Defense with %d power\n", defense_power);
    scanf("%d", &choice);

    if (choice == 1) {
        random_number = rand() % 6 + 1;
        if (random_number <= 3) {
            printf("You missed your attack!\n");
        } else {
            printf("You hit your enemy with %d damage!\n", attack_damage);
            enemy_health -= attack_damage;
        }
    } else if (choice == 2) {
        random_number = rand() % 6 + 1;
        if (random_number <= 3) {
            printf("Your defense failed!\n");
        } else {
            printf("You successfully defended with %d power!\n", defense_power);
        }
    } else {
        printf("Invalid choice!\n");
    }

    if (player_health <= 0) {
        printf("Game over! You lose.\n");
        return 0;
    } else if (enemy_health <= 0) {
        printf("Congratulations! You win.\n");
        return 0;
    } else {
        printf("Continue fighting...\n");
        main();
    }

    return 0;
}