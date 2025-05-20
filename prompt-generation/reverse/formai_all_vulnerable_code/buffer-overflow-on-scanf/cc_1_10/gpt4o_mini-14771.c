//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

// Device structure representing a smart device in the home
typedef struct {
    char name[NAME_LENGTH];
    int status; // 0: off, 1: on
} Device;

// Function prototypes
void initializeDevices(Device devices[], int *deviceCount);
void displayMenu();
void addDevice(Device devices[], int *deviceCount);
void toggleDevice(Device devices[], int deviceCount);
void displayDevices(Device devices[], int deviceCount);
void scheduleDeviceOperation(Device devices[], int deviceCount);
void displayGratitude();

int main() {
    Device devices[MAX_DEVICES];
    int deviceCount = 0;
    int choice;

    initializeDevices(devices, &deviceCount);

    do {
        displayMenu();
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addDevice(devices, &deviceCount);
                break;
            case 2:
                toggleDevice(devices, deviceCount);
                break;
            case 3:
                displayDevices(devices, deviceCount);
                break;
            case 4:
                scheduleDeviceOperation(devices, deviceCount);
                break;
            case 5:
                displayGratitude();
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to initialize devices
void initializeDevices(Device devices[], int *deviceCount) {
    *deviceCount = 0; // Start with no devices
}

// Function to display the menu options
void displayMenu() {
    printf("\n-------------------- Smart Home Automation --------------------\n");
    printf("1. Add Device\n");
    printf("2. Toggle Device\n");
    printf("3. Display Devices\n");
    printf("4. Schedule Device Operation\n");
    printf("5. Show Gratitude\n");
    printf("6. Exit\n");
}

// Function to add a device to the smart home
void addDevice(Device devices[], int *deviceCount) {
    if (*deviceCount >= MAX_DEVICES) {
        printf("Cannot add more devices. Maximum limit reached.\n");
        return;
    }

    printf("Enter device name: ");
    scanf("%s", devices[*deviceCount].name);
    devices[*deviceCount].status = 0; // Start with device off
    (*deviceCount)++;
    printf("Device '%s' added successfully!\n", devices[*deviceCount - 1].name);
}

// Function to toggle the status of a device
void toggleDevice(Device devices[], int deviceCount) {
    int index;
    printf("Enter device number to toggle (1 to %d): ", deviceCount);
    scanf("%d", &index);
    
    if (index < 1 || index > deviceCount) {
        printf("Invalid device number! Please try again.\n");
        return;
    }

    devices[index - 1].status = !devices[index - 1].status;
    printf("Device '%s' is now %s.\n", devices[index - 1].name, devices[index - 1].status ? "ON" : "OFF");
}

// Function to display the list of devices and their statuses
void displayDevices(Device devices[], int deviceCount) {
    if (deviceCount == 0) {
        printf("No devices added yet.\n");
        return;
    }

    printf("\n--- Devices List ---\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("%d. %s - Status: %s\n", i + 1, devices[i].name, devices[i].status ? "ON" : "OFF");
    }
}

// Function to schedule a device operation
void scheduleDeviceOperation(Device devices[], int deviceCount) {
    int index;
    int duration;
  
    printf("Enter device number to schedule (1 to %d): ", deviceCount);
    scanf("%d", &index);
    
    if (index < 1 || index > deviceCount) {
        printf("Invalid device number! Please try again.\n");
        return;
    }

    printf("Enter duration in seconds for device '%s' to turn ON: ", devices[index - 1].name);
    scanf("%d", &duration);
    
    printf("Scheduling device '%s' to turn ON for %d seconds...\n", devices[index - 1].name, duration);
    devices[index - 1].status = 1; // Turn ON the device
    sleep(duration);
    devices[index - 1].status = 0; // Turn OFF the device after duration
    printf("Device '%s' is now turned OFF after %d seconds.\n", devices[index - 1].name, duration);
}

// Function to display a message of gratitude
void displayGratitude() {
    printf("\nThank you for using the Smart Home Automation Program!\n");
    printf("We appreciate your commitment to automating your home for a better life.\n");
    printf("Every device you manage brings us closer to a smarter future!\n");
}