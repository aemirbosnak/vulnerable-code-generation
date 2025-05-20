//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // For sleep()
#include <time.h>

// Define the structure for a smart device
typedef struct {
    char name[50];
    int is_on;  // 1 for ON, 0 for OFF
} SmartDevice;

// Function prototypes
void initializeDevices(SmartDevice* devices, int num_devices);
void printDeviceStatus(SmartDevice* devices, int num_devices);
void toggleDevice(SmartDevice* devices, int num_devices, const char* device_name);
void scheduleDevice(SmartDevice* devices, int num_devices, const char* device_name, int time_in_seconds);

int main() {
    const int num_devices = 5;
    SmartDevice devices[num_devices];

    // Initialize devices
    initializeDevices(devices, num_devices);

    // Main control loop
    while (1) {
        printf("\n=== Smart Home Automation ===\n");
        printDeviceStatus(devices, num_devices);

        printf("\nEnter command (toggle/schedule/exit): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "toggle") == 0) {
            char device_name[50];
            printf("Enter device name to toggle: ");
            scanf("%s", device_name);
            toggleDevice(devices, num_devices, device_name);
        } else if (strcmp(command, "schedule") == 0) {
            char device_name[50];
            int time_in_seconds;
            printf("Enter device name to schedule: ");
            scanf("%s", device_name);
            printf("Enter time in seconds after which to turn ON: ");
            scanf("%d", &time_in_seconds);
            scheduleDevice(devices, num_devices, device_name, time_in_seconds);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Automation.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}

// Function to initialize devices with default status
void initializeDevices(SmartDevice* devices, int num_devices) {
    for (int i = 0; i < num_devices; i++) {
        sprintf(devices[i].name, "Device%d", i + 1);
        devices[i].is_on = 0;  // All devices start as OFF
    }
}

// Function to print the status of all devices
void printDeviceStatus(SmartDevice* devices, int num_devices) {
    for (int i = 0; i < num_devices; i++) {
        printf("%s is currently %s\n", devices[i].name, devices[i].is_on ? "ON" : "OFF");
    }
}

// Function to toggle the state of a specific device
void toggleDevice(SmartDevice* devices, int num_devices, const char* device_name) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, device_name) == 0) {
            devices[i].is_on = !devices[i].is_on;  // Toggle the state
            printf("%s has been turned %s\n", devices[i].name, devices[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Device not found!\n");
}

// Function to schedule a device to turn ON after a specified time
void scheduleDevice(SmartDevice* devices, int num_devices, const char* device_name, int time_in_seconds) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, device_name) == 0) {
            printf("Scheduling %s to turn ON in %d seconds...\n", devices[i].name, time_in_seconds);
            sleep(time_in_seconds);
            devices[i].is_on = 1;  // Turn ON the device
            printf("%s is now ON\n", devices[i].name);
            return;
        }
    }
    printf("Device not found!\n");
}