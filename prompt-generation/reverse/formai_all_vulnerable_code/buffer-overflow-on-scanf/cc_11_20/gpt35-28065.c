//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_ROOMS 5

int main()
{
    srand(time(NULL)); // Seed the random number generator 

    // Define the haunted house rooms
    bool rooms[NUM_ROOMS] = {false, false, false, false, false};

    // Initialize the player's position to the first room
    int player_pos = 0;

    // Define the available exits for each room
    int exits[NUM_ROOMS][2] = { {1, 2}, {0, 3}, {0, 4}, {1, 4}, {2, 3} };

    // Start the game loop
    while (true)
    {
        // Print the current room description
        printf("You are in room %d.\n", player_pos+1);
        printf("This room ");
        if (rooms[player_pos])
        {
            printf("is haunted.\n");
        }
        else
        {
            printf("is not haunted.\n");
        }

        // Print the available exits
        printf("You can exit to rooms ");
        for (int i=0; i<2; i++)
        {
            printf("%d and ", exits[player_pos][i]+1);
        }
        printf("\b\b.\n");

        // Get the player's choice of exit
        int choice;
        printf("Which room do you want to go to? ");
        scanf("%d", &choice);

        // Handle invalid input
        if (choice < 1 || choice > NUM_ROOMS || choice == player_pos+1)
        {
            printf("Invalid choice.\n");
            continue;
        }

        // Update the player's position
        player_pos = choice - 1;

        // Check if the new room is haunted
        if (rooms[player_pos])
        {
            printf("You have entered a haunted room!\n");

            // 50% chance of becoming haunted yourself
            if (rand() % 2 == 0)
            {
                printf("You have been haunted and will haunt other rooms!\n");
                rooms[player_pos] = true;
            }
        }
        else
        {
            printf("The room is safe.\n");

            // 10% chance of becoming haunted
            if (rand() % 10 == 0)
            {
                printf("The room has become haunted!\n");
                rooms[player_pos] = true;
            }
        }

        // Check if all rooms are haunted
        bool all_haunted = true;
        for (int i=0; i<NUM_ROOMS; i++)
        {
            if (!rooms[i])
            {
                all_haunted = false;
                break;
            }
        }

        if (all_haunted)
        {
            printf("You have haunted the entire house!\n");
            break;
        }
    }

    printf("Game over.\n");
    return 0;
}