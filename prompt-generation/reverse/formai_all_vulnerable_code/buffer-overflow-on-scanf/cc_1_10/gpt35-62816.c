//FormAI DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void turnOnLights();
void turnOffLights();
void turnOnAC();
void turnOffAC();
void lockDoor();
void unlockDoor();

int main() {
    bool isHome = false;
    bool isLightsOn = false;
    bool isACOn = false;
    bool isDoorLocked = true;

    printf("Welcome to Smart Home Automation!\n");

    // Loop until user exits
    while(true) {
        printf("\nWhat would you like to do? (Enter '1' for options)\n");
        int choice;
        scanf("%d", &choice);

        // Options menu
        switch(choice) {
            case 1:
                printf("\nOptions:\n");
                printf("1. Turn Lights On/Off\n");
                printf("2. Turn AC On/Off\n");
                printf("3. Lock/Unlock Door\n");
                printf("4. Exit Program\n");
                break;
            case 2:
                if(isHome) {
                    if(isLightsOn) {
                        turnOffLights();
                        isLightsOn = false;
                    } else {
                        turnOnLights();
                        isLightsOn = true;
                    }
                } else {
                    printf("Sorry, you need to be home to control the lights.\n");
                }
                break;
            case 3:
                if(isHome) {
                    if(isACOn) {
                        turnOffAC();
                        isACOn = false;
                    } else {
                        turnOnAC();
                        isACOn = true;
                    }
                } else {
                    printf("Sorry, you need to be home to control the AC.\n");
                }
                break;
            case 4:
                if(isDoorLocked) {
                    unlockDoor();
                    isDoorLocked = false;
                    isHome = true;
                } else {
                    lockDoor();
                    isDoorLocked = true;
                    isHome = false;
                }
                break;
            case 5:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid input, please try again.\n");
                break;
        }
    }

    return 0;
}

void turnOnLights() {
    printf("Turning on lights...\n");
}

void turnOffLights() {
    printf("Turning off lights...\n");
}

void turnOnAC() {
    printf("Turning on AC...\n");
}

void turnOffAC() {
    printf("Turning off AC...\n");
}

void lockDoor() {
    printf("Locking door...\n");
}

void unlockDoor() {
    printf("Unlocking door...\n");
}