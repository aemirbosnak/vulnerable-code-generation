//FormAI DATASET v1.0 Category: Smart home light control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>

// Define constants for light states
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Define function to control lights based on input state
void controlLight(bool lightState) {
    if (lightState == LIGHT_OFF) {
        printf("Turning off the lights.\n");
        // Code to turn off the lights
    } else if (lightState == LIGHT_ON) {
        printf("Turning on the lights.\n");
        // Code to turn on the lights
    } else {
        printf("Invalid light state.\n");
    }
}

int main() {
    // Assume we have some initial state for the light
    bool lightState = LIGHT_OFF;

    // Prompt the user for input and control the light accordingly
    char choice;
    do {
        printf("Current light state: %s\n", lightState ? "on" : "off");
        printf("Enter 'on' or 'off' to control the light, or 'q' to quit.\n");
        scanf("%c", &choice);

        switch (choice) {
            case 'on':
                lightState = LIGHT_ON;
                controlLight(lightState);
                break;
            case 'off':
                lightState = LIGHT_OFF;
                controlLight(lightState);
                break;
            case 'q':
                printf("Quitting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter 'on', 'off', or 'q'.\n");
                break;
        }
    } while (choice != 'q');

    return 0;
}