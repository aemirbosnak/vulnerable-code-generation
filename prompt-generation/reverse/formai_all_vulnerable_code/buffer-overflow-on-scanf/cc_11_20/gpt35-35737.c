//FormAI DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Welcome to your smart home!\n");

    // initialize all devices to off
    bool lights = false;
    bool thermostat = false;
    bool security = false;

    char input;
    while (true) {
        printf("What would you like to do? (l for Lights, t for Thermostat, s for Security)\n");
        scanf(" %c", &input);

        switch(input) {
            case 'l':
                if (lights == false) {
                    printf("Turning lights on...\n");
                    lights = true;
                } else {
                    printf("Turning lights off...\n");
                    lights = false;
                }
                break;

            case 't':
                if (thermostat == false) {
                    printf("Setting thermostat to 70 degrees...\n");
                    thermostat = true;
                } else {
                    printf("Setting thermostat to 75 degrees...\n");
                    thermostat = false;
                }
                break;

            case 's':
                if (security == false) {
                    printf("Arming security system...\n");
                    security = true;
                } else {
                    printf("Disarming security system...\n");
                    security = false;
                }
                break;

            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        // print out the current status of each device
        printf("Lights: %s\n", lights ? "On" : "Off");
        printf("Thermostat: %s\n", thermostat ? "70 degrees" : "75 degrees");
        printf("Security: %s\n\n", security ? "Armed" : "Disarmed");
    }

    return 0;
}