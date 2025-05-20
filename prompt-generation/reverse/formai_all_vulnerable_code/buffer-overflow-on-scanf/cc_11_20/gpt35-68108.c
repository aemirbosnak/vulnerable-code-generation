//FormAI DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Smart home devices
    int lights = 0;
    int thermostat = 0;
    int security_system = 0;

    // User input variables
    char input[50];
    char device[20];

    // Start of program
    printf("Welcome to your smart home! Press Ctrl+C to exit at any time.\n");

    while (1) {
        // Prompt user for input
        printf("What device do you want to control (lights, thermostat, or security system)?\n");
        scanf("%s", device);

        // Determine which device the user wants to control
        if (strcmp(device, "lights") == 0) {
            printf("The lights are currently turned %s. Do you want to turn them on or off? (on/off)\n", lights ? "on" : "off");
            scanf("%s", input);

            if (strcmp(input, "on") == 0) {
                lights = 1;
                printf("Turning lights on.\n");
            } else if (strcmp(input, "off") == 0) {
                lights = 0;
                printf("Turning lights off.\n");
            } else {
                printf("Invalid input. Please try again.\n");
            }
        } else if (strcmp(device, "thermostat") == 0) {
            printf("The thermostat is currently set to %d degrees Celsius. What temperature do you want to set it to?\n", thermostat);
            scanf("%d", &thermostat);

            printf("Setting thermostat to %d degrees Celsius.\n", thermostat);
        } else if (strcmp(device, "security system") == 0) {
            printf("The security system is currently %s. Do you want to arm or disarm it? (arm/disarm)\n", security_system ? "armed" : "disarmed");
            scanf("%s", input);

            if (strcmp(input, "arm") == 0) {
                security_system = 1;
                printf("Arming security system.\n");
            } else if (strcmp(input, "disarm") == 0) {
                security_system = 0;
                printf("Disarming security system.\n");
            } else {
                printf("Invalid input. Please try again.\n");
            }
        } else {
            printf("Invalid device. Please try again.\n");
        }
    }

    return 0;
}