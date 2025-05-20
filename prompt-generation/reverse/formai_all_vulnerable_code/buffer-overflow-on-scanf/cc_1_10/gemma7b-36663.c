//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice;
    char name[20];
    printf("Welcome to the Peaceful Forest of Serenity.\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s, you are standing in the heart of the forest.\n", name);

    // Create a loop to allow the player to explore the forest
    while (1)
    {
        // Display the available options
        printf("What would you like to do? (1) Walk north, (2) Walk south, (3) Walk east, (4) Walk west\n");
        scanf("%d", &choice);

        // Check if the player has chosen an option
        switch (choice)
        {
            case 1:
                printf("You walk north and find a clearing.\n");
                break;
            case 2:
                printf("You walk south and encounter a babbling brook.\n");
                break;
            case 3:
                printf("You walk east and stumble upon an ancient tree.\n");
                break;
            case 4:
                printf("You walk west and find a hidden cave.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Ask the player if they want to continue exploring the forest
        printf("Do you want to continue exploring? (Y/N) ");
        char continue_exploring;
        scanf("%c", &continue_exploring);

        // If the player does not want to continue exploring, break out of the loop
        if (continue_exploring != 'Y')
        {
            break;
        }
    }

    // Thank the player for exploring the forest
    printf("Thank you for exploring the Peaceful Forest of Serenity, %s. See you next time.\n", name);
}