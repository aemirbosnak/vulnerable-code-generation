//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>

// Define constants for devices
#define LIGHTS 1
#define TV 2
#define AC 3
#define LOCK 4

// Define global variables for device states
bool lightsOn = false;
bool tvOn = false;
bool acOn = false;
bool locked = true;

// Function to toggle device states
void toggleDeviceState(int deviceId) {
    switch(deviceId) {
        case LIGHTS:
            lightsOn = !lightsOn;
            printf("Lights are now %s\n", lightsOn ? "on" : "off");
            break;
        case TV:
            tvOn = !tvOn;
            printf("TV is now %s\n", tvOn ? "on" : "off");
            break;
        case AC:
            acOn = !acOn;
            printf("AC is now %s\n", acOn ? "on" : "off");
            break;
        case LOCK:
            locked = !locked;
            printf("Door is now %s\n", locked ? "locked" : "unlocked");
            break;
        default:
            printf("Device id not recognized\n");
    }
}

int main() {
    printf("Welcome to the smart home automation system!\n");
    printf("Type in the device id to toggle its state:\n");
    printf("1 - Lights\n");
    printf("2 - TV\n");
    printf("3 - AC\n");
    printf("4 - Door Lock\n");

    int deviceId;
    while (true) {
        scanf("%d", &deviceId);
        toggleDeviceState(deviceId);
    }

    return 0;
}