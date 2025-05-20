//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the smart home devices
typedef struct {
    char *name;
    int state; // 0 for off, 1 for on
} device;

// Create an array of devices
device devices[] = {
    { "Light 1", 0 },
    { "Light 2", 0 },
    { "Fan", 0 },
    { "TV", 0 },
    { "AC", 0 }
};

// Get the number of devices
int num_devices = sizeof(devices) / sizeof(devices[0]);

// Define the commands
typedef enum {
    CMD_ON,
    CMD_OFF,
    CMD_TOGGLE,
    CMD_LIST,
    CMD_HELP,
    CMD_EXIT
} command;

// Get the command from the user
command get_command() {
    char input[10];
    printf("Enter a command (on, off, toggle, list, help, exit): ");
    scanf("%s", input);

    if (strcmp(input, "on") == 0) {
        return CMD_ON;
    } else if (strcmp(input, "off") == 0) {
        return CMD_OFF;
    } else if (strcmp(input, "toggle") == 0) {
        return CMD_TOGGLE;
    } else if (strcmp(input, "list") == 0) {
        return CMD_LIST;
    } else if (strcmp(input, "help") == 0) {
        return CMD_HELP;
    } else if (strcmp(input, "exit") == 0) {
        return CMD_EXIT;
    } else {
        printf("Invalid command\n");
        return -1;
    }
}

// Execute the command
void execute_command(command cmd) {
    switch (cmd) {
        case CMD_ON:
            printf("Which device do you want to turn on? ");
            char device_name[20];
            scanf("%s", device_name);

            for (int i = 0; i < num_devices; i++) {
                if (strcmp(devices[i].name, device_name) == 0) {
                    devices[i].state = 1;
                    printf("%s turned on\n", device_name);
                    break;
                }
            }

            break;

        case CMD_OFF:
            printf("Which device do you want to turn off? ");
            scanf("%s", device_name);

            for (int i = 0; i < num_devices; i++) {
                if (strcmp(devices[i].name, device_name) == 0) {
                    devices[i].state = 0;
                    printf("%s turned off\n", device_name);
                    break;
                }
            }

            break;

        case CMD_TOGGLE:
            printf("Which device do you want to toggle? ");
            scanf("%s", device_name);

            for (int i = 0; i < num_devices; i++) {
                if (strcmp(devices[i].name, device_name) == 0) {
                    devices[i].state = !devices[i].state;
                    printf("%s toggled\n", device_name);
                    break;
                }
            }

            break;

        case CMD_LIST:
            printf("List of devices:\n");
            for (int i = 0; i < num_devices; i++) {
                printf("%s: %s\n", devices[i].name, devices[i].state ? "on" : "off");
            }

            break;

        case CMD_HELP:
            printf("Commands:\n");
            printf("  on: Turn on a device\n");
            printf("  off: Turn off a device\n");
            printf("  toggle: Toggle a device\n");
            printf("  list: List all devices\n");
            printf("  help: Display this help message\n");
            printf("  exit: Exit the program\n");

            break;

        case CMD_EXIT:
            exit(0);

            break;

        default:
            printf("Invalid command\n");
            break;
    }
}

// Main function
int main() {
    while (1) {
        command cmd = get_command();
        execute_command(cmd);
    }

    return 0;
}