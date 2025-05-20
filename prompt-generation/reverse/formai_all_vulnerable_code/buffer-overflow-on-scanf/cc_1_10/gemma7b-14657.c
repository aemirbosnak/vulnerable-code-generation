//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a simple text-based adventure game

    // Define the main characters
    char name[20];
    int health = 100;
    int strength = 50;

    // Describe the current location
    char location = 'a';

    // Set up the game loop
    while (health > 0)
    {
        // Display the current location
        switch (location)
        {
            case 'a':
                printf("You are in a cozy cottage.\n");
                break;
            case 'b':
                printf("You are in a haunted castle.\n");
                break;
            case 'c':
                printf("You are in a fiery dragon's lair.\n");
                break;
        }

        // Get the user's input
        char input[20];
        printf("What do you want to do? ");
        scanf("%s", input);

        // Process the user's input
        if (strcmp(input, "fight") == 0)
        {
            // Engage in combat
            int damage = strength * 2;
            printf("You fought a mighty foe and dealt %d damage.\n", damage);
        }
        else if (strcmp(input, "explore") == 0)
        {
            // Explore the environment
            location++;
            printf("You explored the area and found a new location.\n");
        }
        else if (strcmp(input, "heal") == 0)
        {
            // Heal your wounds
            health++;
            printf("You healed your wounds.\n");
        }
        else
        {
            // Invalid input
            printf("Invalid input.\n");
        }
    }

    // Game over
    printf("Game over. Your character has died.\n");

    return 0;
}