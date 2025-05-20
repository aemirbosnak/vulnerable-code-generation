//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];
    int hp = 100;

    // Introduction
    printf("Welcome to the Adventure Game!\n");
    printf("What is your name, adventurer? ");
    scanf("%s", name);
    printf("\n%s, your journey begins!\n", name);
    printf("You find yourself in a dark forest with no idea how you got here.\n");

    // Game Loop
    while (hp > 0) {
        char action[20];
        printf("\nWhat do you want to do? (type 'help' for a list of commands) ");
        scanf("%s", action);

        // Move command
        if (strcmp(action, "move") == 0) {
            printf("You start walking through the forest.\n");
            hp -= 10; // walking takes energy
            printf("Your health is now %d\n", hp);
        }

        // Rest command
        else if (strcmp(action, "rest") == 0) {
            printf("You find a peaceful spot and take a rest.\n");
            hp += 20; // resting restores health
            printf("Your health is now %d\n", hp);
        }

        // Help command
        else if (strcmp(action, "help") == 0) {
            printf("List of commands:\n");
            printf(" - move: moves you through the forest, takes 10 health points\n");
            printf(" - rest: makes you rest, restores 20 health points\n");
            printf(" - quit: ends the game\n");
        }

        // Quit command
        else if (strcmp(action, "quit") == 0) {
            printf("You quit the game. Goodbye, %s!\n", name);
            exit(0);
        }

        // Invalid command
        else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    // Game over
    printf("Your health reaches zero. Game over, %s!\n", name);
    return 0;
}