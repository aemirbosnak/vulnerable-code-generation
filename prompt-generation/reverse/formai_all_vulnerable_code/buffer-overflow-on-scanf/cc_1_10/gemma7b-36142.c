//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to store the player's inventory
    typedef struct Item
    {
        char name[20];
        int quantity;
    } Item;

    // Create a list of items in the player's inventory
    Item inventory[10] = {{ "Sword", 3 }, {"Shield", 2 }, {"Healing Potion", 1 }, {"Gold Coin", 50 }};

    // Print the player's inventory
    printf("Your inventory:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s - %d\n", inventory[i].name, inventory[i].quantity);
    }

    // Get the player's input
    char input[20];
    printf("Enter a command: ");
    scanf("%s", input);

    // Check if the player's input is to use an item
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(input, inventory[i].name) == 0)
        {
            // Use the item
            printf("You used the %s.\n", inventory[i].name);
            inventory[i].quantity--;

            // Check if the item is still in the player's inventory
            if (inventory[i].quantity == 0)
            {
                // Remove the item from the player's inventory
                for (int j = i; j < 10; j++)
                {
                    inventory[j] = inventory[j + 1];
                }
            }

            break;
        }
    }

    // If the player did not use an item, print an error message
    if (strcmp(input, "") != 0 && strcmp(input, "help") != 0)
    {
        printf("Invalid command.\n");
    }

    return 0;
}