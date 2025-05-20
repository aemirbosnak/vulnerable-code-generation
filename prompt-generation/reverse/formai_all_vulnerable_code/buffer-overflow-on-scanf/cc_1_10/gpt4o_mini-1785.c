//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef enum {
    OFF,
    ON
} DeviceState;

typedef struct {
    char name[50];
    DeviceState state;
} Device;

void initialize_devices(Device devices[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(devices[i].name, sizeof(devices[i].name), "Device %d", i + 1);
        devices[i].state = OFF;
    }
}

void display_devices(Device devices[], int count) {
    printf("\nSmart Home Devices:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", devices[i].name, devices[i].state == ON ? "ON" : "OFF");
    }
}

void toggle_device(Device *device) {
    device->state = (device->state == ON) ? OFF : ON;
    printf("%s is now %s!\n", device->name, device->state == ON ? "ON" : "OFF");
}

int main() {
    Device devices[MAX_DEVICES];
    int device_count, choice;

    printf("Welcome to Your Smart Home Automation System!\n");
    printf("How many devices would you like to manage? (Max %d): ", MAX_DEVICES);
    scanf("%d", &device_count);

    if (device_count > MAX_DEVICES || device_count <= 0) {
        printf("Please select a valid number of devices!\n");
        return 1;
    }

    // Step 1: Initialize devices
    initialize_devices(devices, device_count);

    while (1) {
        // Step 2: Display devices
        display_devices(devices, device_count);
        
        printf("\nWhat would you like to do?\n");
        printf("1. Toggle Device\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int device_id;
                printf("Which device would you like to toggle? (1 to %d): ", device_count);
                scanf("%d", &device_id);
                
                if (device_id < 1 || device_id > device_count) {
                    printf("Invalid device number!\n");
                } else {
                    toggle_device(&devices[device_id - 1]);
                }
                break;
            }
            case 2: {
                printf("Exiting the Smart Home Automation System. Goodbye!\n");
                return 0;
            }
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}