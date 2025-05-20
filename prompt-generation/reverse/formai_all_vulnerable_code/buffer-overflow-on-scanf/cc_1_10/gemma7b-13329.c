//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a variable to store the player's name
    char name[20];

    // Get the player's name from the user
    printf("What is your name? ");
    scanf("%s", name);

    // Welcome the player to the game
    printf("Welcome, %s, to the Text-Based Adventure Game!\n", name);

    // Create a loop to keep the game running
    while (1)
    {
        // Display the available options
        printf("You are in a room with two doors. To the north, there is a door painted with a red flag. To the east, there is a door painted with a blue flag.\n");

        // Get the player's choice
        printf("What direction do you want to go? (north/east): ");
        char choice[20];
        scanf("%s", choice);

        // Check if the player's choice is valid
        if (strcmp(choice, "north") == 0 || strcmp(choice, "east") == 0)
        {
            // Open the door and move to the next room
            printf("You opened the door and stepped through. You are in the next room.\n");
        }
        else
        {
            // Tell the player that their choice is invalid
            printf("Invalid choice. Please try again.\n");
        }

        // Ask the player if they want to continue playing
        printf("Do you want to continue playing? (yes/no): ");
        char continue_choice[20];
        scanf("%s", continue_choice);

        // Check if the player wants to continue playing
        if (strcmp(continue_choice, "yes") == 0)
        {
            // Continue the game
            continue;
        }
        else
        {
            // End the game
            printf("Thank you for playing, %s. See you next time.\n", name);
            break;
        }
    }

    return 0;
}