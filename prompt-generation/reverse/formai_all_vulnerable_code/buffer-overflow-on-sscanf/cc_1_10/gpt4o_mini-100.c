//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

typedef enum {
    OFF, ON
} State;

typedef struct {
    char name[NAME_LENGTH];
    State state;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char* name) {
    if (deviceCount < MAX_DEVICES) {
        strcpy(devices[deviceCount].name, name);
        devices[deviceCount].state = OFF;
        deviceCount++;
        printf("Added device: %s\n", name);
    } else {
        printf("Device limit reached!\n");
    }
}

void removeDevice(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            for (int j = i; j < deviceCount - 1; j++) {
                devices[j] = devices[j + 1];
            }
            deviceCount--;
            printf("Removed device: %s\n", name);
            return;
        }
    }
    printf("Device not found: %s\n", name);
}

void toggleDevice(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = (devices[i].state == OFF) ? ON : OFF;
            printf("%s is now %s\n", name, devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device not found: %s\n", name);
}

void listDevices() {
    printf("Smart Devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("%s - %s\n", devices[i].name, devices[i].state == ON ? "ON" : "OFF");
    }
}

void simulate() {
    while (1) {
        char command[100];
        printf("\nEnter command (add/remove/toggle/list/exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strncmp(command, "add", 3) == 0) {
            char deviceName[NAME_LENGTH];
            sscanf(command + 4, "%s", deviceName);
            addDevice(deviceName);
        } else if (strncmp(command, "remove", 6) == 0) {
            char deviceName[NAME_LENGTH];
            sscanf(command + 7, "%s", deviceName);
            removeDevice(deviceName);
        } else if (strncmp(command, "toggle", 6) == 0) {
            char deviceName[NAME_LENGTH];
            sscanf(command + 7, "%s", deviceName);
            toggleDevice(deviceName);
        } else if (strncmp(command, "list", 4) == 0) {
            listDevices();
        } else if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting simulation.\n");
            break;
        } else {
            printf("Unknown command!\n");
        }

        // Add a short pause for a more user-friendly experience.
        usleep(500000);
    }
}

int main() {
    printf("Welcome to the Smart Home Automation System!\n");
    printf("You can add, remove, toggle, and list your smart devices.\n");
    simulate();
    return 0;
}