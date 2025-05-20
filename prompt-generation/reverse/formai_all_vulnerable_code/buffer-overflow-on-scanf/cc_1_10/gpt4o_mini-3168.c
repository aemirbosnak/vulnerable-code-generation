//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10
#define MAX_NAME_LEN 30

// Define a structure to hold information about a smart device
typedef struct {
    char name[MAX_NAME_LEN];
    int status; // 0 for off, 1 for on
} SmartDevice;

// Function prototypes
void initializeDevices(SmartDevice devices[], int count);
void toggleDevice(SmartDevice *device);
void printDeviceStatus(SmartDevice devices[], int count);
void displayMenu();
void controlDevices(SmartDevice devices[], int count);

int main() {
    SmartDevice devices[MAX_DEVICES];
    int deviceCount = 3;

    initializeDevices(devices, deviceCount);
    controlDevices(devices, deviceCount);

    return 0;
}

// Function to initialize smart devices with default names and status
void initializeDevices(SmartDevice devices[], int count) {
    strcpy(devices[0].name, "Living Room Light");
    devices[0].status = 0;
    
    strcpy(devices[1].name, "Thermostat");
    devices[1].status = 0;
    
    strcpy(devices[2].name, "Security Camera");
    devices[2].status = 0;
}

// Function to toggle the status of a smart device
void toggleDevice(SmartDevice *device) {
    device->status = !device->status;
}

// Function to print the status of all devices
void printDeviceStatus(SmartDevice devices[], int count) {
    printf("\n--- Device Status ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].status ? "On" : "Off");
    }
    printf("----------------------\n");
}

// Function to display the control menu
void displayMenu() {
    printf("=== Smart Home Automation ===\n");
    printf("1. Toggle Living Room Light\n");
    printf("2. Toggle Thermostat\n");
    printf("3. Toggle Security Camera\n");
    printf("4. Show device status\n");
    printf("0. Exit\n");
    printf("============================\n");
}

// Function to control devices based on user input
void controlDevices(SmartDevice devices[], int count) {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                toggleDevice(&devices[0]);
                printf("Toggled Living Room Light.\n");
                break;
            case 2:
                toggleDevice(&devices[1]);
                printf("Toggled Thermostat.\n");
                break;
            case 3:
                toggleDevice(&devices[2]);
                printf("Toggled Security Camera.\n");
                break;
            case 4:
                printDeviceStatus(devices, count);
                break;
            case 0:
                printf("Exiting Smart Home Automation.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n");
    }
}