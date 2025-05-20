//FormAI DATASET v1.0 Category: Smart home automation ; Style: intelligent
#include <stdio.h>

// Define some constants to represent the different states of the devices
#define DEVICE_OFF 0
#define DEVICE_ON 1
#define DEVICE_ERROR -1

// Define some functions to control the devices
int turn_on_light() {
    printf("Turning on the light.\n");
    return DEVICE_ON;
}

int turn_off_light() {
    printf("Turning off the light.\n");
    return DEVICE_OFF;
}

int turn_on_fan() {
    printf("Turning on the fan.\n");
    return DEVICE_ON;
}

int turn_off_fan() {
    printf("Turning off the fan.\n");
    return DEVICE_OFF;
}

int main() {
    // Set up some variables to represent the current state of the devices
    int light_state = DEVICE_OFF;
    int fan_state = DEVICE_OFF;

    // Start the main loop of the program
    while (1) {
        // Read input from the user
        printf("Enter a command (l for light, f for fan, q to quit): ");
        char input;
        scanf(" %c", &input);

        // Switch on the user's input to determine what action to take
        switch (input) {
        case 'l':
            if (light_state == DEVICE_OFF) {
                light_state = turn_on_light();
            } else {
                light_state = turn_off_light();
            }
            break;
        case 'f':
            if (fan_state == DEVICE_OFF) {
                fan_state = turn_on_fan();
            } else {
                fan_state = turn_off_fan();
            }
            break;
        case 'q':
            printf("Quitting.\n");
            return 0;
        default:
            printf("Invalid command.\n");
        }
    }
}