//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Define the maximum number of devices that can be controlled
#define MAX_DEVICES 10

// Define the structure for each device
typedef struct {
    char name[20];
    int on;
} Device;

// Create an array of devices
Device devices[MAX_DEVICES];

// Initialize all devices to be off
void initDevices() {
    for (int i = 0; i < MAX_DEVICES; i++) {
        devices[i].on = FALSE;
    }
}

// Turn a device on
void turnOnDevice(int index) {
    if (index >= 0 && index < MAX_DEVICES) {
        devices[index].on = TRUE;
        printf("Device %s turned on.\n", devices[index].name);
    } else {
        printf("Invalid device index.\n");
    }
}

// Turn a device off
void turnOffDevice(int index) {
    if (index >= 0 && index < MAX_DEVICES) {
        devices[index].on = FALSE;
        printf("Device %s turned off.\n", devices[index].name);
    } else {
        printf("Invalid device index.\n");
    }
}

// Check if a device is on
int isDeviceOn(int index) {
    if (index >= 0 && index < MAX_DEVICES) {
        return devices[index].on;
    } else {
        return FALSE;
    }
}

// Define the main function
int main() {
    // Initialize all devices to be off
    initDevices();

    // Get user input to control devices
    char input[100];
    while (TRUE) {
        printf("Enter command (on/off/check): ");
        scanf("%s", input);

        // Parse the input and execute the appropriate function
        if (strcmp(input, "on") == 0) {
            printf("Enter device index: ");
            int index;
            scanf("%d", &index);
            turnOnDevice(index);
        } else if (strcmp(input, "off") == 0) {
            printf("Enter device index: ");
            int index;
            scanf("%d", &index);
            turnOffDevice(index);
        } else if (strcmp(input, "check") == 0) {
            printf("Enter device index: ");
            int index;
            scanf("%d", &index);
            int isOn = isDeviceOn(index);
            if (isOn) {
                printf("Device %s is on.\n", devices[index].name);
            } else {
                printf("Device %s is off.\n", devices[index].name);
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}