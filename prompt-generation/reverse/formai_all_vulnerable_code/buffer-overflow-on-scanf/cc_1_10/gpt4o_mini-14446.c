//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LENGTH 50

typedef enum {
    OFF = 0,
    ON
} DeviceState;

typedef struct {
    char name[DEVICE_NAME_LENGTH];
    DeviceState state;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char* name) {
    if (deviceCount < MAX_DEVICES) {
        strncpy(devices[deviceCount].name, name, DEVICE_NAME_LENGTH);
        devices[deviceCount].state = OFF;
        deviceCount++;
        printf("Device '%s' added successfully!\n", name);
    } else {
        printf("Device limit reached! Cannot add more devices.\n");
    }
}

void toggleDevice(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = !devices[i].state;
            printf("Device '%s' is now %s.\n", name, devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

void listDevices() {
    printf("List of Smart Devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].state == ON ? "ON" : "OFF");
    }
}

void simulateScheduling(const char* name, int duration) {
    toggleDevice(name);
    sleep(duration);
    toggleDevice(name);
}

int main() {
    int choice;
    char deviceName[DEVICE_NAME_LENGTH];
    
    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. List Devices\n");
        printf("4. Schedule Device (turn ON for a certain duration)\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", deviceName);
                addDevice(deviceName);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                scanf("%s", deviceName);
                toggleDevice(deviceName);
                break;
            case 3:
                listDevices();
                break;
            case 4:
                printf("Enter device name to schedule: ");
                scanf("%s", deviceName);
                int duration;
                printf("Enter duration in seconds: ");
                scanf("%d", &duration);
                printf("Scheduling device '%s' for %d seconds...\n", deviceName, duration);
                simulateScheduling(deviceName, duration);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select from 1 to 5.\n");
        }
    }

    return 0;
}