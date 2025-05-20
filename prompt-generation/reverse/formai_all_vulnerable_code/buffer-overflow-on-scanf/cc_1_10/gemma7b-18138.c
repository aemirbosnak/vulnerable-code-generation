//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    // Define a list of available rooms
    char **rooms = malloc(5 * sizeof(char *));
    rooms[0] = "The grand hall";
    rooms[1] = "The library";
    rooms[2] = "The kitchen";
    rooms[3] = "The dining hall";
    rooms[4] = "The secret room";

    // Get the player's current room
    char current_room = rooms[0];

    // Loop until the player wins or loses
    while (1)
    {
        // Display the current room
        printf("You are in: %s\n", current_room);

        // Get the player's input
        char input[20];
        printf("What do you want to do? ");
        scanf("%s", input);

        // Check if the player's input is valid
        if (strcmp(input, "go north") == 0 || strcmp(input, "go south") == 0 || strcmp(input, "go east") == 0 || strcmp(input, "go west") == 0)
        {
            // Move the player to the next room
            current_room = rooms[1];
        }
        else
        {
            // Print an error message
            printf("Invalid input.\n");
        }
    }

    // Free the memory allocated for the rooms list
    free(rooms);
}

int main()
{
    play_game();

    return 0;
}