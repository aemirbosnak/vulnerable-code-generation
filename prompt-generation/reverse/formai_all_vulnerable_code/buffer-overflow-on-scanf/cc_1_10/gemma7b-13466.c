//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice;
    char name[20];
    char location = 'A';

    printf("Welcome to the Text-Based Adventure Game, %s!\n", name);
    printf("You are currently at Location %c.\n", location);

    // Loop until the user chooses an option
    while (1)
    {
        printf("Please choose an option:\n");
        printf("1. Travel North\n");
        printf("2. Travel South\n");
        printf("3. Travel East\n");
        printf("4. Travel West\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                location = 'B';
                printf("You traveled North and have arrived at Location %c.\n", location);
                break;
            case 2:
                location = 'C';
                printf("You traveled South and have arrived at Location %c.\n", location);
                break;
            case 3:
                location = 'D';
                printf("You traveled East and have arrived at Location %c.\n", location);
                break;
            case 4:
                location = 'E';
                printf("You traveled West and have arrived at Location %c.\n", location);
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        // Check if the user wants to continue
        printf("Do you want to continue playing? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N')
        {
            break;
        }
    }

    printf("Thank you for playing, %s! See you next time.\n", name);
}