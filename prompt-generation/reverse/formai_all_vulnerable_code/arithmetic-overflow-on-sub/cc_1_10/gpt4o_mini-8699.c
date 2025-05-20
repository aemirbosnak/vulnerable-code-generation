//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    bool status;  // true for ON, false for OFF
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char *name) {
    if (deviceCount < MAX_DEVICES) {
        strncpy(devices[deviceCount].name, name, NAME_LENGTH - 1);
        devices[deviceCount].status = false;  // Initialize as OFF
        deviceCount++;
        printf("Device '%s' added successfully!\n", name);
    } else {
        printf("Device limit reached. Cannot add more!\n");
    }
}

void toggleDevice(int index) {
    if (index < 0 || index >= deviceCount) {
        printf("Invalid device index!\n");
        return;
    }
    devices[index].status = !devices[index].status;
    printf("Device '%s' turned %s.\n", devices[index].name, devices[index].status ? "ON" : "OFF");
}

void listDevices() {
    if (deviceCount == 0) {
        printf("No devices found.\n");
        return;
    }
    printf("\nSmart Home Device List:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("%d. %s - %s\n", i + 1, devices[i].name, devices[i].status ? "ON" : "OFF");
    }
    printf("\n");
}

void controlDevices() {
    int choice;
    listDevices();
    printf("Enter the device number to toggle (0 to exit): ");
    scanf("%d", &choice);
    while (choice != 0) {
        toggleDevice(choice - 1);
        printf("Enter another device number to toggle (0 to exit): ");
        scanf("%d", &choice);
    }
}

void scheduleDevice(int index, int delay) {
    if (index < 0 || index >= deviceCount) {
        printf("Invalid device index for scheduling!\n");
        return;
    }
    printf("Scheduling device '%s' to toggle in %d seconds...\n", devices[index].name, delay);
    sleep(delay); // Simulating delay
    toggleDevice(index);
}

void automatedControl() {
    char command[50];
    printf("Enter command to automate (e.g., 'turn on Device 1 in 5 seconds'): ");
    getchar(); // Clear the newline buffer
    fgets(command, sizeof(command), stdin);
    char action[10];
    char deviceName[NAME_LENGTH];
    int delay;

    sscanf(command, "%s %s in %d seconds", action, deviceName, &delay);

    for (int i = 0; i < deviceCount; i++) {
        if (strncmp(devices[i].name, deviceName, NAME_LENGTH) == 0) {
            if (strcmp(action, "turn") == 0 || strcmp(action, "turn on") == 0) {
                scheduleDevice(i, delay);
            } else {
                printf("Unknown action: %s\n", action);
            }
            return;
        }
    }
    printf("Device '%s' not found.\n", deviceName);
}

int main() {
    char choice;
    char name[NAME_LENGTH];

    while (true) {
        printf("Smart Home Management System\n");
        printf("==============================\n");
        printf("1. Add Device\n");
        printf("2. Control Devices\n");
        printf("3. Automate Control\n");
        printf("4. List Devices\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                printf("Enter device name to add: ");
                scanf("%s", name);
                addDevice(name);
                break;
            case '2':
                controlDevices();
                break;
            case '3':
                automatedControl();
                break;
            case '4':
                listDevices();
                break;
            case '5':
                printf("Exiting the Smart Home Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}