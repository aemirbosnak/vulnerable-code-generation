//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: shape shifting
// Welcome to the Smart Home Revolution

// The Automated Butler
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare the smart home's components
typedef enum {
    LIGHT_ON,
    LIGHT_OFF
} LightState;

typedef enum {
    DOOR_OPEN,
    DOOR_CLOSED
} DoorState;

typedef enum {
    MOTION_DETECTED,
    MOTION_NOT_DETECTED
} MotionState;

// Initialize the smart home's components
LightState lightState = LIGHT_OFF;
DoorState doorState = DOOR_CLOSED;
MotionState motionState = MOTION_NOT_DETECTED;

// Define the smart home's behavior
void updateLightState(LightState newState) {
    lightState = newState;
    printf("Light state: %s\n", lightState == LIGHT_ON ? "ON" : "OFF");
}

void updateDoorState(DoorState newState) {
    doorState = newState;
    printf("Door state: %s\n", doorState == DOOR_OPEN ? "OPEN" : "CLOSED");
}

void updateMotionState(MotionState newState) {
    motionState = newState;
    printf("Motion state: %s\n", motionState == MOTION_DETECTED ? "DETECTED" : "NOT DETECTED");
}

// Main control loop
int main() {
    // Initialize the smart home system
    updateLightState(LIGHT_OFF);
    updateDoorState(DOOR_CLOSED);
    updateMotionState(MOTION_NOT_DETECTED);

    // Event loop
    while (true) {
        // Check for events
        int event;
        scanf("%d", &event);

        switch (event) {
            case 1:  // Light on
                updateLightState(LIGHT_ON);
                break;
            case 2:  // Light off
                updateLightState(LIGHT_OFF);
                break;
            case 3:  // Door open
                updateDoorState(DOOR_OPEN);
                break;
            case 4:  // Door closed
                updateDoorState(DOOR_CLOSED);
                break;
            case 5:  // Motion detected
                updateMotionState(MOTION_DETECTED);
                break;
            case 6:  // Motion not detected
                updateMotionState(MOTION_NOT_DETECTED);
                break;
            default:
                break;
        }
    }

    return 0;
}