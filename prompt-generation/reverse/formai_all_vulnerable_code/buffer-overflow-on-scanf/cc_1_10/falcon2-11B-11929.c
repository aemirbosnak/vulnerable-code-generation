//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Variables to store the current room and items
    int current_room = 1;
    char current_item[20] = "";
    char current_inventory[20] = "";
    
    // Initialize the game
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in a dark room.\n");
    printf("You can see a door to your left and a door to your right.\n");
    
    // Loop until the player exits the game
    while (1)
    {
        // Prompt the player to choose an action
        printf("What do you want to do?\n");
        printf("1. Go through the left door\n");
        printf("2. Go through the right door\n");
        printf("3. Check your inventory\n");
        printf("4. Quit the game\n");
        printf("Enter your choice: ");
        
        // Get the player's input and convert it to an integer
        int choice;
        if (scanf("%d", &choice) == 1)
        {
            if (choice == 1)
            {
                // If the player chooses to go through the left door, move to the next room
                if (current_room == 1)
                {
                    printf("You cannot go through this door.\n");
                }
                else
                {
                    printf("You enter the next room.\n");
                    current_room++;
                }
            }
            else if (choice == 2)
            {
                // If the player chooses to go through the right door, move to the next room
                if (current_room == 1)
                {
                    printf("You cannot go through this door.\n");
                }
                else
                {
                    printf("You enter the next room.\n");
                    current_room++;
                }
            }
            else if (choice == 3)
            {
                // If the player chooses to check their inventory, print it
                printf("You have the following items in your inventory: %s\n", current_item);
            }
            else if (choice == 4)
            {
                // If the player chooses to quit the game, exit the loop
                break;
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
            }
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    // Print the game over message
    printf("Game Over!\n");
    return 0;
}