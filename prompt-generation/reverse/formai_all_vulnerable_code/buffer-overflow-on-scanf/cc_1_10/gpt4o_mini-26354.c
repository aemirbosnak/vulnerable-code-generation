//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define device structure
typedef struct {
    char name[20];
    int status; // 0: OFF, 1: ON
} Device;

// Function to initialize the devices
void initializeDevices(Device devices[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("Enter device name: ");
        scanf("%s", devices[i].name);
        devices[i].status = 0; // Initialize all devices to OFF
    }
}

// Function to display the status of devices
void displayDevices(Device devices[], int size) {
    printf("\n--- Device Status ---\n");
    for (int i = 0; i < size; ++i) {
        printf("Device: %s, Status: %s\n", devices[i].name, devices[i].status ? "ON" : "OFF");
    }
}

// Function to turn a device ON or OFF
void toggleDevice(Device *device) {
    device->status = !device->status; // Switches between 0 and 1
    printf("%s is now %s\n", device->name, device->status ? "ON" : "OFF");
}

// Function to simulate automation feature
void autoControl(Device devices[], int size) {
    printf("\n--- Auto Control Starting ---\n");
    for (int i = 0; i < size; ++i) {
        if (strcmp(devices[i].name, "Light") == 0) {
            toggleDevice(&devices[i]); // Turn ON lights
            sleep(2); // Keep Light ON for 2 seconds
            toggleDevice(&devices[i]); // Turn OFF lights
        } else if (strcmp(devices[i].name, "Heater") == 0) {
            toggleDevice(&devices[i]); // Turn ON heater
            sleep(3); // Keep Heater ON for 3 seconds
            toggleDevice(&devices[i]); // Turn OFF heater
        }
    }
}

// Main function to run the program
int main() {
    int numDevices;

    printf("Welcome to Smart Home Automation!\n");
    printf("How many devices do you want to control? ");
    scanf("%d", &numDevices);

    // Dynamically allocate memory for devices
    Device *devices = (Device *)malloc(numDevices * sizeof(Device));
    if (devices == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initializeDevices(devices, numDevices);
    displayDevices(devices, numDevices);

    char command[10];

    while (1) {
        printf("\nEnter command (toggle <device_name> | auto | exit): ");
        scanf("%s", command);

        if (strncmp(command, "toggle", 6) == 0) {
            char deviceName[20];
            sscanf(command + 7, "%s", deviceName);
            int found = 0;

            for (int i = 0; i < numDevices; ++i) {
                if (strcmp(devices[i].name, deviceName) == 0) {
                    toggleDevice(&devices[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Device %s not found!\n", deviceName);
            }
        } else if (strcmp(command, "auto") == 0) {
            autoControl(devices, numDevices);
        } else if (strcmp(command, "exit") == 0) {
            break; // Exit loop
        } else {
            printf("Unknown command!\n");
        }
    }

    free(devices); // Free allocated memory
    printf("Exiting Smart Home Automation. Goodbye!\n");
    return 0;
}