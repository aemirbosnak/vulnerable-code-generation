//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the smart home devices
typedef struct {
    char *name;
    int state; // 0 = off, 1 = on
} device;

device devices[] = {
    { "Light 1", 0 },
    { "Light 2", 0 },
    { "Fan", 0 },
    { "AC", 0 },
    { "TV", 0 }
};

// Define the commands
typedef enum {
    CMD_ON,
    CMD_OFF,
    CMD_TOGGLE,
    CMD_LIST,
    CMD_EXIT
} command;

// Get the command from the user
command get_command() {
    char input[10];
    printf("Enter a command (on, off, toggle, list, exit): ");
    scanf("%s", input);

    if (strcmp(input, "on") == 0) {
        return CMD_ON;
    } else if (strcmp(input, "off") == 0) {
        return CMD_OFF;
    } else if (strcmp(input, "toggle") == 0) {
        return CMD_TOGGLE;
    } else if (strcmp(input, "list") == 0) {
        return CMD_LIST;
    } else if (strcmp(input, "exit") == 0) {
        return CMD_EXIT;
    } else {
        printf("Invalid command\n");
        return get_command();
    }
}

// Get the device from the user
device *get_device() {
    char input[20];
    printf("Enter the name of the device: ");
    scanf("%s", input);

    for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
        if (strcmp(input, devices[i].name) == 0) {
            return &devices[i];
        }
    }

    printf("Device not found\n");
    return get_device();
}

// Execute the command
void execute_command(command cmd, device *device) {
    switch (cmd) {
        case CMD_ON:
            device->state = 1;
            printf("%s turned on\n", device->name);
            break;
        case CMD_OFF:
            device->state = 0;
            printf("%s turned off\n", device->name);
            break;
        case CMD_TOGGLE:
            device->state = !device->state;
            printf("%s %s\n", device->name, device->state ? "turned on" : "turned off");
            break;
        case CMD_LIST:
            for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
                printf("%s: %s\n", devices[i].name, devices[i].state ? "on" : "off");
            }
            break;
        case CMD_EXIT:
            exit(0);
    }
}

// Main function
int main() {
    while (1) {
        command cmd = get_command();
        device *device = get_device();
        execute_command(cmd, device);
    }

    return 0;
}