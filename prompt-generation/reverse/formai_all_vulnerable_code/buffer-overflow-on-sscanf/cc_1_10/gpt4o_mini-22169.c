//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int status; // 0 off, 1 on
} Device;

Device devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char* name) {
    if (deviceCount < MAX_DEVICES) {
        strncpy(devices[deviceCount].name, name, NAME_LENGTH - 1);
        devices[deviceCount].name[NAME_LENGTH - 1] = '\0';
        devices[deviceCount].status = 0; // default status off
        deviceCount++;
        printf("Device '%s' added successfully.\n", name);
    } else {
        printf("Device limit reached. Cannot add more devices.\n");
    }
}

void toggleDevice(int index) {
    if (index >= 0 && index < deviceCount) {
        devices[index].status = !devices[index].status;
        printf("Device '%s' is now %s.\n", devices[index].name, 
               devices[index].status ? "ON" : "OFF");
    } else {
        printf("Invalid device index.\n");
    }
}

void showDevices() {
    printf("List of Smart Home Devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf(" [%d] %s - %s\n", i, devices[i].name, devices[i].status ? "ON" : "OFF");
    }
}

void executeCommand(const char* command) {
    char action[10], deviceName[NAME_LENGTH];
    int index;

    if (sscanf(command, "add %s", deviceName) == 1) {
        addDevice(deviceName);
    } else if (sscanf(command, "toggle %d", &index) == 1) {
        toggleDevice(index);
    } else if (strcmp(command, "show") == 0) {
        showDevices();
    } else {
        printf("Unknown command. Available commands: add <device>, toggle <index>, show\n");
    }
}

int main() {
    char command[100];

    printf("Welcome to the Smart Home Automation System!\n");
    printf("You can add devices, toggle their status, or show all devices.\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove the newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the Smart Home Automation System. Goodbye!\n");
            break;
        }

        executeCommand(command);
        sleep(1); // Simulate some delay for realistic interaction
    }

    return 0;
}