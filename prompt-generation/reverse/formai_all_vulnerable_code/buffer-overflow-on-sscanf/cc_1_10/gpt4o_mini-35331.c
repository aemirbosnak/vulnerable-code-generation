//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

// Smart Home Device Structure
typedef struct {
    char name[30];
    bool is_on;
} SmartDevice;

// Function Prototypes
void toggleDevice(SmartDevice *device);
void displayDevices(SmartDevice devices[], int num_devices);
void commandLoop(SmartDevice devices[], int num_devices);

int main() {
    // Initialize smart devices
    SmartDevice devices[3] = {
        {"Living Room Light", false},
        {"Thermostat", false},
        {"Security Camera", false}
    };

    // Start the command loop
    commandLoop(devices, 3);
    
    return 0;
}

// Function to toggle the state of a smart device
void toggleDevice(SmartDevice *device) {
    device->is_on = !device->is_on;
    const char *status = device->is_on ? "ON" : "OFF";
    printf("%s is now %s.\n", device->name, status);
}

// Function to display the status of all devices
void displayDevices(SmartDevice devices[], int num_devices) {
    printf("\nCurrent Device Status:\n");
    for (int i = 0; i < num_devices; i++) {
        const char *status = devices[i].is_on ? "ON" : "OFF";
        printf("%s: %s\n", devices[i].name, status);
    }
    printf("-------------------------\n");
}

// Function to handle user commands
void commandLoop(SmartDevice devices[], int num_devices) {
    char command[10];
    int device_number;
    
    printf("Welcome to Smart Home Automation System!\n");
    
    while (true) {
        displayDevices(devices, num_devices);
        printf("Enter command (toggle <device_number>, exit): ");
        
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove the trailing newline

        if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Automation System. Goodbye!\n");
            break;
        } else if (sscanf(command, "toggle %d", &device_number) == 1) {
            if (device_number >= 0 && device_number < num_devices) {
                toggleDevice(&devices[device_number]);
            } else {
                printf("Invalid device number. Please try again.\n");
            }
        } else {
            printf("Invalid command. Please enter a valid command.\n");
        }
    }
}