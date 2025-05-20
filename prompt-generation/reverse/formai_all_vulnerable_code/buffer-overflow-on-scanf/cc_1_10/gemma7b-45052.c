//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, room, treasure_found = 0;
    char character_name[20];

    // Character creation
    printf("Enter your character's name: ");
    scanf("%s", character_name);

    // Starting room
    room = 1;

    // Main game loop
    while (!treasure_found)
    {
        // Display room options
        printf("\nYou are in room %d. You have 3 options:\n", room);
        printf("1. Go north.\n");
        printf("2. Go east.\n");
        printf("3. Go south.\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice)
        {
            case 1:
                room = 2;
                break;
            case 2:
                room = 3;
                break;
            case 3:
                room = 4;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Check if treasure has been found
        if (room == 4)
        {
            treasure_found = 1;
            printf("Congratulations, %s! You have found the treasure!\n", character_name);
        }
    }

    // Game over
    printf("Thank you for playing, %s. See you next time!\n", character_name);
}