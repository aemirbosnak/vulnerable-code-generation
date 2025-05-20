//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

typedef enum {
    OFF,
    ON
} Status;

typedef struct {
    char name[NAME_LENGTH];
    Status status;
} Device;

Device devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char *name) {
    if (deviceCount < MAX_DEVICES) {
        strncpy(devices[deviceCount].name, name, NAME_LENGTH);
        devices[deviceCount].status = OFF;
        deviceCount++;
        printf("Device '%s' added.\n", name);
    } else {
        printf("Maximum device limit reached. Cannot add more devices.\n");
    }
}

void toggleDeviceStatus(int index) {
    if (index >= 0 && index < deviceCount) {
        devices[index].status = (devices[index].status == OFF) ? ON : OFF;
        printf("Device '%s' is now %s.\n", devices[index].name, 
            devices[index].status == ON ? "ON" : "OFF");
    } else {
        printf("Invalid device index.\n");
    }
}

void displayDevices() {
    printf("\nDevices in the smart home system:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("%d. %s - %s\n", i + 1, devices[i].name, 
            devices[i].status == ON ? "ON" : "OFF");
    }
}

void initializeDevices() {
    addDevice("Living Room Light");
    addDevice("Bedroom Fan");
    addDevice("Kitchen Thermostat");
    addDevice("Bathroom Light");
}

int main() {
    initializeDevices();
    
    int choice = -1;
    int deviceIndex;

    while (choice != 0) {
        printf("\nSmart Home Automation Menu:\n");
        printf("1. Display Devices\n");
        printf("2. Toggle Device Status\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayDevices();
                break;
            case 2:
                displayDevices();
                printf("Enter device number to toggle (1-%d): ", deviceCount);
                scanf("%d", &deviceIndex);
                toggleDeviceStatus(deviceIndex - 1);
                break;
            case 0:
                printf("Exiting Smart Home Automation System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}