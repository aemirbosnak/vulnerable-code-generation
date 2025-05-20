//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void main()
{
    int i, j, n, r, seed, choice;
    char name[MAX];

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Get the user's name
    printf("What is your name: ");
    scanf("%s", name);

    // Create a loop to simulate the haunted house
    for (n = 0; n < MAX; n++)
    {
        // Choose a random room
        r = rand() % 5;

        // Display the room
        switch (r)
        {
            case 0:
                printf("You are in the living room.\n");
                break;
            case 1:
                printf("You are in the kitchen.\n");
                break;
            case 2:
                printf("You are in the dining room.\n");
                break;
            case 3:
                printf("You are in the bedroom.\n");
                break;
            case 4:
                printf("You are in the hallway.\n");
                break;
        }

        // Simulate a ghostly encounter
        if (rand() % 2 == 0)
        {
            printf("You hear a strange noise.\n");
            printf("You feel a cold breeze on your skin.\n");
            printf("You hear footsteps coming towards you.\n");
        }

        // Ask the user if they want to continue
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &choice);

        // If the user does not want to continue, break out of the loop
        if (choice == 'N')
        {
            break;
        }
    }

    // Thank the user for visiting the haunted house
    printf("Thank you for visiting the haunted house, %s.\n", name);
}