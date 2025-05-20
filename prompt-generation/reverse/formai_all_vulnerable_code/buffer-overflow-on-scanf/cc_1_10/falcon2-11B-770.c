//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char* playerName;
    char* verb;
    char* noun;
    int choice;

    // Print welcome message
    printf("Welcome to the Text-Based Adventure Game!\n");

    // Prompt player for name
    printf("What is your name, adventurer? ");
    scanf("%s", playerName);

    // Print intro
    printf("You are a brave adventurer, %s, on a quest to find the legendary treasure.\n", playerName);
    printf("You are in a dark, spooky forest, and you can see a path leading deeper into the woods.\n");
    printf("What do you do?\n");

    // Print choices
    printf("1. Follow the path\n");
    printf("2. Turn back\n");

    // Prompt player for choice
    scanf("%d", &choice);

    // Handle choice
    switch(choice) {
        case 1:
            printf("You follow the path deeper into the woods. Suddenly, a giant troll jumps out and attacks you!\n");
            printf("What do you do?\n");
            printf("1. Run away\n");
            printf("2. Fight the troll\n");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("You run away from the troll and manage to escape. You continue on your quest.\n");
                    break;
                case 2:
                    printf("You fight the troll, but he is too strong. You die.\n");
                    break;
            }
            break;
        case 2:
            printf("You turn back and decide to find another path. You stumble upon a secret cave and discover the treasure!\n");
            printf("Congratulations, you have completed the game.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}