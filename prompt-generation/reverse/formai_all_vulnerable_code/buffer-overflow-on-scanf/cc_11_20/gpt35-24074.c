//FormAI DATASET v1.0 Category: Smart home automation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

    // Initialize the smart home devices
    bool lights_on = false;
    bool thermostat_on = false;

    // Welcome the user
    printf("Welcome to Smart Home Automation!\n");

    // Prompt the user for a command
    while (true) {
        printf("What would you like to do?\n");
        printf("1. Turn on the lights\n");
        printf("2. Turn off the lights\n");
        printf("3. Turn on the thermostat\n");
        printf("4. Turn off the thermostat\n");
        printf("5. Exit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Perform the appropriate action based on the user's choice
        switch (choice) {
            case 1:
                if (!lights_on) {
                    printf("Turning on the lights!\n");
                    lights_on = true;
                } else {
                    printf("The lights are already on!\n");
                }
                break;
            case 2:
                if (lights_on) {
                    printf("Turning off the lights!\n");
                    lights_on = false;
                } else {
                    printf("The lights are already off!\n");
                }
                break;
            case 3:
                if (!thermostat_on) {
                    printf("Turning on the thermostat!\n");
                    thermostat_on = true;
                } else {
                    printf("The thermostat is already on!\n");
                }
                break;
            case 4:
                if (thermostat_on) {
                    printf("Turning off the thermostat!\n");
                    thermostat_on = false;
                } else {
                    printf("The thermostat is already off!\n");
                }
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}