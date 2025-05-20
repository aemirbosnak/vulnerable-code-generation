//FormAI DATASET v1.0 Category: Smart home automation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int lights = 0;
int door_lock = 0;
int thermostat = 70;

// Declare functions
void toggle_lights();
void toggle_door_lock();
void adjust_thermostat(int);

int main() {
    printf("Welcome to the Smart Home Automation System!\n");
    
    // Display initial status
    printf("Lights: %s\n", (lights == 1) ? "On" : "Off");
    printf("Door Lock: %s\n", (door_lock == 1) ? "Locked" : "Unlocked");
    printf("Thermostat: %d degrees\n\n", thermostat);
    
    // User interaction loop
    char option;
    do {
        printf("Enter 'L' to toggle Lights.\nEnter 'D' to toggle Door Lock.\nEnter 'T' to increase the Thermostat.\nEnter 'C' to decrease the Thermostat.\nEnter 'Q' to Quit.\n");
        scanf(" %c", &option);
        switch (option) {
            case 'L':
                toggle_lights();
                break;
            case 'D':
                toggle_door_lock();
                break;
            case 'T':
                adjust_thermostat(1);
                break;
            case 'C':
                adjust_thermostat(-1);
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
        // Display updated status
        printf("Lights: %s\n", (lights == 1) ? "On" : "Off");
        printf("Door Lock: %s\n", (door_lock == 1) ? "Locked" : "Unlocked");
        printf("Thermostat: %d degrees\n\n", thermostat);
    } while (option != 'Q');
    
    return 0;
}

void toggle_lights() {
    if (lights == 0) {
        printf("Turning lights on.\n");
        lights = 1;
    } else {
        printf("Turning lights off.\n");
        lights = 0;
    }
}

void toggle_door_lock() {
    if (door_lock == 0) {
        printf("Locking the door.\n");
        door_lock = 1;
    } else {
        printf("Unlocking the door.\n");
        door_lock = 0;
    }
}

void adjust_thermostat(int increment) {
    thermostat += increment;
    printf("Adjusting thermostat to %d degrees.\n", thermostat);
}