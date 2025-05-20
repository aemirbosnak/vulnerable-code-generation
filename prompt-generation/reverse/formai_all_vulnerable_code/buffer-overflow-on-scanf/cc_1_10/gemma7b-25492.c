//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int choice;
    char name[20];
    char inventory[10] = {0};
    int health = 100;
    int room = 1;

    printf("Welcome to The Astral Realm, %s.\n", name);
    printf("You find yourself in a mysterious chamber, filled with arcane artifacts.\n");

    // Loop until the player makes a choice
    while (1)
    {
        printf("What do you want to do? (1) Examine the surroundings, (2) Search for clues, (3) Attack?\n");
        scanf("%d", &choice);

        // Check if the player's choice is valid
        if (choice < 1 || choice > 3)
        {
            printf("Invalid choice.\n");
        }
        else
        {
            break;
        }
    }

    // Based on the player's choice, execute different actions
    switch (choice)
    {
        case 1:
            printf("You examine the chamber and find a hidden compartment.\n");
            inventory[0] = "Crystal Ball";
            break;
        case 2:
            printf("You search for clues and find a cryptic note.\n");
            inventory[1] = "Scroll of Secrets";
            break;
        case 3:
            printf("You attack the mysterious artifact and damage it.\n");
            health -= 20;
            break;
    }

    // Check if the player's health is still above 0
    if (health <= 0)
    {
        printf("You have succumbed to your wounds. Game over.\n");
    }
    else
    {
        printf("You have successfully explored the chamber. Thank you for playing.\n");
    }

    return;
}