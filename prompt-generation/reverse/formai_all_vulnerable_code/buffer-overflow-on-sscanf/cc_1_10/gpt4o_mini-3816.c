//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LENGTH 50

typedef enum {
    OFF,
    ON
} DeviceState;

typedef struct {
    char name[DEVICE_NAME_LENGTH];
    DeviceState state;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char *deviceName) {
    if (deviceCount < MAX_DEVICES) {
        strncpy(devices[deviceCount].name, deviceName, DEVICE_NAME_LENGTH);
        devices[deviceCount].state = OFF;
        deviceCount++;
        printf("Device '%s' added.\n", deviceName);
    } else {
        printf("Device limit reached. Cannot add more devices.\n");
    }
}

void removeDevice(const char *deviceName) {
    for (int i = 0; i < deviceCount; i++) {
        if (strncmp(devices[i].name, deviceName, DEVICE_NAME_LENGTH) == 0) {
            // Move the last device to the current position
            devices[i] = devices[deviceCount - 1];
            deviceCount--;
            printf("Device '%s' removed.\n", deviceName);
            return;
        }
    }
    printf("Device '%s' not found.\n", deviceName);
}

void toggleDevice(const char *deviceName) {
    for (int i = 0; i < deviceCount; i++) {
        if (strncmp(devices[i].name, deviceName, DEVICE_NAME_LENGTH) == 0) {
            devices[i].state = (devices[i].state == ON) ? OFF : ON;
            const char *stateStr = (devices[i].state == ON) ? "ON" : "OFF";
            printf("Device '%s' toggled to %s.\n", deviceName, stateStr);
            return;
        }
    }
    printf("Device '%s' not found.\n", deviceName);
}

void listDevices() {
    printf("Smart Devices List:\n");
    for (int i = 0; i < deviceCount; i++) {
        const char *stateStr = (devices[i].state == ON) ? "ON" : "OFF";
        printf("%d: %s - State: %s\n", i + 1, devices[i].name, stateStr);
    }
}

void scheduleDevice(const char *deviceName, int hour, int minute) {
    printf("Scheduling device '%s' to toggle at %02d:%02d.\n", deviceName, hour, minute);
    // Simulating scheduling (in a real scenario, you would use threads or timers)
    time_t t;
    struct tm *tm_info;
    
    while (1) {
        time(&t);
        tm_info = localtime(&t);

        if (tm_info->tm_hour == hour && tm_info->tm_min == minute) {
            toggleDevice(deviceName);
            break;
        }

        sleep(30); // Check every 30 seconds
    }
}

void executeCommand(const char *command) {
    char deviceName[DEVICE_NAME_LENGTH];
    if (sscanf(command, "ADD %s", deviceName) == 1) {
        addDevice(deviceName);
    } else if (sscanf(command, "REMOVE %s", deviceName) == 1) {
        removeDevice(deviceName);
    } else if (sscanf(command, "TOGGLE %s", deviceName) == 1) {
        toggleDevice(deviceName);
    } else if (strcmp(command, "LIST") == 0) {
        listDevices();
    } else {
        printf("Invalid command. Use ADD, REMOVE, TOGGLE, or LIST.\n");
    }
}

int main() {
    char command[100];

    printf("Welcome to the Smart Home Automation System!\n");
    
    while (1) {
        printf("\nEnter command (ADD, REMOVE, TOGGLE, LIST, or EXIT): ");
        fgets(command, sizeof(command), stdin);
        
        // Removing newline character
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "EXIT") == 0) {
            printf("Exiting the Smart Home Automation System.\n");
            break;
        }

        executeCommand(command);
    }

    return 0;
}