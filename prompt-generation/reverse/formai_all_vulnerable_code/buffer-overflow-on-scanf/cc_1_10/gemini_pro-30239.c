//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the smart home devices
typedef enum {
    LIGHT,
    FAN,
    AC,
    TV
} device_type;

struct device {
    device_type type;
    char *name;
    bool is_on;
};

// Create a list of smart home devices
struct device devices[] = {
    { LIGHT, "Bedroom Light", false },
    { FAN, "Living Room Fan", false },
    { AC, "Master Bedroom AC", false },
    { TV, "Family Room TV", false }
};

// Define the smart home commands
typedef enum {
    TURN_ON,
    TURN_OFF,
    GET_STATUS
} command_type;

struct command {
    command_type type;
    device_type device;
};

// Function to turn on a device
void turn_on(struct device *device) {
    device->is_on = true;
    printf("Turning on %s\n", device->name);
}

// Function to turn off a device
void turn_off(struct device *device) {
    device->is_on = false;
    printf("Turning off %s\n", device->name);
}

// Function to get the status of a device
void get_status(struct device *device) {
    printf("%s is %s\n", device->name, device->is_on ? "on" : "off");
}

// Main function
int main() {
    // Get the user's command
    struct command command;
    printf("Enter a command (turn on/off/get status): ");
    scanf("%s %s", &command.type, &command.device);

    // Execute the command
    switch (command.type) {
        case TURN_ON:
            for (int i = 0; i < sizeof(devices) / sizeof(struct device); i++) {
                if (devices[i].type == command.device) {
                    turn_on(&devices[i]);
                    break;
                }
            }
            break;
        case TURN_OFF:
            for (int i = 0; i < sizeof(devices) / sizeof(struct device); i++) {
                if (devices[i].type == command.device) {
                    turn_off(&devices[i]);
                    break;
                }
            }
            break;
        case GET_STATUS:
            for (int i = 0; i < sizeof(devices) / sizeof(struct device); i++) {
                if (devices[i].type == command.device) {
                    get_status(&devices[i]);
                    break;
                }
            }
            break;
    }

    return 0;
}