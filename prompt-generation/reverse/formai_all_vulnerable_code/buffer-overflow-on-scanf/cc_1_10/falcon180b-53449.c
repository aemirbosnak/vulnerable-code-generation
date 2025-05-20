//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: Alan Turing
/* Alan Turing Smart Home Automation Example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// Define the number of devices in the smart home
#define NUM_DEVICES 5

// Define the device types and their corresponding commands
typedef enum {
    LIGHT = 0,
    FAN = 1,
    TV = 2,
    AC = 3,
    DOOR = 4
} DeviceType;

char* device_commands[NUM_DEVICES] = {
    "turn on",
    "turn off",
    "change channel",
    "set temperature",
    "open",
};

// Define the device states
typedef enum {
    OFF = 0,
    ON = 1
} DeviceState;

// Define the structure for each device
typedef struct {
    DeviceType type;
    DeviceState state;
} Device;

// Initialize the devices
void init_devices(Device* devices) {
    for (int i = 0; i < NUM_DEVICES; i++) {
        devices[i].type = (DeviceType)i;
        devices[i].state = OFF;
    }
}

// Print the current state of all devices
void print_device_states(Device* devices) {
    for (int i = 0; i < NUM_DEVICES; i++) {
        printf("Device %d (%s): %s\n", i, device_commands[i], devices[i].state == ON? "On" : "Off");
    }
}

// Parse a command and update the device state
void process_command(Device* devices, char* command) {
    int device_index = -1;
    for (int i = 0; i < NUM_DEVICES; i++) {
        if (strcmp(command, device_commands[i]) == 0) {
            device_index = i;
            break;
        }
    }

    if (device_index!= -1) {
        devices[device_index].state = (devices[device_index].state == ON)? OFF : ON;
    } else {
        printf("Invalid device command.\n");
    }
}

// Main function
int main() {
    Device devices[NUM_DEVICES];
    init_devices(devices);

    while (1) {
        printf("Enter a command (e.g. turn on light): ");
        char command[50];
        scanf("%s", command);

        process_command(devices, command);
        print_device_states(devices);
    }

    return 0;
}