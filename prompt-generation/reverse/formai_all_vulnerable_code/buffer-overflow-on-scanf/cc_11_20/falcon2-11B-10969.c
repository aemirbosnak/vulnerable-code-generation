//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char command[MAX_LEN];
    char player_name[MAX_LEN];

    printf("Welcome to the Future Adventure Game!\n\n");
    printf("Enter your name: ");
    scanf("%s", player_name);
    printf("Welcome, %s! Let's begin your adventure!\n", player_name);

    while (1) {
        printf("What do you want to do? (type 'quit' to exit)\n");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            printf("Goodbye, %s!\n", player_name);
            break;
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("    quit - exit the game\n");
            printf("    help - display available commands\n");
            printf("    explore - explore your surroundings\n");
            printf("    talk - talk to people\n");
            printf("    fight - engage in combat\n");
            printf("    use - use items or abilities\n");
            printf("    inventory - view your inventory\n");
        } else if (strcmp(command, "explore") == 0) {
            printf("You walk around and see a cave.\n");
            printf("Do you want to enter the cave? (yes/no)\n");
            scanf("%s", command);

            if (strcmp(command, "yes") == 0) {
                printf("You enter the cave and find a treasure chest.\n");
                printf("Do you want to open the chest? (yes/no)\n");
                scanf("%s", command);

                if (strcmp(command, "yes") == 0) {
                    printf("You open the chest and find a shiny new weapon.\n");
                    printf("You add the weapon to your inventory.\n");
                } else {
                    printf("You leave the cave without opening the chest.\n");
                }
            } else {
                printf("You decide not to enter the cave.\n");
            }
        } else if (strcmp(command, "talk") == 0) {
            printf("You see a robot walking by.\n");
            printf("Do you want to talk to the robot? (yes/no)\n");
            scanf("%s", command);

            if (strcmp(command, "yes") == 0) {
                printf("You approach the robot and say hello.\n");
                printf("The robot replies with a friendly greeting.\n");
            } else {
                printf("You decide not to talk to the robot.\n");
            }
        } else if (strcmp(command, "fight") == 0) {
            printf("You see a group of hostile robots approaching you.\n");
            printf("Do you want to fight them? (yes/no)\n");
            scanf("%s", command);

            if (strcmp(command, "yes") == 0) {
                printf("You engage in combat with the robots.\n");
                printf("You manage to defeat them and gain some experience points.\n");
                printf("Do you want to level up? (yes/no)\n");
                scanf("%s", command);

                if (strcmp(command, "yes") == 0) {
                    printf("You level up and gain some new abilities.\n");
                } else {
                    printf("You decide not to level up.\n");
                }
            } else {
                printf("You decide not to fight the robots.\n");
            }
        } else if (strcmp(command, "use") == 0) {
            printf("You find a potion in your inventory.\n");
            printf("Do you want to use the potion? (yes/no)\n");
            scanf("%s", command);

            if (strcmp(command, "yes") == 0) {
                printf("You drink the potion and gain some temporary buffs.\n");
            } else {
                printf("You decide not to use the potion.\n");
            }
        } else if (strcmp(command, "inventory") == 0) {
            printf("You have:\n");
            printf("- Sword\n");
            printf("- Potion\n");
        } else {
            printf("I don't understand that command.\n");
        }
    }

    return 0;
}