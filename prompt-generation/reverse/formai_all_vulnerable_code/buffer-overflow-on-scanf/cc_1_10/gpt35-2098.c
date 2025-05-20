//FormAI DATASET v1.0 Category: Smart home automation ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

// Function to turn on the lights in the living room
void turnOnLivingRoomLights() {
    printf("Turning on the lights in the living room\n");
}

// Function to turn off the lights in the living room
void turnOffLivingRoomLights() {
    printf("Turning off the lights in the living room\n");
}

// Function to turn on the AC in the living room
void turnOnLivingRoomAC() {
    printf("Turning on the AC in the living room\n");
}

// Function to turn off the AC in the living room
void turnOffLivingRoomAC() {
    printf("Turning off the AC in the living room\n");
}

// Function to turn on the TV in the living room
void turnOnLivingRoomTV() {
    printf("Turning on the TV in the living room\n");
}

// Function to turn off the TV in the living room
void turnOffLivingRoomTV() {
    printf("Turning off the TV in the living room\n");
}

int main() {
    // Initially all devices are turned off
    bool livingRoomLights = false;
    bool livingRoomAC = false;
    bool livingRoomTV = false;

    // Variables to store user input
    char livingRoomInput;

    // Ask user what they want to do in the living room
    printf("What do you want to do in the living room? (l)ights, (a)c, (t)v or (q)uit?\n");

    // Keep looping until user wants to quit
    while (true) {
        // Get user input
        scanf(" %c", &livingRoomInput);

        // If user wants to control the lights
        if (livingRoomInput == 'l') {
            // If lights are currently off, turn them on
            if (!livingRoomLights) {
                turnOnLivingRoomLights();
                livingRoomLights = true;
            }
            // If lights are currently on, turn them off
            else {
                turnOffLivingRoomLights();
                livingRoomLights = false;
            }
        }
        // If user wants to control the AC
        else if (livingRoomInput == 'a') {
            // If AC is currently off, turn it on
            if (!livingRoomAC) {
                turnOnLivingRoomAC();
                livingRoomAC = true;
            }
            // If AC is currently on, turn it off
            else {
                turnOffLivingRoomAC();
                livingRoomAC = false;
            }
        }
        // If user wants to control the TV
        else if (livingRoomInput == 't') {
            // If TV is currently off, turn it on
            if (!livingRoomTV) {
                turnOnLivingRoomTV();
                livingRoomTV = true;
            }
            // If TV is currently on, turn it off
            else {
                turnOffLivingRoomTV();
                livingRoomTV = false;
            }
        }
        // If user wants to quit
        else if (livingRoomInput == 'q') {
            printf("Goodbye!\n");
            break;
        }
        // If user inputs invalid option
        else {
            printf("Invalid option. Please choose (l)ights, (a)c, (t)v or (q)uit.\n");
        }
    }

    return 0;
}