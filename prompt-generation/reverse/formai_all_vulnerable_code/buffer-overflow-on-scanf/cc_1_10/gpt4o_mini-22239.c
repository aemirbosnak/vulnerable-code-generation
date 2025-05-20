//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 30

typedef enum {
    OFF,
    ON
} DeviceState;

typedef struct {
    char name[MAX_NAME_LENGTH];
    DeviceState state;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char *name) {
    if (deviceCount < MAX_DEVICES) {
        strncpy(devices[deviceCount].name, name, MAX_NAME_LENGTH);
        devices[deviceCount].state = OFF;
        deviceCount++;
        printf("Device '%s' added successfully.\n", name);
    } else {
        printf("Device limit reached, can't add more devices.\n");
    }
}

void removeDevice(const char *name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i] = devices[deviceCount - 1]; // Replace with last device
            deviceCount--;
            printf("Device '%s' removed successfully.\n", name);
            return;
        }
    }
    printf("No device with name '%s' found.\n", name);
}

void toggleDevice(const char *name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = (devices[i].state == OFF) ? ON : OFF;
            printf("Device '%s' is now %s.\n", name, (devices[i].state == ON) ? "ON" : "OFF");
            return;
        }
    }
    printf("No device with name '%s' found.\n", name);
}

void listDevices() {
    if (deviceCount == 0) {
        printf("No devices available.\n");
        return;
    }

    printf("Devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("-%s: %s\n", devices[i].name, (devices[i].state == ON) ? "ON" : "OFF");
    }
}

void showMenu() {
    printf("\nSmart Home Automation Menu:\n");
    printf("1. Add Device\n");
    printf("2. Remove Device\n");
    printf("3. Toggle Device\n");
    printf("4. List Devices\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", name);
                addDevice(name);
                break;

            case 2:
                printf("Enter device name to remove: ");
                scanf("%s", name);
                removeDevice(name);
                break;

            case 3:
                printf("Enter device name to toggle: ");
                scanf("%s", name);
                toggleDevice(name);
                break;

            case 4:
                listDevices();
                break;

            case 5:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
        sleep(1); // Pause for a good user experience
    }

    return 0;
}