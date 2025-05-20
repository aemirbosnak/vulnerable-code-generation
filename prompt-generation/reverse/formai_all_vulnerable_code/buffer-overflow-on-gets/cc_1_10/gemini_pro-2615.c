//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of devices
#define MAX_DEVICES 10

// Define the device types
typedef enum {
    DEVICE_TYPE_LIGHT,
    DEVICE_TYPE_FAN,
    DEVICE_TYPE_THERMOSTAT
} device_type;

// Define the device states
typedef enum {
    DEVICE_STATE_ON,
    DEVICE_STATE_OFF
} device_state;

// Define the device structure
typedef struct {
    char *name;
    device_type type;
    device_state state;
} device;

// Create an array of devices
device devices[MAX_DEVICES];

// Initialize the devices
void init_devices() {
    // Light devices
    strcpy(devices[0].name, "Living Room Light");
    devices[0].type = DEVICE_TYPE_LIGHT;
    devices[0].state = DEVICE_STATE_OFF;

    strcpy(devices[1].name, "Bedroom Light");
    devices[1].type = DEVICE_TYPE_LIGHT;
    devices[1].state = DEVICE_STATE_OFF;

    // Fan devices
    strcpy(devices[2].name, "Living Room Fan");
    devices[2].type = DEVICE_TYPE_FAN;
    devices[2].state = DEVICE_STATE_OFF;

    strcpy(devices[3].name, "Bedroom Fan");
    devices[3].type = DEVICE_TYPE_FAN;
    devices[3].state = DEVICE_STATE_OFF;

    // Thermostat devices
    strcpy(devices[4].name, "Living Room Thermostat");
    devices[4].type = DEVICE_TYPE_THERMOSTAT;
    devices[4].state = DEVICE_STATE_OFF;

    strcpy(devices[5].name, "Bedroom Thermostat");
    devices[5].type = DEVICE_TYPE_THERMOSTAT;
    devices[5].state = DEVICE_STATE_OFF;
}

// Get the device by name
device *get_device_by_name(char *name) {
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            return &devices[i];
        }
    }

    return NULL;
}

// Turn a device on
void turn_on_device(device *device) {
    device->state = DEVICE_STATE_ON;
}

// Turn a device off
void turn_off_device(device *device) {
    device->state = DEVICE_STATE_OFF;
}

// Toggle a device
void toggle_device(device *device) {
    device->state = (device->state == DEVICE_STATE_ON) ? DEVICE_STATE_OFF : DEVICE_STATE_ON;
}

// Print the device status
void print_device_status(device *device) {
    printf("%s is %s\n", device->name, (device->state == DEVICE_STATE_ON) ? "on" : "off");
}

// Main function
int main() {
    // Initialize the devices
    init_devices();

    // Get the command from the user
    char command[100];
    printf("Enter a command: ");
    gets(command);

    // Parse the command
    char *device_name = strtok(command, " ");
    char *action = strtok(NULL, " ");

    // Get the device
    device *device = get_device_by_name(device_name);

    if (device == NULL) {
        printf("Device not found\n");
        return 1;
    }

    // Perform the action
    if (strcmp(action, "on") == 0) {
        turn_on_device(device);
    } else if (strcmp(action, "off") == 0) {
        turn_off_device(device);
    } else if (strcmp(action, "toggle") == 0) {
        toggle_device(device);
    } else {
        printf("Invalid action\n");
        return 1;
    }

    // Print the device status
    print_device_status(device);

    return 0;
}