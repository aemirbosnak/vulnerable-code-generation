//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char player[20]; // Player name
    char choice[20]; // Player choice
    int coins = 10; // Starting coins
    int health = 100; // Starting health
    int key = 0; // Key status

    // Introduction
    printf("Welcome to the Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", player);
    printf("\nWelcome, %s! Let's start the game!\n", player);
    printf("You find yourself in a dark forest with no idea how you got there.\n");

    // Game loop
    while (health > 0) {
        printf("\nWhat do you want to do? Choose an option from the list below:\n");
        printf("1. Look for a way out\n");
        printf("2. Search for items\n");
        printf("3. Check your status\n");
        printf("4. Quit the game\n");
        printf("Your choice: ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            printf("\nYou wander through the forest, searching for a way out.\n");
            if (key == 1) {
                printf("You find a locked door and use the key you found to open it.\n");
                printf("Congratulations, %s! You have escaped the forest!\n", player);
                break;
            }
            else {
                printf("You wander for hours without finding anything.\n");
                printf("You stumble across a small pond and drink some water to regain some health points.\n");
                health += 10;
            }
        }

        else if (strcmp(choice, "2") == 0) {
            printf("\nYou search the area for any useful items.\n");
            int itemChance = rand() % 10;
            if (itemChance >= 5) {
                printf("You find a rusty key on the ground.\n");
                printf("It might come in handy later.\n");
                key = 1;
            }
            else {
                printf("You don't find anything useful.\n");
            }
        }

        else if (strcmp(choice, "3") == 0) {
            printf("\nYour current status:\n");
            printf("Coins: %d\n", coins);
            printf("Health: %d\n", health);
            printf("Key: %s\n", key ? "yes" : "no");
        }

        else if (strcmp(choice, "4") == 0) {
            printf("\nAre you sure you want to quit the game? (yes/no) ");
            scanf("%s", choice);
            if (strcmp(choice, "yes") == 0) {
                printf("\nGoodbye, %s! Thanks for playing!\n", player);
                break;
            }
            else {
                printf("\nGlad you decided to stay!\n");
            }
        }

        else {
            printf("\nI'm sorry, that is not a valid choice. Please try again.\n");
        }

        // Random damage
        int damage = rand() % 20;
        health -= damage;
        printf("\nOh no! You took %d damage from an unseen force!\n", damage);

        // Game over
        if (health <= 0) {
            printf("\nYou died. Game over.\n");
            break;
        }
    }

    return 0;
}