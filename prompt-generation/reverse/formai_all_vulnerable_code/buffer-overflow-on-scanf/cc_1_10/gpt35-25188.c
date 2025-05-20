//FormAI DATASET v1.0 Category: Smart home automation ; Style: safe
#include <stdio.h>
#include <stdbool.h>

// Function to turn the lights on or off
void turnLights(bool on) {
    if(on) {
        printf("Lights turned on.\n");
    } else {
        printf("Lights turned off.\n");
    }
}

// Function to adjust the thermostat
void adjustTemperature(int temperature) {
    printf("Temperature adjusted to %d degrees.\n", temperature);
}

// Function to check if the door is locked or unlocked
bool isDoorLocked() {
    return true;
}

// Function to lock or unlock the door
void toggleDoor(bool lock) {
    if(lock) {
        printf("Door locked.\n");
    } else {
        printf("Door unlocked.\n");
    }
}

int main() {
    bool lightsOn = false;
    int temperature = 72;
    bool doorLocked = true;
    
    // Initial state
    printf("Welcome to your smart home!\n");
    printf("Lights are off.\n");
    printf("Temperature is set to %d degrees.\n", temperature); 
    printf("Door is locked.\n\n");

    // User input
    char input;
    while(1) {
        printf("What would you like to do? (L for lights, T for temperature, D for door, Q to quit)\n");
        scanf(" %c", &input); // Clear input buffer

        switch(input) {
            case 'L':
                printf("Current lights state: %s\n", lightsOn ? "on" : "off");
                printf("Turn lights on or off? (Y or N)\n");
                scanf(" %c", &input); // Clear input buffer

                switch(input) {
                    case 'Y':
                        turnLights(true);
                        lightsOn = true;
                        break;
                    case 'N':
                        turnLights(false);
                        lightsOn = false;
                        break;
                    default:
                        printf("Invalid input.\n");
                }

                break;
            case 'T':
                printf("Current temperature: %d degrees.\n", temperature);
                printf("Set temperature to what? (Enter an integer)\n");
                scanf("%d", &temperature); // Clear input buffer

                adjustTemperature(temperature);
                break;
            case 'D':
                printf("Current door state: %s\n", doorLocked ? "locked" : "unlocked");
                printf("Lock or unlock the door? (Y or N)\n");
                scanf(" %c", &input); // Clear input buffer

                switch(input) {
                    case 'Y':
                        toggleDoor(true);
                        doorLocked = true;
                        break;
                    case 'N':
                        toggleDoor(false);
                        doorLocked = false;
                        break;
                    default:
                        printf("Invalid input.\n");
                }

                break;
            case 'Q':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid input.\n");
        }

        printf("\n"); // Add whitespace for readability
    }
}