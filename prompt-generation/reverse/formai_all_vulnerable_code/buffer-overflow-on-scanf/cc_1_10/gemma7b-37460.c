//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spooky_sounds(int);

int main()
{
    int choice, i, r;
    time_t t;

    // Initialize the seed for random numbers
    srand(time(NULL));

    // Create a loop to keep the game running
    while (1)
    {
        // Display the options
        printf("Enter 1 to explore the haunted house, 2 to leave: ");

        // Get the user's choice
        scanf("%d", &choice);

        // Check if the user wants to explore the haunted house
        if (choice == 1)
        {
            // Generate a random room number
            r = rand() % 5;

            // Play spooky sounds
            spooky_sounds(r);

            // Display a message
            printf("You are in room %d. There is a feeling of dread in the air.\n", r);

            // Check if the user wants to leave
            printf("Enter 1 to leave, 2 to continue: ");
            scanf("%d", &choice);

            // If the user wants to leave, break out of the loop
            if (choice == 1)
            {
                break;
            }
        }

        // Leave the haunted house
        else if (choice == 2)
        {
            break;
        }

        // Invalid input
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

void spooky_sounds(int r)
{
    switch (r)
    {
        case 0:
            printf("Footsteps echoing through the hallway.\n");
            break;
        case 1:
            printf("A chilling wind blows through the trees.\n");
            break;
        case 2:
            printf("The sound of a door slamming shut.\n");
            break;
        case 3:
            printf("A ghostly moan.\n");
            break;
        case 4:
            printf("The sound of a broken clock.\n");
            break;
    }
}