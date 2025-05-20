//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int hp = 100; // Player's Hit points
int damage = 10; // Player's damage

int enemy_hp = 50; // Enemy's hit points
int enemy_damage = 5; // Enemy's damage

int level = 1; // Player's Level
int experience = 0; // Player's Experience

int choice; // Player's Choice
char name[20]; // Player's Name

void instructions() {

    printf("\nGreetings adventurer! Welcome to the Text-Based Adventure Game!\n");
    printf("In this game, you will be presented with different choices and your decisions will affect the outcome of your adventure.\n");
    printf("You will encounter enemies, collect treasures, and gain experience as you progress through the game.\n");
    printf("Be careful though, as your choices can either lead you to victory or defeat.\n");
    printf("Press 'Enter' to continue...\n");
    getchar();
}

void start() {

    printf("\nBefore we begin, what is your name adventurer?\n");
    scanf("%s", name);
    printf("\nWelcome %s! Your adventure begins now!\n", name);
    printf("Press 'Enter' to continue...\n");
    getchar();
}

void battle() {

    printf("\nYou have encountered an enemy.\n");
    printf("Enemy's hit points: %d\n", enemy_hp);
    printf("Enemy's damage: %d\n", enemy_damage);
    printf("\nWhat will you do?\n");
    printf("1. Attack\n");
    printf("2. Defend\n");
    printf("3. Run\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nYou attacked the enemy!\n");
            enemy_hp -= damage;
            printf("Enemy's hit points: %d\n", enemy_hp);

            if (enemy_hp <= 0) {
                printf("\nYou have defeated the enemy!\n");
                experience += 20;
                printf("You gained 20 experience points.\n");
            } else {
                printf("\nThe enemy attacked you!\n");
                hp -= enemy_damage;
                printf("Your hit points: %d\n", hp);

                if (hp <= 0) {
                    printf("\nYou have been defeated by the enemy!\n");
                    printf("GAME OVER\n");
                    exit(0);
                }
            }

            break;
        case 2:
            printf("\nYou chose to defend!\n");
            printf("The enemy attacked you but you only received half the damage.\n");
            hp -= enemy_damage / 2;
            printf("Your hit points: %d\n", hp);

            if (hp <= 0) {
                printf("\nYou have been defeated by the enemy!\n");
                printf("GAME OVER\n");
                exit(0);
            }

            break;
        case 3:
            printf("\nYou chose to run!\n");
            printf("You managed to escape from the enemy.\n");
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
    }
}

void treasure() {

    printf("\nYou found a treasure chest!\n");
    printf("What will you do?\n");
    printf("1. Open it\n");
    printf("2. Leave it\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nYou opened the treasure chest!\n");
            printf("You found a potion. Your hit points have been restored.\n");
            hp = 100;

            break;
        case 2:
            printf("\nYou left the treasure chest untouched.\n");

            break;

        default:
            printf("\nInvalid choice!\n");
            break;
    }
}

void level_up() {

    if (experience >= 50) {
        printf("\nCongratulations! You have reached Level 2!\n");
        level++;
        hp = 150;
        damage += 5;
        printf("Your hit points have increased to %d.\n", hp);
        printf("Your damage has increased to %d\n", damage);
    }

}

int main() {

    srand(time(NULL)); // Seed for random number generator

    instructions();
    start();

    while (1) {

        printf("\nWhat would you like to do next %s?\n", name);
        printf("1. Battle\n");
        printf("2. Treasure\n");
        printf("3. Quit\n\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                battle();

                break;
            case 2:
                treasure();

                break;
            case 3:
                printf("\nThank you for playing the Text-Based Adventure Game %s!\n", name);
                printf("Your final score is %d.\n", experience);
                printf("Goodbye!\n");
                exit(0);

                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }

        level_up();
    }

    return 0;
}