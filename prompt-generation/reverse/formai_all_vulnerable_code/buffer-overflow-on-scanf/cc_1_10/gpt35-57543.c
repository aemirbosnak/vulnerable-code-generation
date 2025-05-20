//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int hp = 100;
    int damage = 0;
    int escape_chance = 0;
    int alien_hp = 50;
    int alien_damage = 0;
    int choice = 0;
    srand(time(NULL));

    printf("Welcome to the intergalactic space adventure!\n\n");

    while(hp > 0 && alien_hp > 0) {
        printf("You have encountered an alien spacecraft, what would you like to do?\n");
        printf("1. Attack\n2. Try to escape\n");
        scanf("%d", &choice);

        if(choice == 1) {
            damage = rand() % 10 + 1;
            alien_hp -= damage;
            printf("You have dealt %d damage to the alien spacecraft!\n", damage);
        } else if(choice == 2) {
            escape_chance = rand() % 2;
            if(escape_chance == 0) {
                printf("You failed to escape and the alien spacecraft damaged you!\n");
                alien_damage = rand() % 10 + 1;
                hp -= alien_damage;
                printf("You have %d health points remaining!\n", hp);
            } else {
                printf("You have successfully escaped the alien spacecraft!\n");
                break;
            }
        }

        if(alien_hp > 0) {
            alien_damage = rand() % 10 + 1;
            hp -= alien_damage;
            printf("The alien spacecraft has dealt %d damage to you!\n", alien_damage);
            printf("You have %d health points remaining!\n", hp);
        }
    }

    if(hp > 0) {
        printf("Congratulations! You have successfully defeated the alien spacecraft and completed your mission!\n");
    } else {
        printf("Unfortunately, your spaceship has sustained too much damage and you have lost the space adventure!\n");
    }

    return 0;
}