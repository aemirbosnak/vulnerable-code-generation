//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    system("clear");
    srand(time(NULL));
    int choice = 0;

    // Haunted House Menu
    printf("Welcome to the Haunted House of horrors...\n");
    printf("1. Enter the house.\n");
    printf("2. Exit.\n");
    printf("Please make a selection: ");

    // Get user input
    scanf("%d", &choice);

    // Enter the house
    if (choice == 1)
    {
        system("clear");
        printf("You have entered the haunted house. Prepare for a fright...\n");

        // Randomly generate a scare
        int scare = rand() % 3;

        // Show the scare
        switch (scare)
        {
            case 0:
                printf("You hear a scream in the hallway.\n");
                break;
            case 1:
                printf("A ghostly figure appears before you.\n");
                break;
            case 2:
                printf("A bloodcurdling scream echoes through the house.\n");
                break;
        }

        // Ask the user if they want to continue
        printf("Do you want to continue exploring the haunted house? (Y/N) ");

        // Get user input
        char answer;
        scanf("%c", &answer);

        // Exit the house
        if (answer == 'N' || answer == 'n')
        {
            system("clear");
            printf("You have safely exited the haunted house. Thank you for visiting.\n");
        }
    }

    // Exit the program
    return;
}