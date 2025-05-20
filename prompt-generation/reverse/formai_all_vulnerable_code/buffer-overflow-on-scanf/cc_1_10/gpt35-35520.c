//FormAI DATASET v1.0 Category: Smart home automation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    // retro style smart home automation
    printf("Welcome to Retro Home Automation!\n");

    // Initializing variables
    bool lights = false;
    bool temperature = false;
    bool music = false;
    int choice;

    // Looping until user decides to exit the program
    while (true)
    {
        // Displaying the available options to the user
        printf("1. Turn on/off lights\n");
        printf("2. Set temperature\n");
        printf("3. Play/pause music\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Checking user's input and performing the needed actions
        switch (choice)
        {
            case 1:
                if (lights == false)
                {
                    printf("Turning on the lights.\n");
                    lights = true;
                }
                else
                {
                    printf("Turning off the lights.\n");
                    lights = false;
                }
                break;

            case 2:
                if (temperature == false)
                {
                    printf("Setting the temperature to warm.\n");
                    temperature = true;
                }
                else
                {
                    printf("Setting the temperature to cool.\n");
                    temperature = false;
                }
                break;

            case 3:
                if (music == false)
                {
                    printf("Playing music.\n");
                    music = true;
                }
                else
                {
                    printf("Pausing music.\n");
                    music = false;
                }
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid input, please try again.\n");
                break;
        }
    }

    return 0;
}