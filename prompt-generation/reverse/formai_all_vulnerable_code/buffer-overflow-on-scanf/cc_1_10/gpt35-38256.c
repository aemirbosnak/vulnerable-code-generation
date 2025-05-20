//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[25], choice[10];
    int hp = 100, damage = 20, potion = 3, monster_hp = 80, monster_damage = 15, flee = 0;

    printf("Welcome to the Text-Based Adventure Game!\nWhat is your name?: ");
    scanf("%s", name);
    printf("Hello, %s! Are you ready to start your adventure?\n", name);

    while (1) {
        printf("\nWhat would you like to do next?: attack, potion, flee\n");
        scanf("%s", choice);

        if (strcmp(choice, "attack") == 0) {
            printf("The monster has taken %d points of damage!\n", damage);
            monster_hp -= damage;
            if (monster_hp <= 0) {
                printf("Congratulation! You defeated the monster!\n");
                break;
            }
            hp -= monster_damage;
            printf("The monster has counter-attacked and taken %d points of damage!\n", monster_damage);
            if (hp <= 0) {
                printf("You were defeated! Game over.\n");
                exit(0);
            }

        } else if (strcmp(choice, "potion") == 0) {
            if (potion > 0) {
                hp += 30;
                if (hp > 100) {
                    hp = 100;
                }
                printf("You have consumed a potion, and your health is now %d.\n", hp);
                potion--;
            } else {
                printf("You have no more potions. Choose another action.\n");
            }

        } else if (strcmp(choice, "flee") == 0) {
            printf("You fled from the monster!\n");
            flee = 1;
            break;

        } else {
            printf("Invalid input. Try again!\n");
        }
    }
    
    if (flee == 0) { // If the player didn't flee and defeated the monster
        printf("\nYou have reached the end of your adventure. Congratulations, %s!\n", name);
    } else { // If the player fled and didn't defeat the monster
        printf("\nYou were unable to defeat the monster. Game over.\n");
    }

    return 0;
}