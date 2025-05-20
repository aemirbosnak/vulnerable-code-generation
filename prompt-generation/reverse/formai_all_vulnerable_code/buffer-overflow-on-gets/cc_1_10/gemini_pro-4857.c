//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumerations for device types and states
typedef enum { LIGHT, FAN, AC, TV } device_type;
typedef enum { ON, OFF } device_state;

// Structure to represent a smart home device
typedef struct {
    device_type type;
    char *name;
    device_state state;
} device;

// Array of devices
device devices[] = {
    { LIGHT, "Bedroom Light", OFF },
    { FAN, "Living Room Fan", OFF },
    { AC, "Master Bedroom AC", OFF },
    { TV, "Family Room TV", OFF }
};

// Function to turn a device on
void turn_on(device *d) {
    d->state = ON;
    printf("%s turned on.\n", d->name);
}

// Function to turn a device off
void turn_off(device *d) {
    d->state = OFF;
    printf("%s turned off.\n", d->name);
}

// Function to print the status of a device
void print_status(device *d) {
    printf("%s is %s.\n", d->name, d->state == ON ? "on" : "off");
}

// Main function
int main() {
    // Get the user's input
    char input[256];
    printf("Enter a command: ");
    gets(input);

    // Parse the input
    char *command = strtok(input, " ");
    char *device_name = strtok(NULL, " ");

    // Find the device by name
    device *d = NULL;
    for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
        if (strcmp(devices[i].name, device_name) == 0) {
            d = &devices[i];
            break;
        }
    }

    // If the device was found, execute the command
    if (d != NULL) {
        if (strcmp(command, "on") == 0) {
            turn_on(d);
        } else if (strcmp(command, "off") == 0) {
            turn_off(d);
        } else if (strcmp(command, "status") == 0) {
            print_status(d);
        } else {
            printf("Invalid command.\n");
        }
    } else {
        printf("Device not found.\n");
    }

    return 0;
}