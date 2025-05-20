//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int age, room_num, inventory[5] = {0, 0, 0, 0, 0};
    char current_room[20] = "The Entrance Hall";

    // Welcome the player and gather their name and age
    printf("Welcome to the mysterious mansion, %s. Please tell me your name and age:\n", name);
    scanf("%s %d", name, &age);

    // Assign a random room number
    room_num = rand() % 5 + 1;

    // Create the inventory and assign items
    inventory[0] = "A rusty sword";
    inventory[1] = "A worn-down backpack";
    inventory[2] = "A silver key";
    inventory[3] = "A bottle of poison";
    inventory[4] = "A glowing stone";

    // Enter the chosen room and interact with the environment
    switch (room_num)
    {
        case 1:
            printf("You are in the Entrance Hall. The only thing you see is a grand staircase leading up to the second floor.\n");
            break;
        case 2:
            printf("You are in the Dining Hall. There is a table with a feast on it, but it is empty.\n");
            break;
        case 3:
            printf("You are in the Library. There are many bookshelves filled with books.\n");
            break;
        case 4:
            printf("You are in the Ballroom. There is a dance floor and a bar.\n");
            break;
        case 5:
            printf("You are in the Master Bedroom. There is a bed, a dresser, and a mirror.\n");
            break;
    }

    // Prompt the player to enter a command
    printf("Please enter your command: ");

    // Get the player's command and process it
    char command[20];
    scanf("%s", command);

    // Check if the player has entered a valid command
    if (strcmp(command, "look") == 0)
    {
        // Describe the room
        printf("You look around and see:\n");
        printf("%s\n", current_room);
        printf("Your inventory: \n");
        for (int i = 0; i < 5; i++)
        {
            if (inventory[i] != 0)
            {
                printf("%s\n", inventory[i]);
            }
        }
    }
    else if (strcmp(command, "take") == 0)
    {
        // Check if the player has picked up an item
        int item_taken = 0;
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(inventory[i], command) == 0)
            {
                item_taken = 1;
            }
        }

        // If the player has taken an item, describe the item
        if (item_taken)
        {
            printf("You have taken the %s.\n", command);
        }
        else
        {
            printf("You cannot take that item.\n");
        }
    }
    else if (strcmp(command, "use") == 0)
    {
        // Check if the player has the item they want to use
        int item_used = 0;
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(inventory[i], command) == 0)
            {
                item_used = 1;
            }
        }

        // If the player has used an item, describe the effect of the item
        if (item_used)
        {
            printf("You use the %s and it has the following effect:\n", command);
            printf("...\n");
        }
        else
        {
            printf("You do not have that item.\n");
        }
    }
    else
    {
        printf("Invalid command.\n");
    }

    return 0;
}