//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 5

typedef enum {
    OFF,
    ON
} DeviceState;

typedef struct {
    char name[20];
    DeviceState state;
} Device;

void initializeDevices(Device devices[]) {
    strcpy(devices[0].name, "Living Room Light");
    devices[0].state = OFF;

    strcpy(devices[1].name, "Bedroom Light");
    devices[1].state = OFF;

    strcpy(devices[2].name, "Thermostat");
    devices[2].state = OFF;

    strcpy(devices[3].name, "Security Alarm");
    devices[3].state = OFF;

    strcpy(devices[4].name, "Kitchen Light");
    devices[4].state = OFF;
}

void displayDevices(Device devices[]) {
    printf("\nCurrent Device States:\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        printf("%d. %s: %s\n", i + 1, devices[i].name, devices[i].state == ON ? "ON" : "OFF");
    }
}

void toggleDevice(Device *device) {
    device->state = (device->state == OFF) ? ON : OFF;
    printf("%s is now %s\n", device->name, device->state == ON ? "ON" : "OFF");
}

void controlDevice(Device devices[]) {
    int choice;
    printf("Enter the device number to toggle (1 to %d) or 0 to return to the main menu: ", MAX_DEVICES);
    scanf("%d", &choice);
    
    if (choice >= 1 && choice <= MAX_DEVICES) {
        toggleDevice(&devices[choice - 1]);
    } else if (choice != 0) {
        printf("Invalid choice. Please try again.\n");
    }
}

void displayMenu() {
    printf("\nSmart Home Automation System\n");
    printf("1. Display Device States\n");
    printf("2. Control a Device\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Device devices[MAX_DEVICES];
    initializeDevices(devices);
    
    while (1) {
        displayMenu();
        
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                displayDevices(devices);
                break;
            case 2:
                controlDevice(devices);
                break;
            case 3:
                printf("Exiting the Smart Home Automation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please select 1, 2, or 3.\n");
        }
    }
    
    return 0;
}