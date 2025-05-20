//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the maximum number of devices
#define MAX_DEVICES 10
#define COMMAND_LENGTH 100

typedef struct {
    char deviceName[20];
    int isOn; // 0 for off, 1 for on
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(char *name) {
    if (deviceCount < MAX_DEVICES) {
        strcpy(devices[deviceCount].deviceName, name);
        devices[deviceCount].isOn = 0; // off by default
        deviceCount++;
        printf("Device %s added successfully!\n", name);
    } else {
        printf("Device limit reached. Cannot add more devices.\n");
    }
}

void toggleDevice(char *name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].deviceName, name) == 0) {
            devices[i].isOn = !devices[i].isOn;
            printf("Device %s is now %s.\n", devices[i].deviceName, devices[i].isOn ? "ON" : "OFF");
            return;
        }
    }
    printf("Device %s not found.\n", name);
}

void statusReport() {
    printf("Smart Home Status Report:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("Device: %s, Status: %s\n", devices[i].deviceName, devices[i].isOn ? "ON" : "OFF");
    }
    if (deviceCount == 0) {
        printf("No devices added yet.\n");
    }
}

void executeCommand(char *command) {
    char operation[10], deviceName[20];

    sscanf(command, "%s %s", operation, deviceName);

    if (strcmp(operation, "ADD") == 0) {
        addDevice(deviceName);
    } else if (strcmp(operation, "TOGGLE") == 0) {
        toggleDevice(deviceName);
    } else if (strcmp(operation, "REPORT") == 0) {
        statusReport();
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    char command[COMMAND_LENGTH];

    printf("Welcome to the Smart Home Automation System!\n");
    printf("Available Commands: ADD <device_name>, TOGGLE <device_name>, REPORT, EXIT\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove the newline character

        if (strcmp(command, "EXIT") == 0) {
            printf("Exiting Smart Home Automation System. Goodbye!\n");
            break;
        }

        executeCommand(command);
        sleep(1); // Simulating a delay as if interacting with devices 
    }

    return 0;
}