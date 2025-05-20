//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIGHT_ON  1
#define LIGHT_OFF 0

int main()
{
    // Create a smart home light control system.
    // The system will have the following features:
    // - Turn on the light.
    // - Turn off the light.
    // - Get the light status.

    // Define the light status variable.
    int light_status = LIGHT_OFF;

    // Create a menu to allow the user to select an option.
    while (1)
    {
        printf("Smart Home Light Control System\n");
        printf("==============================\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Get the light status\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        // Get the user's choice.
        int choice;
        scanf("%d", &choice);

        // Perform the selected action.
        switch (choice)
        {
            case 1:
                // Turn on the light.
                light_status = LIGHT_ON;
                printf("The light is now on.\n");
                break;

            case 2:
                // Turn off the light.
                light_status = LIGHT_OFF;
                printf("The light is now off.\n");
                break;

            case 3:
                // Get the light status.
                printf("The light is currently %s.\n", light_status == LIGHT_ON ? "on" : "off");
                break;

            case 4:
                // Quit the program.
                exit(0);

            default:
                // Invalid choice.
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }

        // Wait for the user to press any key to continue.
        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}