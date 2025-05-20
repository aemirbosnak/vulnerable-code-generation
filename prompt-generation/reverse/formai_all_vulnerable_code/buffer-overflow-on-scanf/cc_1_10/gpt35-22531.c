//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int health = 100;
int gold = 0;

void introduction() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a forest. You have no memory of how you got here.\n");
    printf("You have a sword, shield and a map. Good luck on your adventure!\n");
}

void main_menu() {
    printf("What would you like to do?\n");
    printf("1. Explore the forest\n");
    printf("2. Check inventory\n");
    printf("3. Exit\n");
}

void explore_forest() {
    printf("You are now exploring the forest...\n");
    int enemy = rand() % 3; // generates a random enemy encounter
    if (enemy == 0) {
        printf("You have encountered a goblin!\n");
        int attack = rand() % 20; // generates a random attack
        printf("The goblin attacks you for %d damage!\n", attack);
        health -= attack; // subtracts attack damage from health
        printf("Your health is now %d.\n", health);
        if (health <= 0) {
            printf("You have been defeated. Game over.\n");
            exit(0);
        }
        else {
            printf("You have successfully defeated the goblin!\n");
            int gold_earned = rand() % 20;
            printf("You have earned %d gold.\n", gold_earned);
            gold += gold_earned; // adds earned gold to total gold
            printf("Your total gold is now %d.\n", gold);
        }
    }
    else {
        printf("You wander aimlessly through the forest with no encounters.\n");
    }
}

void check_inventory() {
    printf("Sword: Yes\n");
    printf("Shield: Yes\n");
    printf("Map: Yes\n");
    printf("Health: %d\n", health);
    printf("Gold: %d\n", gold);
}

int main() {
    introduction();
    while (1) {
        main_menu();
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            explore_forest();
        }
        else if (choice == 2) {
            check_inventory();
        }
        else if (choice == 3) {
            printf("Goodbye! Thanks for playing.\n");
            exit(0);
        }
        else {
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}