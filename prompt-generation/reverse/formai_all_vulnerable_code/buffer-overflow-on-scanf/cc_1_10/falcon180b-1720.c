//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of devices in the smart home
#define NUM_DEVICES 5

// Define the maximum length of a device name
#define MAX_DEVICE_NAME_LENGTH 20

// Define the structure for a smart home device
typedef struct {
    char name[MAX_DEVICE_NAME_LENGTH];
    int status;
} Device;

// Initialize the smart home devices
Device devices[NUM_DEVICES] = {
    {"Living Room Light", 0},
    {"Bedroom Light", 0},
    {"Kitchen Light", 0},
    {"TV", 0},
    {"Music System", 0}
};

// Function to turn a device on
void turnOnDevice(int deviceIndex) {
    printf("Turning on device %s...\n", devices[deviceIndex].name);
    devices[deviceIndex].status = 1;
}

// Function to turn a device off
void turnOffDevice(int deviceIndex) {
    printf("Turning off device %s...\n", devices[deviceIndex].name);
    devices[deviceIndex].status = 0;
}

// Function to toggle a device
void toggleDevice(int deviceIndex) {
    if (devices[deviceIndex].status == 0) {
        turnOnDevice(deviceIndex);
    } else {
        turnOffDevice(deviceIndex);
    }
}

// Function to print the status of all devices
void printDeviceStatus() {
    printf("\nCurrent status of smart home devices:\n");
    for (int i = 0; i < NUM_DEVICES; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].status? "On" : "Off");
    }
}

// Function to handle user commands
void handleCommand(char* command) {
    int deviceIndex = -1;
    for (int i = 0; i < NUM_DEVICES; i++) {
        if (strcmp(devices[i].name, command) == 0) {
            deviceIndex = i;
            break;
        }
    }

    if (deviceIndex == -1) {
        printf("Device not found.\n");
    } else {
        if (strcmp(command, "on") == 0 || strcmp(command, "toggle") == 0) {
            turnOnDevice(deviceIndex);
        } else if (strcmp(command, "off") == 0) {
            turnOffDevice(deviceIndex);
        } else {
            printf("Invalid command.\n");
        }
    }

    printDeviceStatus();
}

// Main function
int main() {
    printf("Welcome to your smart home!\n\n");
    printDeviceStatus();

    char command[MAX_DEVICE_NAME_LENGTH];
    while (1) {
        printf("\nEnter a command (e.g. 'living room light on'): ");
        scanf("%s", command);
        handleCommand(command);
    }

    return 0;
}