//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LEN 50

typedef enum {
    ON,
    OFF
} DeviceStatus;

typedef struct {
    char name[DEVICE_NAME_LEN];
    DeviceStatus status;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char* name) {
    if (deviceCount >= MAX_DEVICES) {
        printf("Device limit reached. Cannot add more devices.\n");
        return;
    }
    strncpy(devices[deviceCount].name, name, DEVICE_NAME_LEN);
    devices[deviceCount].status = OFF; // new devices are off by default
    deviceCount++;
    printf("Added device: %s\n", name);
}

void removeDevice(int index) {
    if (index < 0 || index >= deviceCount) {
        printf("Invalid device index.\n");
        return;
    }
    printf("Removing device: %s\n", devices[index].name);
    for (int i = index; i < deviceCount - 1; i++) {
        devices[i] = devices[i + 1]; // Shift devices to fill the gap
    }
    deviceCount--;
}

void toggleDevice(int index) {
    if (index < 0 || index >= deviceCount) {
        printf("Invalid device index.\n");
        return;
    }
    devices[index].status = (devices[index].status == ON) ? OFF : ON;
    const char *statusString = (devices[index].status == ON) ? "ON" : "OFF";
    printf("Device %s toggled %s.\n", devices[index].name, statusString);
}

void listDevices() {
    printf("\nSmart Home Devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        const char *statusString = (devices[i].status == ON) ? "ON" : "OFF";
        printf("%d: %s - %s\n", i, devices[i].name, statusString);
    }
    if (deviceCount == 0) {
        printf("No devices available.\n");
    }
}

void controlDevice(int index, DeviceStatus status) {
    if (index < 0 || index >= deviceCount) {
        printf("Invalid device index.\n");
        return;
    }
    devices[index].status = status;
    const char *statusString = (status == ON) ? "ON" : "OFF";
    printf("Device %s is now %s.\n", devices[index].name, statusString);
}

void executeCommand(char *command) {
    char action[20], name[DEVICE_NAME_LEN];
    int index;

    if (sscanf(command, "add %s", name) == 1) {
        addDevice(name);
    } else if (sscanf(command, "remove %d", &index) == 1) {
        removeDevice(index);
    } else if (sscanf(command, "toggle %d", &index) == 1) {
        toggleDevice(index);
    } else if (strcmp(command, "list") == 0) {
        listDevices();
    } else if (sscanf(command, "set %d %s", &index, name) == 2) {
        if (strcmp(name, "on") == 0) {
            controlDevice(index, ON);
        } else if (strcmp(name, "off") == 0) {
            controlDevice(index, OFF);
        } else {
            printf("Invalid status. Use 'on' or 'off'.\n");
        }
    } else {
        printf("Unknown command. Try 'add', 'remove', 'toggle', 'list', or 'set'.\n");
    }
}

int main() {
    char command[100];

    printf("Welcome to the Smart Home Automation System!\n");
    printf("Available commands: add <device_name>, remove <index>, toggle <index>, list, set <index> <on/off>\n");

    while (1) {
        printf("\n> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;  // Remove trailing newline

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the Smart Home Automation System. Goodbye!\n");
            break;
        }

        executeCommand(command);
    }

    return 0;
}