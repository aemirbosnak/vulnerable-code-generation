//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 100

typedef struct {
    char name[50];
    bool status; // true for ON, false for OFF
} Device;

typedef struct {
    Device devices[MAX_DEVICES];
    int deviceCount;
} SmartHome;

void initializeSmartHome(SmartHome *home) {
    home->deviceCount = 0;
}

void addDevice(SmartHome *home, const char *deviceName) {
    if (home->deviceCount < MAX_DEVICES) {
        strcpy(home->devices[home->deviceCount].name, deviceName);
        home->devices[home->deviceCount].status = false; // Initially, devices are OFF
        home->deviceCount++;
        printf("Device '%s' added successfully!\n", deviceName);
    } else {
        printf("Device limit reached! Cannot add more devices.\n");
    }
}

void toggleDevice(SmartHome *home, const char *deviceName) {
    for (int i = 0; i < home->deviceCount; i++) {
        if (strcmp(home->devices[i].name, deviceName) == 0) {
            home->devices[i].status = !home->devices[i].status; // Toggle status
            printf("Device '%s' is now %s\n", deviceName, home->devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", deviceName);
}

void displayDevices(SmartHome *home) {
    printf("\nSmart Home Devices:\n");
    for (int i = 0; i < home->deviceCount; i++) {
        printf("%s: %s\n", home->devices[i].name, home->devices[i].status ? "ON" : "OFF");
    }
    printf("\n");
}

void executeCommand(SmartHome *home, const char *command) {
    char action[20], deviceName[50];
    if (sscanf(command, "%s %s", action, deviceName) < 2) {
        printf("Invalid command format. Use 'add <device>', 'toggle <device>', or 'list'.\n");
        return;
    }
    
    if (strcmp(action, "add") == 0) {
        addDevice(home, deviceName);
    } else if (strcmp(action, "toggle") == 0) {
        toggleDevice(home, deviceName);
    } else if (strcmp(action, "list") == 0) {
        displayDevices(home);
    } else {
        printf("Unknown command: %s\n", action);
    }
}

int main() {
    SmartHome myHome;
    initializeSmartHome(&myHome);
    char command[100];

    printf("Welcome to Smart Home Automation System!\n");
    printf("Available commands:\n");
    printf("1. add <device>\n");
    printf("2. toggle <device>\n");
    printf("3. list\n");
    printf("4. exit\n");

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Automation System. Goodbye!\n");
            break;
        }

        executeCommand(&myHome, command);
    }

    return 0;
}