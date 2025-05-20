//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of devices that can be controlled
#define MAX_DEVICES 100

// Define the structure for each device
typedef struct {
    char name[50];
    int status;
} Device;

// Initialize the devices
Device devices[MAX_DEVICES] = {{"Living Room Light", 0}, {"Bedroom Light", 0}, {"Kitchen Light", 0}, {"TV", 0}, {"Air Conditioner", 0}};

// Function to turn a device on or off
void controlDevice(char* deviceName, int status) {
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {
        if (strcmp(devices[i].name, deviceName) == 0) {
            devices[i].status = status;
            printf("%s has been set to %s.\n", devices[i].name, status? "on" : "off");
            break;
        }
    }
}

// Function to query the status of a device
void queryDevice(char* deviceName) {
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {
        if (strcmp(devices[i].name, deviceName) == 0) {
            printf("%s is currently %s.\n", devices[i].name, devices[i].status? "on" : "off");
            break;
        }
    }
}

// Function to list all available devices
void listDevices() {
    int i;
    printf("Available devices:\n");
    for (i = 0; i < MAX_DEVICES; i++) {
        printf("%s\n", devices[i].name);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Smart Home Automation System\n");
        printf("1. Control a device\n");
        printf("2. Query the status of a device\n");
        printf("3. List all available devices\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the name of the device: ");
            char deviceName[50];
            scanf("%s", deviceName);
            printf("Enter the desired status (on or off): ");
            int status;
            scanf("%d", &status);
            controlDevice(deviceName, status);
            break;
        case 2:
            printf("Enter the name of the device: ");
            char deviceName2[50];
            scanf("%s", deviceName2);
            queryDevice(deviceName2);
            break;
        case 3:
            listDevices();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}