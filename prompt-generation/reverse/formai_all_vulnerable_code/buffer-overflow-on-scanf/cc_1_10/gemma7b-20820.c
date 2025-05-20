//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    char name[20];
    int room_num;
    int spooky_meter = 0;

    // Welcome the visitor and ask for their name
    printf("Welcome to The Haunted House of Thornfield Hall. Please enter your name: ");
    scanf("%s", name);

    // Get the visitor's room number
    printf("Please enter the room number you will be staying in: ");
    scanf("%d", &room_num);

    // Generate a spooky meter reading
    spooky_meter = rand() % 10;

    // Check if the room is haunted
    if (spooky_meter >= 5)
    {
        // The room is haunted
        printf("The room you have chosen is haunted. Prepare for a spooky experience...\n");
    }
    else
    {
        // The room is not haunted
        printf("The room you have chosen is not haunted. You are safe...\n");
    }

    // Ask the visitor if they want to stay in the room
    printf("Do you want to stay in this room? (Y/N): ");
    scanf("%c", &choice);

    // If the visitor chooses to stay, the program will simulate a haunted house experience
    if (choice == 'Y')
    {
        // Play spooky sounds and music
        system("start spooky_sounds.bat");

        // Flash the lights
        system("start flash_lights.bat");

        // Simulate ghostly voices and footsteps
        system("start ghostly_voices.bat");

        // Ask the visitor if they want to leave
        printf("Do you want to leave the haunted house? (Y/N): ");
        scanf("%c", &choice);

        // If the visitor chooses to leave, the program will end
        if (choice == 'Y')
        {
            printf("Thank you for visiting The Haunted House of Thornfield Hall. We hope you enjoyed your stay.\n");
            exit(0);
        }
    }

    return 0;
}