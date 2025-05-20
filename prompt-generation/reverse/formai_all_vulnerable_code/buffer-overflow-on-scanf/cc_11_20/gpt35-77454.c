//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Opening message
    printf("Welcome to the Haunted House Simulator!\n\n");

    // Declaration of variables
    int is_in_room = 0; // 0 represents outside of room, 1 represents inside of room
    int has_flashlight = 0; // 0 represents no flashlight, 1 represents flashlight owned
    int ghost_location = 0; // 0 represents ghost not in room, 1 represents ghost in room
    int player_choice; // Player's choice of action

    // Setting seed for random number generator
    srand(time(NULL));

    // Main game loop
    while (1)
    {
        // Display player's options
        printf("What would you like to do?\n");
        printf("1. Enter room\n");
        printf("2. Search for flashlight\n");
        printf("3. Quit game\n");

        // Get player's choice of action
        scanf("%d", &player_choice);

        // Process player's choice of action
        switch (player_choice)
        {
            case 1:
                // Player enters room
                is_in_room = 1;
                printf("You enter the room. It is dark and cold.\n");

                // Random chance of ghost appearing
                if (rand() % 2 == 0)
                {
                    ghost_location = 1;
                    printf("Suddenly, you feel a cold breath on your neck. You turn around and see a ghost hovering behind you!\n");
                }
                break;

            case 2:
                // Player searches for flashlight
                if (!has_flashlight)
                {
                    has_flashlight = 1;
                    printf("You search the room and find a flashlight!\n");
                }
                else
                {
                    printf("You already have a flashlight!\n");
                }
                break;

            case 3:
                // Player quits game
                printf("Thanks for playing! Goodbye!\n");
                exit(0);

            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // Check if player has been caught by the ghost
        if (ghost_location && is_in_room)
        {
            printf("The ghost catches you and you are never seen again...\n");
            exit(0);
        }

        // Check if player has won the game
        if (has_flashlight && !ghost_location && is_in_room)
        {
            printf("Congratulations! You have found the flashlight and escaped the haunted house!\n");
            exit(0);
        }
    }

    return 0;
}