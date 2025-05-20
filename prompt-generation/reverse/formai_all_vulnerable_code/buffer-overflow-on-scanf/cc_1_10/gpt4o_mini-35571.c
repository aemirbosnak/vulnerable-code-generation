//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[20];
    int status; // 0: OFF, 1: ON
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char* name) {
    if (deviceCount >= MAX_DEVICES) {
        printf("Wow! Can't add more devices! Max limit reached!\n");
        return;
    }
    strncpy(devices[deviceCount].name, name, sizeof(devices[deviceCount].name) - 1);
    devices[deviceCount].status = 0; // Initially OFF
    deviceCount++;
    printf("Oh snap! Device '%s' added successfully!\n", name);
}

void toggleDevice(const char* name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].status = !devices[i].status;
            const char* statusText = devices[i].status ? "ON" : "OFF";
            printf("Whoa! Device '%s' is now %s!\n", name, statusText);
            return;
        }
    }
    printf("Hmm... Device '%s' not found!\n", name);
}

void listDevices() {
    if (deviceCount == 0) {
        printf("Surprisingly, there are no devices to show!\n");
        return;
    }
    printf("Look at these devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        const char* statusText = devices[i].status ? "ON" : "OFF";
        printf("Device: %s, Status: %s\n", devices[i].name, statusText);
    }
}

void controlDevice() {
    char name[20];
    printf("Which device do you want to control? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove the newline character
    toggleDevice(name);
}

void smartHomeMenu() {
    int choice;

    do {
        printf("\n--- Smart Home Automation ---\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. List All Devices\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the new line character left by scanf

        switch (choice) {
            case 1: {
                char name[20];
                printf("Enter device name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove the newline character
                addDevice(name);
                break;
            }
            case 2:
                printf("Time to control a device!\n");
                controlDevice();
                break;
            case 3:
                listDevices();
                break;
            case 4:
                printf("Exiting... Wow! This was fun!\n");
                break;
            default:
                printf("Whoa! That's an invalid choice! Try again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Smart Home Automation System!\n");
    smartHomeMenu();
    return 0;
}