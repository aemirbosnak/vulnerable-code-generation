//FormAI DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declaration
void turnOnLights();
void turnOffLights();
void adjustTemperature();
void unlockDoor();
void lockDoor();

// Global variables
bool isLightsOn = false;
int temperature = 25;
bool isDoorLocked = true;

int main() {
    // Welcome message
    printf("Welcome to the Smart Home Automation System\n");

    // Input command from the user
    while (true) {
        printf("Please enter a command (1 = turn on lights, 2 = turn off lights, 3 = adjust temperature, 4 = unlock door, 5 = lock door): ");
        int command;
        scanf("%d", &command);

        // Call the appropriate function based on the user's command
        switch (command) {
            case 1:
                turnOnLights(); break;
            case 2:
                turnOffLights(); break;
            case 3:
                adjustTemperature(); break;
            case 4:
                unlockDoor(); break;
            case 5:
                lockDoor(); break;
            default:
                printf("Invalid command\n"); break;
        }

        // Check if the user wants to exit the program
        printf("Do you want to exit? (1 = yes, 0 = no): ");
        int shouldExit;
        scanf("%d", &shouldExit);
        if (shouldExit) {
            printf("Goodbye!\n");
            break;
        }
    }

    return 0;
}

// Function definitions
void turnOnLights() {
    if (!isLightsOn) {
        printf("Turning on lights...\n");
        isLightsOn = true;
    } else {
        printf("Lights are already on\n");
    }
}

void turnOffLights() {
    if (isLightsOn) {
        printf("Turning off lights...\n");
        isLightsOn = false;
    } else {
        printf("Lights are already off\n");
    }
}

void adjustTemperature() {
    printf("Current temperature: %d\n", temperature);
    printf("Enter the new temperature: ");
    scanf("%d", &temperature);
    printf("Adjusting temperature to %d degrees...\n", temperature);
}

void unlockDoor() {
    if (isDoorLocked) {
        printf("Unlocking door...\n");
        isDoorLocked = false;
    } else {
        printf("Door is already unlocked\n");
    }
}

void lockDoor() {
    if (!isDoorLocked) {
        printf("Locking door...\n");
        isDoorLocked = true;
    } else {
        printf("Door is already locked\n");
    }
}