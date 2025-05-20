//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char name[20];
    int health = 100;

    printf("Welcome to the Text-Based Adventure Game, %s!\n", name);
    printf("You are in a dark forest. You hear rustling in the bushes...\n");

    // Loop until the player makes a choice
    while (1)
    {
        printf("Please enter your choice (1, 2, 3): ");
        scanf("%d", &choice);

        // Check if the player's choice is valid
        if (choice < 1 || choice > 3)
        {
            printf("Invalid choice. Please try again.\n");
        }
        else
        {
            break;
        }
    }

    // Based on the player's choice, take different actions
    switch (choice)
    {
        case 1:
            printf("You decide to attack the rustling in the bushes. You swing your sword and...", name);
            break;
        case 2:
            printf("You decide to flee. You run away from the forest...\n");
            break;
        case 3:
            printf("You decide to search for a way to escape. You look around for...", name);
            break;
    }

    // Check if the player's health is still at 100%
    if (health <= 0)
    {
        printf("You have died. Game over.\n");
    }
    else
    {
        printf("You have survived the encounter. You are safe.\n");
    }

    return 0;
}