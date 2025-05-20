//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int i, n, choice;

    // Seed the random number generator
    srand(time(NULL));

    // Create a loop to simulate the haunted house
    for (i = 0; i < 10; i++)
    {
        // Display the haunted house options
        printf("Enter 1 to go to the living room, 2 to go to the kitchen, or 3 to go to the bedroom:\n");

        // Get the user's choice
        scanf("%d", &choice);

        // Simulate the haunted house event
        switch (choice)
        {
            case 1:
                printf("You hear a shuffling sound in the living room.\n");
                break;
            case 2:
                printf("You smell burning food in the kitchen.\n");
                break;
            case 3:
                printf("You hear footsteps in the bedroom.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Generate a random event
        n = rand() % 3;

        // Simulate the random event
        switch (n)
        {
            case 0:
                printf("A ghostly figure appears.\n");
                break;
            case 1:
                printf("A door slams shut.\n");
                break;
            case 2:
                printf("A voice whispers in your ear.\n");
                break;
        }

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n) ");

        // Get the user's answer
        scanf(" %c", &choice);

        // If the user does not want to continue, break out of the loop
        if (choice == 'n')
            break;
    }

    // Thank the user for playing
    printf("Thank you for playing the haunted house simulator.\n");
}