//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int choice;
    char location;
    int room_num;

    // Create a simple text-based adventure game
    printf("Welcome, traveler, to the enchanting realm of Serene Falls.\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    // Initialize the room number to 1
    room_num = 1;

    // Main loop for the adventure
    while (room_num != 5)
    {
        // Display the available options
        printf("You are in room %d. What would you like to do?\n", room_num);
        printf("1. Explore the garden.\n");
        printf("2. Meet the residents.\n");
        printf("3. Search for clues.\n");
        printf("Please make your choice: ");

        // Get the user's choice
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice)
        {
            case 1:
                // Go to the garden
                room_num = 2;
                break;
            case 2:
                // Meet the residents
                room_num = 3;
                break;
            case 3:
                // Search for clues
                room_num = 4;
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    // End of the adventure
    printf("Congratulations, %s, you have completed your journey.\n", name);
    return 0;
}