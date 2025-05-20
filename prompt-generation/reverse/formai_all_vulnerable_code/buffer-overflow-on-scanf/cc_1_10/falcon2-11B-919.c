//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define constants for the fan and light states
const int FAN_ON = 1;
const int FAN_OFF = 0;
const int LIGHT_ON = 1;
const int LIGHT_OFF = 0;

// Define function prototypes
void fan_control(int state);
void light_control(int state);

// Main function
int main() {
    // Initialize fan and light states to off
    int fan_state = FAN_OFF;
    int light_state = LIGHT_OFF;

    // Loop until user wants to quit
    while (1) {
        // Display menu options
        printf("\n1. Turn fan on\n2. Turn fan off\n3. Turn light on\n4. Turn light off\n5. Quit\n");
        int choice;
        scanf("%d", &choice);

        // User wants to quit
        if (choice == 5) {
            break;
        }

        // Control fan based on choice
        switch (choice) {
            case 1:
                fan_control(FAN_ON);
                break;
            case 2:
                fan_control(FAN_OFF);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        // Control light based on choice
        switch (choice) {
            case 3:
                light_control(LIGHT_ON);
                break;
            case 4:
                light_control(LIGHT_OFF);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    // Free memory
    free(fan_state);
    free(light_state);

    return 0;
}

// Function to control fan state
void fan_control(int state) {
    if (state == FAN_ON) {
        printf("Fan turned on\n");
    } else if (state == FAN_OFF) {
        printf("Fan turned off\n");
    } else {
        printf("Invalid state\n");
    }
}

// Function to control light state
void light_control(int state) {
    if (state == LIGHT_ON) {
        printf("Light turned on\n");
    } else if (state == LIGHT_OFF) {
        printf("Light turned off\n");
    } else {
        printf("Invalid state\n");
    }
}