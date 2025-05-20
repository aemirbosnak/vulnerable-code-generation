//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Happy Adventure Game! Let's go!\n\n");

    // Initializations
    char name[20];
    int age, choice, health = 100, coins = 0, sword = 0;
    srand(time(NULL));

    // Get player's name and age
    printf("What is your name?\n");
    scanf("%s", name);

    printf("How old are you?\n");
    scanf("%d", &age);

    printf("\nHello %s, let's begin our happy adventure!\n\n", name);

    // Start of the game
    printf("You are in a forest and you see three paths.\n");
    printf("Which path do you want to take? (1, 2 or 3)\n");

    // Get player's choice
    scanf("%d", &choice);

    // Execute choice
    switch (choice) {
        case 1:
            printf("You encounter a friendly squirrel! It gives you a shiny coin.\n");
            coins++;
            break;

        case 2:
            printf("You come across a stream and decide to take a drink. The water is refreshing and you gain 10 health points.\n");
            health += 10;
            break;

        case 3:
            printf("You find an abandoned sword on the ground.\n");
            sword = 1;
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    // Continue adventure
    printf("\nYou continue walking and see a monster!\n");
    printf("What do you want to do? (1 - fight, 2 - run)\n");

    // Get player's choice
    scanf("%d", &choice);

    // Fight or run
    if (choice == 1) {
        // Fight
        if (sword) {
            printf("You defeat the monster with your sword and gain another coin.\n");
            coins++;
        } else {
            printf("You try to fight the monster barehanded but it's too strong and you lose 20 health points.\n");
            health -= 20;
        }
    } else {
        // Run
        printf("You run as fast as you can and escape from the monster but lose 5 coins in the process.\n");
        coins -= 5;
    }

    // Final results
    printf("\nYour adventure is over! Let's see how it went.\n\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Health: %d\n", health);
    printf("Coins: %d\n", coins);
    printf("Sword: %s\n", sword ? "yes" : "no");

    // Goodbye message
    printf("\nThank you for playing the Happy Adventure Game! Have a wonderful day!\n");

    return 0;
}