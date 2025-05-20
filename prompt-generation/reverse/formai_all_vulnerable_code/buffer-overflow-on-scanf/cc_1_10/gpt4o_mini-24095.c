//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define NAME_SIZE 20

typedef struct Device {
    char name[NAME_SIZE];
    int status; // 1 for ON, 0 for OFF
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

// Function to add a device recursively
void addDevice() {
    if (device_count >= MAX_DEVICES) {
        printf("Maximum device limit reached.\n");
        return;
    }

    Device newDevice;
    printf("Enter device name: ");
    scanf("%s", newDevice.name);
    
    newDevice.status = 0; // New device starts OFF
    devices[device_count++] = newDevice;

    char choice;
    printf("Do you want to add another device (y/n)? ");
    scanf(" %c", &choice);
    if (choice == 'y') {
        addDevice();
    }
}

// Function to toggle the status of a device recursively
void toggleDevice(int index) {
    if (index >= device_count) {
        return; // Base case: Check if we've reached beyond device count
    }

    printf("Toggle device %s (current status: %s)? (y/n): ", devices[index].name, devices[index].status ? "ON" : "OFF");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y') {
        devices[index].status = !devices[index].status; // Toggle the status
        printf("%s is now %s\n", devices[index].name, devices[index].status ? "ON" : "OFF");
    }
    // Recursive call to toggle the next device
    toggleDevice(index + 1);
}

// Function to show the status of all devices recursively
void showStatus(int index) {
    if (index >= device_count) {
        return; // Base case: Check if we've displayed all devices
    }

    printf("Device: %s, Status: %s\n", devices[index].name, devices[index].status ? "ON" : "OFF");
    // Recursive call to show status of the next device
    showStatus(index + 1);
}

// Function to display the main menu
void displayMenu() {
    printf("Smart Home Automation System\n");
    printf("1. Add Device\n");
    printf("2. Toggle Device Status\n");
    printf("3. Show Device Status\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDevice();
                break;
            case 2:
                toggleDevice(0);
                break;
            case 3:
                showStatus(0);
                break;
            case 4:
                printf("Exiting Smart Home Automation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}