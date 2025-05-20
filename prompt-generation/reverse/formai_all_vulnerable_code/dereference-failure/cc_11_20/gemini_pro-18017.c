//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the smart home devices
#define NUM_DEVICES 4
typedef enum {
    LIGHT,
    FAN,
    DOOR,
    AC
} device_type;

struct device {
    device_type type;
    char *name;
    int state; // 0 for off, 1 for on
};

struct device devices[NUM_DEVICES] = {
    {LIGHT, "Living Room Light", 1},
    {FAN, "Bedroom Fan", 0},
    {DOOR, "Front Door", 0},
    {AC, "Central AC", 0}
};

// Define the commands that can be sent to the smart home devices
#define NUM_COMMANDS 5
typedef enum {
    TURN_ON,
    TURN_OFF,
    SET_TEMPERATURE,
    SET_FAN_SPEED,
    GET_STATE
} command_type;

struct command {
    command_type type;
    char *device_name;
    int value; // for SET_TEMPERATURE and SET_FAN_SPEED commands
};

// Function to execute a command on a smart home device
int execute_command(struct command *command) {
    // Find the device by name
    struct device *device = NULL;
    for (int i = 0; i < NUM_DEVICES; i++) {
        if (strcmp(devices[i].name, command->device_name) == 0) {
            device = &devices[i];
            break;
        }
    }

    // If the device was not found, return an error
    if (device == NULL) {
        return -1;
    }

    // Execute the command on the device
    switch (command->type) {
    case TURN_ON:
        device->state = 1;
        printf("%s turned on\n", device->name);
        break;
    case TURN_OFF:
        device->state = 0;
        printf("%s turned off\n", device->name);
        break;
    case SET_TEMPERATURE:
        if (device->type != AC) {
            return -1;
        }
        device->state = command->value;
        printf("AC temperature set to %d degrees Fahrenheit\n", device->state);
        break;
    case SET_FAN_SPEED:
        if (device->type != FAN) {
            return -1;
        }
        device->state = command->value;
        printf("Fan speed set to %d%%", device->state);
        break;
    case GET_STATE:
        printf("%s is %s\n", device->name, device->state ? "on" : "off");
        break;
    }

    return 0;
}

// Main function
int main() {
    // Create a command buffer
    char buffer[100];

    // Read commands from the user until they enter "exit"
    while (1) {
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        // Parse the command
        struct command command;
        char *args[3];
        int num_args = sscanf(buffer, "%s %s %d", args[0], args[1], &args[2]);

        // Set the command type
        if (strcmp(args[0], "turn_on") == 0) {
            command.type = TURN_ON;
        } else if (strcmp(args[0], "turn_off") == 0) {
            command.type = TURN_OFF;
        } else if (strcmp(args[0], "set_temperature") == 0 && num_args == 3) {
            command.type = SET_TEMPERATURE;
        } else if (strcmp(args[0], "set_fan_speed") == 0 && num_args == 3) {
            command.type = SET_FAN_SPEED;
        } else if (strcmp(args[0], "get_state") == 0) {
            command.type = GET_STATE;
        } else {
            printf("Invalid command\n");
            continue;
        }

        // Set the device name
        command.device_name = args[1];

        // Set the value for SET_TEMPERATURE and SET_FAN_SPEED commands
        if (command.type == SET_TEMPERATURE || command.type == SET_FAN_SPEED) {
            command.value = atoi(args[2]);
        }

        // Execute the command
        int result = execute_command(&command);
        if (result != 0) {
            printf("Error executing command\n");
        }
    }

    return 0;
}