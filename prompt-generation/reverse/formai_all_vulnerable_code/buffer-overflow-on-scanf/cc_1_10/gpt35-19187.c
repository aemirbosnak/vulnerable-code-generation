//FormAI DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for various devices connected to the smart home system
#define LIGHTS 1
#define THERMOSTAT 2
#define SECURITY_SYSTEM 3
#define SPRINKLER_SYSTEM 4

// Define variables to store the status of different devices
bool lightsOn = false;
int temperature = 75;
bool securitySystemArmed = true;
bool sprinklerSystemOn = false;

// Function to turn lights on/off
void toggleLights() {
    if (lightsOn) {
        printf("Turning lights off.\n");
        lightsOn = false;
    } else {
        printf("Turning lights on.\n");
        lightsOn = true;
    }
}

// Function to adjust thermostat temperature
void adjustThermostat(int newTemperature) {
    printf("Adjusting thermostat to %d degrees.\n", newTemperature);
    temperature = newTemperature;
}

// Function to arm/disarm security system
void toggleSecuritySystem() {
    if (securitySystemArmed) {
        printf("Disarming security system.\n");
        securitySystemArmed = false;
    } else {
        printf("Arming security system.\n");
        securitySystemArmed = true;
    }
}

// Function to turn sprinkler system on/off
void toggleSprinklerSystem() {
    if (sprinklerSystemOn) {
        printf("Turning sprinkler system off.\n");
        sprinklerSystemOn = false;
    } else {
        printf("Turning sprinkler system on.\n");
        sprinklerSystemOn = true;
    }
}

int main() {
    int userInput;
    bool exitProgram = false;

    printf("Welcome to Smart Home Automation System!\n");

    // Loop until user decides to exit program
    while (!exitProgram) {
        printf("\nPlease choose an option:\n");
        printf("1. Toggle Lights\n");
        printf("2. Adjust Thermostat\n");
        printf("3. Toggle Security System\n");
        printf("4. Toggle Sprinkler System\n");
        printf("5. Exit Program\n");
        scanf("%d", &userInput);

        switch (userInput) {
            case LIGHTS:
                toggleLights();
                break;
            case THERMOSTAT:
                printf("Enter new temperature:\n");
                scanf("%d", &userInput);
                adjustThermostat(userInput);
                break;
            case SECURITY_SYSTEM:
                toggleSecuritySystem();
                break;
            case SPRINKLER_SYSTEM:
                toggleSprinklerSystem();
                break;
            default:
                printf("Invalid input, please try again.\n");
        }

        // Check if user entered option to exit program
        if (userInput == 5) {
            exitProgram = true;
            printf("Goodbye!\n");
        }
    }

    return 0;
}