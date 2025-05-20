//FormAI DATASET v1.0 Category: Smart home automation ; Style: genious
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define light status constants
#define LIGHT_OFF false
#define LIGHT_ON true

// Define function prototypes
void turnOnLight();
void turnOffLight();
void toggleLight(bool *lightStatusPtr);
void printLightStatus(bool lightStatus);

int main() {
    // Initialize light status to off
    bool lightStatus = LIGHT_OFF;

    while (true) {
        // Prompt user for choice
        printf("Enter 1 to turn on the light\n");
        printf("Enter 2 to turn off the light\n");
        printf("Enter 3 to toggle the light\n");
        printf("Enter 4 to exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                turnOnLight();
                lightStatus = LIGHT_ON;
                break;
            case 2:
                turnOffLight();
                lightStatus = LIGHT_OFF;
                break;
            case 3:
                toggleLight(&lightStatus);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        // Print new light status
        printLightStatus(lightStatus);
    }

    return 0;
}

// Function to turn on light
void turnOnLight() {
    printf("Turning on the light...\n");
}

// Function to turn off light
void turnOffLight() {
    printf("Turning off the light...\n");
}

// Function to toggle light status
void toggleLight(bool *lightStatusPtr) {
    if (*lightStatusPtr == LIGHT_OFF) {
        turnOnLight();
        *lightStatusPtr = LIGHT_ON;
    } else {
        turnOffLight();
        *lightStatusPtr = LIGHT_OFF;
    }
}

// Function to print light status
void printLightStatus(bool lightStatus) {
    if (lightStatus == LIGHT_ON) {
        printf("The light is on.\n");
    } else {
        printf("The light is off.\n");
    }
}