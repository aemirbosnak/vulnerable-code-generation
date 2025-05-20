//FormAI DATASET v1.0 Category: Smart home automation ; Style: realistic
#include <stdio.h>
#include <stdbool.h>

// Define constants to represent the different rooms in the house
#define LIVING_ROOM 1
#define BEDROOM 2
#define KITCHEN 3

// Define constants to represent the different devices in the house
#define LIGHTS 1
#define THERMOSTAT 2
#define LOCKS 3

// Define functions for each automation task
bool lightsOn(int room) {
    // Code to turn lights on
    printf("Lights turned on in room %d.\n", room);
    return true;
}

bool lightsOff(int room) {
    // Code to turn lights off
    printf("Lights turned off in room %d.\n", room);
    return true;
}

bool setTemperature(int room, int degree) {
    // Code to set temperature
    printf("Temperature set to %d degrees in room %d.\n", degree, room);
    return true;
}

bool lockDoors(bool locked) {
    // Code to lock/unlock doors
    if (locked) {
        printf("Doors locked.\n");
    } else {
        printf("Doors unlocked.\n");
    }
    return true;
}

int main() {
    // Declare variables to hold user input
    int roomSelection, deviceSelection, actionSelection;

    // Prompt user to select room
    printf("Select a room:\n");
    printf("1. Living Room\n");
    printf("2. Bedroom\n");
    printf("3. Kitchen\n");
    scanf("%d", &roomSelection);

    // Prompt user to select device
    printf("Select a device:\n");
    printf("1. Lights\n");
    printf("2. Thermostat\n");
    printf("3. Locks\n");
    scanf("%d", &deviceSelection);

    // Prompt user to select action
    printf("Select an action:\n");
    printf("1. Turn on\n");
    printf("2. Turn off\n");
    if (deviceSelection == THERMOSTAT) {
        printf("3. Set temperature\n");
    } else if (deviceSelection == LOCKS) {
        printf("3. Lock\n");
        printf("4. Unlock\n");
    }
    scanf("%d", &actionSelection);

    // Perform selected action
    if (deviceSelection == LIGHTS) {
        if (actionSelection == 1) {
            lightsOn(roomSelection);
        } else if (actionSelection == 2) {
            lightsOff(roomSelection);
        }
    } else if (deviceSelection == THERMOSTAT) {
        if (actionSelection == 3) {
            int degree;
            printf("Enter the temperature in Celsius:\n");
            scanf("%d", &degree);
            setTemperature(roomSelection, degree);
        } else {
            printf("Invalid selection.\n");
        }
    } else if (deviceSelection == LOCKS) {
        if (actionSelection == 3) {
            lockDoors(true);
        } else if (actionSelection == 4) {
            lockDoors(false);
        } else {
            printf("Invalid selection.\n");
        }
    } else {
        printf("Invalid selection.\n");
    }

    return 0;
}