//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void fight(int att, int def) {
    int damage = att - def;
    if (damage > 0) {
        printf("You dealt %d damage!\n", damage);
    } else {
        printf("Your attack was blocked.\n");
    }
}

int main() {
    int health = 100;
    int armor = 20;
    int enemy_health = 200;
    int enemy_armor = 30;

    printf("Welcome to the Arena of Doom.\n");
    printf("Your health: %d, armor: %d.\n", health, armor);

    while (health > 0 && enemy_health > 0) {
        printf("What do you want to do? (attack, defend, flee): ");
        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                fight(15, enemy_armor);
                break;
            case 'd':
                printf("You blocked the enemy's attack.\n");
                break;
            case 'f':
                printf("You fled the arena.\n");
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }

        if (enemy_health < 0) {
            printf("You have won the battle!\n");
            return 0;
        }

        printf("Enemy's health: %d, armor: %d.\n", enemy_health, enemy_armor);
    }

    printf("You have been defeated.\n");
    return 0;
}