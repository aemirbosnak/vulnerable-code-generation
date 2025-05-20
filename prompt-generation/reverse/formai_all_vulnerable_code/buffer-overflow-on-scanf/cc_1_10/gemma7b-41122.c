//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice;
    char name[20];

    // Initialize the haunted house environment
    system("clear");
    printf("You wake up in a dimly lit, ancient Victorian mansion.\n");
    printf("The only sound is your breathing and the ticking of a grandfather clock.\n");

    // Present the options
    printf("What do you want to do?\n");
    printf("1. Explore the mansion\n");
    printf("2. Call for help\n");
    printf("3. Leave the mansion\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Based on the user's choice, take them through the haunted house
    switch (choice)
    {
        case 1:
            printf("You cautiously explore the mansion, room by room. The atmosphere is thick with the scent of decay and despair.\n");
            break;
        case 2:
            printf("You frantically call for help, but there is no answer. You feel alone and helpless.\n");
            break;
        case 3:
            printf("You flee the mansion, running for your life. You hear footsteps behind you, but you manage to escape.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Ask the user if they want to play again
    printf("Do you want to play again? (Y/N) ");

    // Get the user's answer
    scanf(" %c", name);

    // If the user wants to play again, start the game over
    if (name[0] == 'Y')
    {
        main();
    }

    // Otherwise, thank the user for playing and exit the program
    else
    {
        printf("Thank you for playing. Goodbye.\n");
    }
}