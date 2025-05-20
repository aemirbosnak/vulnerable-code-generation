//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define BUFFER_SIZE 100

typedef struct {
    char name[30];
    int state; // 0 for OFF, 1 for ON
} Device;

Device devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char *name) {
    if (deviceCount < MAX_DEVICES) {
        strcpy(devices[deviceCount].name, name);
        devices[deviceCount].state = 0; // Initially set to OFF
        deviceCount++;
        printf("Device '%s' added successfully!\n", name);
    } else {
        printf("Device limit reached, cannot add more devices.\n");
    }
}

void toggleDevice(const char *name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = !devices[i].state;
            printf("Device '%s' is now %s.\n", name, devices[i].state ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void showDevices() {
    printf("\nConnected Devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf(" - %s: %s\n", devices[i].name, devices[i].state ? "ON" : "OFF");
    }
    printf("\n");
}

void executeCommand(char *command) {
    char action[10];
    char deviceName[30];
    
    if (sscanf(command, "%s %s", action, deviceName) != 2) {
        printf("Invalid command. Use 'ADD <device_name>', 'TOGGLE <device_name>', or 'SHOW'.\n");
        return;
    }
    
    if (strcmp(action, "ADD") == 0) {
        addDevice(deviceName);
    } else if (strcmp(action, "TOGGLE") == 0) {
        toggleDevice(deviceName);
    } else if (strcmp(action, "SHOW") == 0) {
        showDevices();
    } else {
        printf("Unknown action: %s\n", action);
    }
}

int main() {
    char command[BUFFER_SIZE];
    
    printf("Welcome to Smart Home Automation System.\n");
    printf("Available commands: ADD <device_name>, TOGGLE <device_name>, SHOW, EXIT\n");
    
    while (1) {
        printf("Enter command: ");
        if (fgets(command, BUFFER_SIZE, stdin) == NULL) {
            break;
        }

        // Remove newline character from the command input
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "EXIT") == 0) {
            break;
        }

        executeCommand(command);
        sleep(1); // Sleep for a second to simulate processing time
    }

    printf("Exiting Smart Home Automation System. Goodbye!\n");
    return 0;
}