//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int choice;
    char name[20];
    int health = 100;

    // Get the player's name
    printf("What is your name, hero?\n");
    scanf("%s", name);

    // Introduction
    printf("Welcome, %s, to the world of Trogdor!\n", name);
    printf("You find yourself in a dark and menacing dungeon.\n");

    // Present options
    printf("What do you want to do?\n");
    printf("1. Attack\n");
    printf("2. Search\n");
    printf("3. Cast a spell\n");

    // Get the player's choice
    scanf("%d", &choice);

    // Handle the player's choice
    switch (choice)
    {
        case 1:
            // Attack code
            printf("You attack the dungeon's guardian.\n");
            break;
        case 2:
            // Search code
            printf("You search the dungeon for hidden treasures.\n");
            break;
        case 3:
            // Cast a spell code
            printf("You cast a spell on the dungeon's guardian.\n");
            break;
        default:
            // Invalid choice message
            printf("Invalid choice.\n");
    }

    // Check if the player is still alive
    if (health <= 0)
    {
        printf("You have perished, %s. Game over.\n", name);
    }

    // End of game
    return 0;
}