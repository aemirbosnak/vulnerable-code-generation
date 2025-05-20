//FormAI DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Welcome to the Smart Home Automation Program!\n");
    printf("Initializing all systems...\n");
    
    // Create variables for all devices
    bool lightsOn = false;
    bool tvOn = false;
    int temperature = 72;
    int fanSpeed = 0;

    printf("\n");

    // Start user interaction loop
    while (true)
    {
        printf("What would you like to do?\n");
        printf("1. Turn lights on/off\n");
        printf("2. Turn TV on/off\n");
        printf("3. Adjust temperature\n");
        printf("4. Adjust fan speed\n");
        printf("5. Exit program\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (lightsOn)
                {
                    printf("Turning lights off...\n");
                    lightsOn = false;
                }
                else
                {
                    printf("Turning lights on...\n");
                    lightsOn = true;
                }
                break;

            case 2:
                if (tvOn)
                {
                    printf("Turning TV off...\n");
                    tvOn = false;
                }
                else
                {
                    printf("Turning TV on...\n");
                    tvOn = true;
                }
                break;

            case 3:
                printf("Enter desired temperature: ");
                scanf("%d", &temperature);
                printf("Setting temperature to %d degrees...\n", temperature);
                break;

            case 4:
                printf("Enter desired fan speed (0-10): ");
                scanf("%d", &fanSpeed);
                if (fanSpeed < 0)
                {
                    printf("Invalid speed! Setting to 0...\n");
                    fanSpeed = 0;
                }
                else if (fanSpeed > 10)
                {
                    printf("Invalid speed! Setting to 10...\n");
                    fanSpeed = 10;
                }
                printf("Setting fan speed to %d...\n", fanSpeed);
                break;

            case 5:
                printf("Leaving the Smart Home Automation Program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please choose 1-5.\n");
                break;
        }

        printf("\n");
    }
}