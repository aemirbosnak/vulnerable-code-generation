//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int health = 100;
    int inventory[5] = {0, 0, 0, 0, 0};
    char current_location[20] = "The Great Hall";

    printf("Welcome to the grand hall of the mysterious castle!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    // Start the adventure
    while (health > 0)
    {
        // Display the current location
        printf("You are currently in: %s\n", current_location);

        // List the available actions
        printf("What would you like to do? (fight, explore, search, inventory)\n");
        char action[20];
        scanf("%s", action);

        // Process the action
        if (strcmp(action, "fight") == 0)
        {
            // Fight a monster
            printf("You encountered a monstrous creature! Prepare for battle...\n");
            // Combat mechanics
        }
        else if (strcmp(action, "explore") == 0)
        {
            // Explore the surroundings
            printf("You decided to explore the hall. You found a hidden secret...\n");
            // Secret mechanics
        }
        else if (strcmp(action, "search") == 0)
        {
            // Search for items
            printf("You searched the area and found a valuable item...\n");
            // Inventory mechanics
        }
        else if (strcmp(action, "inventory") == 0)
        {
            // Display your inventory
            printf("Your inventory:\n");
            for (int i = 0; i < 5; i++)
            {
                if (inventory[i] > 0)
                {
                    printf("%d. %s\n", i + 1, inventory[i]);
                }
            }
        }
        else
        {
            // Invalid action
            printf("Invalid action. Please try again.\n");
        }
    }

    // Game over
    printf("Game over, %s. You have defeated the evil overlord.\n", name);

    return 0;
}