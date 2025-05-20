//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    int choice;
    char name[20];

    printf("Welcome to the Quest of Hero, %s!\n", name);

    // Main game loop
    while (1)
    {
        // Display available options
        printf("You are at a crossroads. You can:\n");
        printf("1. Travel north.\n");
        printf("2. Travel south.\n");
        printf("3. Travel east.\n");
        printf("4. Travel west.\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Check the user's choice
        switch (choice)
        {
            case 1:
                printf("You travel north and encounter a dragon.\n");
                break;
            case 2:
                printf("You travel south and find a hidden treasure.\n");
                break;
            case 3:
                printf("You travel east and encounter a troll.\n");
                break;
            case 4:
                printf("You travel west and find a mysterious portal.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Ask the user if they want to continue
        printf("Do you want to continue your journey? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        // If the user wants to continue, start the game loop again
        if (answer == 'Y')
        {
            play_game();
        }
        else
        {
            printf("Thank you for playing, %s!\n", name);
            exit(0);
        }
    }
}

int main()
{
    play_game();

    return 0;
}