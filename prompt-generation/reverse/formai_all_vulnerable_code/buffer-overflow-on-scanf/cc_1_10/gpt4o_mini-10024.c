//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define a structure to hold smart device details
typedef struct {
    char name[50];
    int isOn;
} SmartDevice;

// Function prototypes
void displayMenu();
void toggleDevice(SmartDevice *device);
void displayDeviceStatus(SmartDevice *device);
void turnOnAllDevices(SmartDevice *devices, int count);
void turnOffAllDevices(SmartDevice *devices, int count);
void setDeviceName(SmartDevice *device, const char *newName);

// Main function
int main() {
    // Creating an array of smart devices
    SmartDevice devices[3];
    
    // Initializing devices
    strcpy(devices[0].name, "Living Room Light");
    devices[0].isOn = 0;

    strcpy(devices[1].name, "Thermostat");
    devices[1].isOn = 1;

    strcpy(devices[2].name, "Smart Speaker");
    devices[2].isOn = 0;

    int choice = -1;

    while (choice != 0) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                toggleDevice(&devices[0]);
                break;
            case 2:
                toggleDevice(&devices[1]);
                break;
            case 3:
                toggleDevice(&devices[2]);
                break;
            case 4:
                turnOnAllDevices(devices, 3);
                break;
            case 5:
                turnOffAllDevices(devices, 3);
                break;
            case 6:
                {
                    char newName[50];
                    printf("Enter new name for Living Room Light: ");
                    scanf("%s", newName);
                    setDeviceName(&devices[0], newName);
                }
                break;
            case 7:
                printf("Exiting the Smart Home Automation System. Bye!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}

// Display menu options
void displayMenu() {
    printf("\n--- Smart Home Automation Menu ---\n");
    printf("1. Toggle Living Room Light\n");
    printf("2. Toggle Thermostat\n");
    printf("3. Toggle Smart Speaker\n");
    printf("4. Turn ON All Devices\n");
    printf("5. Turn OFF All Devices\n");
    printf("6. Change Living Room Light Name\n");
    printf("0. Exit\n");
}

// Toggle the device status
void toggleDevice(SmartDevice *device) {
    device->isOn = !device->isOn;
    displayDeviceStatus(device);
}

// Display the status of the device
void displayDeviceStatus(SmartDevice *device) {
    if (device->isOn) {
        printf("%s is now ON!\n", device->name);
    } else {
        printf("%s is now OFF!\n", device->name);
    }
}

// Turn on all devices
void turnOnAllDevices(SmartDevice *devices, int count) {
    for (int i = 0; i < count; i++) {
        devices[i].isOn = 1;
        printf("%s is now ON!\n", devices[i].name);
    }
}

// Turn off all devices
void turnOffAllDevices(SmartDevice *devices, int count) {
    for (int i = 0; i < count; i++) {
        devices[i].isOn = 0;
        printf("%s is now OFF!\n", devices[i].name);
    }
}

// Set new name for the device
void setDeviceName(SmartDevice *device, const char *newName) {
    strcpy(device->name, newName);
    printf("Living Room Light renamed to: %s\n", device->name);
}