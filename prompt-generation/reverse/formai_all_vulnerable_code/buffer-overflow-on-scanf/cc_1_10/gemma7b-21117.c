//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define the main character's name
    char name[20];

    // Get the character's name from the user
    printf("Please enter your name: ");
    scanf("%s", name);

    // Display a welcome message
    printf("Welcome, %s, to the Text-Based Adventure Game!\n", name);

    // Create a simple inventory
    int inventory[5] = {0, 0, 0, 0, 0};

    // Define the game loop
    int game_loop = 1;

    // While the game loop is active, continue the game
    while (game_loop)
    {
        // Display the current inventory
        printf("Your inventory: ");
        for (int i = 0; i < 5; i++)
        {
            if (inventory[i] > 0)
            {
                printf("%d ", inventory[i]);
            }
        }

        // Get the user's command
        char command[20];
        printf("\nEnter a command: ");
        scanf("%s", command);

        // Check if the command is valid
        if (strcmp(command, "quit") == 0)
        {
            // The user wants to quit the game
            game_loop = 0;
        }
        else if (strcmp(command, "look") == 0)
        {
            // The user wants to look around
            printf("You are in a mysterious room. There is a door to the north and a window to the east.\n");
        }
        else if (strcmp(command, "take") == 0)
        {
            // The user wants to take an item
            char item_name[20];
            printf("What item do you want to take? ");
            scanf("%s", item_name);

            // Check if the item is available
            for (int i = 0; i < 5; i++)
            {
                if (strcmp(item_name, inventory[i]) == 0)
                {
                    // The item is in the inventory
                    inventory[i]++;
                    printf("You have taken the %s.\n", item_name);
                }
            }
        }
        else
        {
            // The command is not valid
            printf("Invalid command.\n");
        }
    }

    // Display a goodbye message
    printf("Thank you for playing, %s. See you next time!\n", name);

    return 0;
}