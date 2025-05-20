//FormAI DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>

// Function to turn on/off the lights in the living room
void livingRoomLights(bool turnOn) {
    if(turnOn) {
        printf("Turning on the living room lights.\n");
    } else {
        printf("Turning off the living room lights.\n");
    }
}

// Function to adjust the thermostat temperature
void adjustTemperature(int temp) {
    printf("Adjusting thermostat temperature to %d.\n", temp);
}

// Function to close/open the garage door
void garageDoor(bool close) {
    if(close) {
        printf("Closing the garage door.\n");
    } else {
        printf("Opening the garage door.\n");
    }
}

// Main function
int main() {

    // Set initial state of devices
    bool livingRoomLightsOn = false;
    int temperature = 68;
    bool garageDoorClosed = true;

    // Loop to receive input and adjust devices accordingly
    while(true) {
        // Menu to display options
        printf("Select an option:\n");
        printf("1. Turn living room lights on/off.\n");
        printf("2. Adjust thermostat temperature.\n");
        printf("3. Close/open garage door.\n");
        printf("4. Quit.\n");

        // Receive input
        int choice;
        scanf("%d", &choice);

        // Determine which option was selected
        switch(choice) {
            case 1:
                // Toggle living room lights
                livingRoomLightsOn = !livingRoomLightsOn;
                livingRoomLights(livingRoomLightsOn);
                break;
            case 2:
                // Adjust temperature
                printf("Enter the desired temperature: ");
                scanf("%d", &temperature);
                adjustTemperature(temperature);
                break;
            case 3:
                // Toggle garage door
                garageDoorClosed = !garageDoorClosed;
                garageDoor(garageDoorClosed);
                break;
            case 4:
                // Quit program
                printf("Goodbye!\n");
                return 0;
            default:
                // Invalid option
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}