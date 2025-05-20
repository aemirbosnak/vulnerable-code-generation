//FormAI DATASET v1.0 Category: Smart home automation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Initialize Devices
bool lampOn = false;
bool acOn = false;
bool tvOn = false;

// Function to turn on/off a device
void toggleDevice(bool *device, char deviceName[]) {
    if(*device) {
        *device = false;
        printf("%s has been turned off.\n", deviceName);
    } else {
        *device = true;
        printf("%s has been turned on.\n", deviceName);
    }
}

int main() {
    char userInput;
    bool prevLampOnState = lampOn;
    bool prevAcOnState = acOn;
    bool prevTvOnState = tvOn;
    
    printf("Welcome to Smart Home Automation!\n");

    // Main Loop
    while(true) {
        printf("\nSelect a device to toggle:\n");
        printf("1 - Lamp\n");
        printf("2 - AC\n");
        printf("3 - TV\n");
        printf("q - Quit program\n");
        
        // Check for changes in device states
        if(lampOn != prevLampOnState) {
            printf("Lamp state has changed.\n");
            prevLampOnState = lampOn;
        }
        if(acOn != prevAcOnState) {
            printf("AC state has changed.\n");
            prevAcOnState = acOn;
        }
        if(tvOn != prevTvOnState) {
            printf("TV state has changed.\n");
            prevTvOnState = tvOn;
        }
        
        // Get user input
        scanf(" %c", &userInput);

        switch(userInput) {
            case '1':
                toggleDevice(&lampOn, "Lamp");
                break;
            case '2':
                toggleDevice(&acOn, "AC");
                break;
            case '3':
                toggleDevice(&tvOn, "TV");
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}