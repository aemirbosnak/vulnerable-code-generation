//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_DEVICES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int status; // 0: off, 1: on
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char *name) {
    if (deviceCount < MAX_DEVICES) {
        strcpy(devices[deviceCount].name, name);
        devices[deviceCount].status = 0; // Start as off
        deviceCount++;
        printf("Device '%s' added successfully.\n", name);
    } else {
        printf("Maximum device limit reached!\n");
    }
}

void toggleDevice(const char *name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].status = !devices[i].status;
            printf("Device '%s' is now %s.\n", devices[i].name, devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void listDevices() {
    if (deviceCount == 0) {
        printf("No devices found.\n");
        return;
    }
    printf("List of Smart Devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf(" - %s: %s\n", devices[i].name, devices[i].status ? "ON" : "OFF");
    }
}

void scheduleDevice(const char *name, int seconds) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            printf("Scheduling device '%s' to toggle after %d seconds.\n", name, seconds);
            sleep(seconds);
            devices[i].status = !devices[i].status;
            printf("Device '%s' is now %s.\n", devices[i].name, devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void displayMenu() {
    printf("Welcome to the Smart Home Automation System!\n");
    printf("1. Add Device\n");
    printf("2. Toggle Device\n");
    printf("3. List Devices\n");
    printf("4. Schedule Device\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int option;
    char deviceName[NAME_LENGTH];
    int seconds;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter device name to add: ");
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
                printf("Enter time in seconds to toggle: ");
                scanf("%d", &seconds);
                scheduleDevice(deviceName, seconds);
                break;
            case 5:
                printf("Exiting Smart Home Automation System. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}