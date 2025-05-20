//FormAI DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialize device status
    int lightStatus = 0;    // off
    int acStatus = 0;       // off
    int lockStatus = 1;     // locked

    // Welcome message
    printf("Welcome to Smart Home Automation System!\n\n");

    while(1)
    {
        // Display current status
        printf("Current status:\n");
        printf("Light: %s\n", lightStatus ? "on" : "off");
        printf("AC: %s\n", acStatus ? "on" : "off");
        printf("Lock: %s\n", lockStatus ? "locked" : "unlocked");

        // User prompt
        printf("\nWhat would you like to do?\n");
        printf("1. Turn light on/off\n");
        printf("2. Turn AC on/off\n");
        printf("3. Lock/unlock door\n");
        printf("4. Exit\n");
        int option;
        scanf("%d", &option);

        // Process user input
        switch(option)
        {
            case 1:
                lightStatus = !lightStatus;   // toggle light status
                printf("Light turned %s.\n", lightStatus ? "on" : "off");
                break;
            case 2:
                acStatus = !acStatus;   // toggle AC status
                printf("AC turned %s.\n", acStatus ? "on" : "off");
                break;
            case 3:
                if(lockStatus)
                {
                    lockStatus = 0; // unlock door
                    printf("Door unlocked.\n");
                }
                else
                {
                    lockStatus = 1; // lock door
                    printf("Door locked.\n");
                }
                break;
            case 4:
                printf("Exiting Smart Home Automation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}