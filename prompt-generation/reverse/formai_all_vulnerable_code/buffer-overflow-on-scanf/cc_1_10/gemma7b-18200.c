//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int choice;

    // Create a simple text-based adventure game in a cozy cottage.

    // Introduction
    printf("Welcome to the cozy cottage of Mr. Bartholomew.\n");
    printf("You wake up with a start, hearing a rustling sound outside the window.\n");

    // Gather the player's name
    printf("What is your name? ");
    scanf("%s", name);

    // Present options
    printf("You hear three sounds: a creak on the floor, a groan from the attic, and a tapping at the window.\n");
    printf("Please choose an option below:\n");
    printf("1. Investigate the creak on the floor.\n");
    printf("2. Listen to the groan from the attic.\n");
    printf("3. Focus on the tapping at the window.\n");

    // Get the player's choice
    scanf("%d", &choice);

    // Branching based on the player's choice
    switch (choice)
    {
        case 1:
            // Investigate the creak on the floor
            printf("You cautiously inspect the area around the creak, but find nothing suspicious.\n");
            break;
        case 2:
            // Listen to the groan from the attic
            printf("You hear a faint groan coming from the attic. It sounds like someone is moving around upstairs.\n");
            break;
        case 3:
            // Focus on the tapping at the window
            printf("You hear the tapping at the window again. It sounds like someone is trying to get your attention.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Conclusion
    printf("Thank you for playing, %s. Please come again soon.\n", name);

    return 0;
}