//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// Define the smart home devices
typedef struct {
    char *name;
    bool state;
} device_t;

// Create an array of smart home devices
device_t devices[] = {
    { "Light 1", false },
    { "Light 2", false },
    { "Fan 1", false },
    { "Door 1", false },
    { "Window 1", false }
};

// Define the commands that can be used to control the devices
typedef enum {
    CMD_TURN_ON,
    CMD_TURN_OFF,
    CMD_GET_STATE,
    CMD_SET_STATE
} command_t;

// Create a function to execute a command on a device
void execute_command(device_t *device, command_t command) {
    switch (command) {
        case CMD_TURN_ON:
            device->state = true;
            printf("%s turned on\n", device->name);
            break;
        case CMD_TURN_OFF:
            device->state = false;
            printf("%s turned off\n", device->name);
            break;
        case CMD_GET_STATE:
            printf("%s is %s\n", device->name, device->state ? "on" : "off");
            break;
        case CMD_SET_STATE:
            device->state = !device->state;
            printf("%s state set to %s\n", device->name, device->state ? "on" : "off");
            break;
    }
}

// Create a function to parse a command from a string
command_t parse_command(char *str) {
    if (strcmp(str, "turn on") == 0) {
        return CMD_TURN_ON;
    } else if (strcmp(str, "turn off") == 0) {
        return CMD_TURN_OFF;
    } else if (strcmp(str, "get state") == 0) {
        return CMD_GET_STATE;
    } else if (strcmp(str, "set state") == 0) {
        return CMD_SET_STATE;
    } else {
        return -1;
    }
}

// Create a function to get the device from a string
device_t *get_device(char *str) {
    for (int i = 0; i < sizeof(devices) / sizeof(device_t); i++) {
        if (strcmp(str, devices[i].name) == 0) {
            return &devices[i];
        }
    }
    return NULL;
}

// Create a function to run the smart home automation system
void run_smart_home_automation() {
    // Get the command from the user
    char *command_str = malloc(100);
    printf("Enter a command: ");
    scanf("%s", command_str);

    // Parse the command
    command_t command = parse_command(command_str);

    // Get the device from the user
    char *device_str = malloc(100);
    printf("Enter a device: ");
    scanf("%s", device_str);

    // Get the device
    device_t *device = get_device(device_str);

    // Execute the command on the device
    execute_command(device, command);

    // Free the memory allocated for the command and device strings
    free(command_str);
    free(device_str);
}

// Main function
int main() {
    // Run the smart home automation system
    run_smart_home_automation();

    return 0;
}