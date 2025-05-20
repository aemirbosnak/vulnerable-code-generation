//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main()
{
    // Create a variable to store the player's name
    char player_name[20];

    // Get the player's name from the user
    printf("What is your name? ");
    scanf("%s", player_name);

    // Print a welcome message
    printf("Welcome, %s, to the Text-Based Adventure Game!\n", player_name);

    // Create a loop to keep the game running
    int game_running = 1;

    // While the game is running, the player will continue to make choices
    while (game_running)
    {
        // Display the available choices
        printf("You are in a room with three doors.\n");
        printf("Door 1 is red and leads to the east.\n");
        printf("Door 2 is blue and leads to the south.\n");
        printf("Door 3 is green and leads to the west.\n");

        // Get the player's choice
        int choice = 0;
        printf("Please choose a door number: ");
        scanf("%d", &choice);

        // Check if the player's choice is valid
        if (choice < 1 || choice > 3)
        {
            // Print an error message
            printf("Invalid choice.\n");
        }
        else
        {
            // The player has made a valid choice, so we will move to the next room
            game_running = 0;
        }
    }

    // Print a goodbye message
    printf("Thank you for playing, %s.\n", player_name);

    // Return 0 to indicate successful execution
    return 0;
}