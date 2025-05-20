//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int health = 100;

// Function to display current health status
void display_health() {
    printf("Current health: %d\n", health);
}

int main() {
    char name[20];

    // Introduction
    printf("Welcome to The Cave!\n");
    printf("In this game, you will navigate a dangerous cave to find a treasure\n\n");

    // Get user's name
    printf("What's your name?\n");
    scanf("%s", name);

    // Start of the game
    printf("\n%s, you start your journey into the cave\n", name);

    // First decision
    printf("You come across a fork in the path\n");
    printf("Do you go left or right?\n");

    char decision[10];
    scanf("%s", decision);

    if(strcmp(decision, "left")==0) {
        // Left path
        printf("\nYou go left and find a sword\n");
        printf("Do you take the sword?\n");

        char take_sword[10];
        scanf("%s", take_sword);

        if(strcmp(take_sword, "yes")==0) {
            printf("You take the sword and your attack power has increased by 10\n");
        } else {
            printf("You don't take the sword\n");
        }

        // Encounter with monster
        printf("As you go further, you encounter a monster\n");
        printf("Do you fight or run?\n");

        char fight_or_run[10];
        scanf("%s", fight_or_run);

        if(strcmp(fight_or_run, "fight")==0) {
            printf("You engage in battle with the monster!\n");

            int monster_health = 50;
            int attack_power = 10;

            while(health>0 && monster_health>0) {
                // Your attack
                int your_hit = rand() % attack_power + 5;
                monster_health -= your_hit;
                printf("You hit the monster for %d damage\n", your_hit);

                if(monster_health<=0) {
                    printf("You defeat the monster!\n");
                    break;
                }

                // Monster's attack
                int monster_hit = rand() % 15 + 5;
                health -= monster_hit;
                printf("The monster hits you for %d damage\n", monster_hit);

                display_health();
            }

            if(health<=0) {
                printf("You have been defeated by the monster\n");
            }

        } else {
            printf("You run away from the monster\n");
        }

    } else {
        // Right path
        printf("\nYou go right and find a healing potion\n");
        printf("Do you drink the potion?\n");

        char drink_potion[10];
        scanf("%s", drink_potion);

        if(strcmp(drink_potion, "yes")==0) {
            health += 50;
            printf("Your health has been increased by 50\n");
            display_health();
        } else {
            printf("You don't drink the potion\n");
        }

        // Encounter with trap
        printf("As you go further, you encounter a trap\n");
        printf("Do you try to disarm it or go around?\n");

        char disarm_trap[10];
        scanf("%s", disarm_trap);

        if(strcmp(disarm_trap, "disarm")==0) {
            printf("You successfully disarm the trap and continue your journey\n");
        } else {
            int trap_damage = rand() % 30 + 10;
            health -= trap_damage;
            printf("You triggered the trap and take %d damage\n", trap_damage);
            display_health();
        }
    }

    // End of game
    if(health<=0) {
        printf("Game over! You have died.\n");
    } else {
        printf("Congratulations! You have found the treasure and won the game!\n");
        printf("Your final health: %d\n", health);
    }

    printf("Thank you for playing The Cave!\n");

    return 0;
}