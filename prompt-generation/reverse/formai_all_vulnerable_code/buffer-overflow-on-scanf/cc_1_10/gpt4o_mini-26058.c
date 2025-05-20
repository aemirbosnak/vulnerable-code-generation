//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef enum {
    LIGHT,
    THERMOSTAT,
    SECURITY,
    SMART_LOCK,
    DEVICE_TYPE_COUNT
} DeviceType;

typedef struct {
    char name[30];
    DeviceType type;
    int status; // 0: off, 1: on
} Device;

Device devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char *name, DeviceType type) {
    if (deviceCount < MAX_DEVICES) {
        strcpy(devices[deviceCount].name, name);
        devices[deviceCount].type = type;
        devices[deviceCount].status = 0; // Initially off
        deviceCount++;
        printf("Device '%s' added successfully.\n", name);
    } else {
        printf("Device limit reached. Cannot add new device.\n");
    }
}

void toggleDeviceStatus(int deviceIndex) {
    devices[deviceIndex].status = !devices[deviceIndex].status;
    const char *status = devices[deviceIndex].status ? "on" : "off";
    printf("Device '%s' is now %s.\n", devices[deviceIndex].name, status);
}

void displayDevices() {
    printf("\n--- Smart Home Devices ---\n");
    for (int i = 0; i < deviceCount; i++) {
        const char *status = devices[i].status ? "On" : "Off";
        printf("[%d] %s (%s): %s\n", i, devices[i].name,
               devices[i].type == LIGHT ? "Light" :
               devices[i].type == THERMOSTAT ? "Thermostat" :
               devices[i].type == SECURITY ? "Security" : "Smart Lock",
               status);
    }
    printf("--------------------------\n");
}

int main() {
    int choice;
    addDevice("Living Room Light", LIGHT);
    addDevice("Bedroom Light", LIGHT);
    addDevice("Main Thermostat", THERMOSTAT);
    addDevice("Front Door Security", SECURITY);
    addDevice("Front Door Lock", SMART_LOCK);

    while (1) {
        displayDevices();
        printf("Choose an option:\n");
        printf("1. Toggle Device Status\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int deviceIndex;
            printf("Enter device index to toggle (0-%d): ", deviceCount - 1);
            scanf("%d", &deviceIndex);
            if (deviceIndex >= 0 && deviceIndex < deviceCount) {
                toggleDeviceStatus(deviceIndex);
            } else {
                printf("Invalid device index. Please try again.\n");
            }
        } else if (choice == 2) {
            printf("Exiting Smart Home Control.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}