//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LENGTH 50

enum DeviceState {
    OFF,
    ON
};

typedef struct {
    char name[DEVICE_NAME_LENGTH];
    enum DeviceState state;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

// Function to initialize a new device
void initDevice(const char *name) {
    if (device_count >= MAX_DEVICES) {
        printf("Maximum device limit reached!\n");
        return;
    }
    strcpy(devices[device_count].name, name);
    devices[device_count].state = OFF;
    device_count++;
    printf("Device '%s' initialized and added.\n", name);
}

// Function to display the state of all devices
void displayDevices() {
    printf("\n=== Smart Home Devices ===\n");
    for (int i = 0; i < device_count; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].state == ON ? "ON" : "OFF");
    }
    printf("==========================\n");
}

// Function to turn on a device
void turnOnDevice(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = ON;
            printf("Device '%s' has been turned ON.\n", name);
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

// Function to turn off a device
void turnOffDevice(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = OFF;
            printf("Device '%s' has been turned OFF.\n", name);
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

// Function to toggle a device state
void toggleDevice(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = (devices[i].state == ON) ? OFF : ON;
            printf("Device '%s' toggled to %s.\n", name, devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

// Function to find a device
int findDeviceIndex(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  // Device not found
}

// Function to handle commands
void handleCommands() {
    char command[100];
    char deviceName[DEVICE_NAME_LENGTH];

    while (1) {
        printf("Enter command (add <device>, on <device>, off <device>, toggle <device>, display, exit): ");
        fgets(command, sizeof(command), stdin);
        sscanf(command, "%s %s", command, deviceName);

        if (strncmp(command, "add", 3) == 0) {
            initDevice(deviceName);
        } else if (strncmp(command, "on", 2) == 0) {
            turnOnDevice(deviceName);
        } else if (strncmp(command, "off", 3) == 0) {
            turnOffDevice(deviceName);
        } else if (strncmp(command, "toggle", 6) == 0) {
            toggleDevice(deviceName);
        } else if (strcmp(command, "display\n") == 0) {
            displayDevices();
        } else if (strcmp(command, "exit\n") == 0) {
            printf("Exiting Smart Home Automation...\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Automation System!\n");
    handleCommands();
    return 0;
}