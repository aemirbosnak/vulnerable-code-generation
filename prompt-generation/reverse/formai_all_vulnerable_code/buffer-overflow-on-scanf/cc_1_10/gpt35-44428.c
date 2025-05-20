//FormAI DATASET v1.0 Category: Smart home automation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIGHTS 0
#define AC 1
#define MUSIC 2
#define ALARM 3
#define WINDOW_SHADES 4

// Function prototypes
void toggleDevice(int deviceNum, bool *deviceState);
void displayMenu();
void displayDevices(bool *deviceStates);
void setDeviceStates(bool *deviceStates);
void randomizeDeviceStates(bool *deviceStates);

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    bool deviceStates[5] = {false};
    char selection;
    
    setDeviceStates(deviceStates);
    
    printf("Welcome to your Smart Home!\n");
    
    do {
        displayDevices(deviceStates);
        displayMenu();
        scanf(" %c", &selection);
        
        switch(selection) {
            case 't':
                // Toggle device
                printf("\nEnter device number: ");
                int deviceNum;
                scanf("%d", &deviceNum);
                toggleDevice(deviceNum, deviceStates);
                break;
            case 's':
                // Set device states
                setDeviceStates(deviceStates);
                break;
            case 'r':
                // Randomize device states
                randomizeDeviceStates(deviceStates);
                break;
            case 'q':
                // Quit program
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid selection. Please try again.\n");
        }
    } while(true);
    
    return 0;
}

/**
 * Toggles the state of a device.
 * @param deviceNum the device number
 * @param deviceStates the array of device states
 */
void toggleDevice(int deviceNum, bool *deviceStates) {
    if(deviceNum < 0 || deviceNum >= 5) {
        printf("\nInvalid device number. Please try again.\n");
        return;
    }
    
    deviceStates[deviceNum] = !deviceStates[deviceNum];
    
    if(deviceStates[deviceNum]) {
        printf("\nDevice %d has been turned ON.\n", deviceNum);
    }
    else {
        printf("\nDevice %d has been turned OFF.\n", deviceNum);
    }
}

/**
 * Displays the main menu.
 */
void displayMenu() {
    printf("\nMain Menu:");
    printf("\n(t)oggle device state");
    printf("\n(s)et device states");
    printf("\n(r)andomize device states");
    printf("\n(q)uit program");
    printf("\nEnter your selection: ");
}

/**
 * Displays the current state of all devices.
 * @param deviceStates the array of device states
 */
void displayDevices(bool *deviceStates) {
    printf("\nCurrent Smart Home state:");
    printf("\nLights: %d", deviceStates[LIGHTS]);
    printf("\nAC: %d", deviceStates[AC]);
    printf("\nMusic: %d", deviceStates[MUSIC]);
    printf("\nAlarm: %d", deviceStates[ALARM]);
    printf("\nWindow Shades: %d\n", deviceStates[WINDOW_SHADES]);
}

/**
 * Asks the user to set the state of all devices.
 * @param deviceStates the array of device states
 */
void setDeviceStates(bool *deviceStates) {
    printf("\nSet the state of all Smart Home devices:");
    printf("\nLights (0=off, 1=on): ");
    scanf("%d", &deviceStates[LIGHTS]);
    printf("AC (0=off, 1=on): ");
    scanf("%d", &deviceStates[AC]);
    printf("Music (0=off, 1=on): ");
    scanf("%d", &deviceStates[MUSIC]);
    printf("Alarm (0=off, 1=on): ");
    scanf("%d", &deviceStates[ALARM]);
    printf("Window Shades (0=closed, 1=open): ");
    scanf("%d", &deviceStates[WINDOW_SHADES]);
}

/**
 * Randomizes the state of all devices.
 * @param deviceStates the array of device states
 */
void randomizeDeviceStates(bool *deviceStates) {
    for(int i = 0; i < 5; i++) {
        deviceStates[i] = rand() % 2 == 0;
    }
    
    printf("\nSmart Home devices have been randomized.\n");
}