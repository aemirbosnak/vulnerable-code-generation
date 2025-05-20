//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the smart home devices
typedef struct {
    char *name;
    int state; // 0 = off, 1 = on
} device;

device devices[] = {
    { "light", 0 },
    { "fan", 0 },
    { "tv", 0 },
    { "ac", 0 }
};

// Define the commands
typedef enum {
    CMD_ON,
    CMD_OFF,
    CMD_TOGGLE,
    CMD_LIST,
    CMD_HELP
} command;

// Define the command strings
char *commands[] = {
    "on",
    "off",
    "toggle",
    "list",
    "help"
};

// Parse the command
command parse_command(char *cmd) {
    for (int i = 0; i < sizeof(commands) / sizeof(char *); i++) {
        if (strcmp(cmd, commands[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Print the help message
void print_help() {
    printf("Smart Home Automation Commands:\n");
    for (int i = 0; i < sizeof(commands) / sizeof(char *); i++) {
        printf("%s\n", commands[i]);
    }
}

// Execute the command
void execute_command(command cmd, char *arg) {
    if (cmd == CMD_ON) {
        for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
            if (strcmp(devices[i].name, arg) == 0) {
                devices[i].state = 1;
                printf("%s turned on\n", devices[i].name);
            }
        }
    } else if (cmd == CMD_OFF) {
        for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
            if (strcmp(devices[i].name, arg) == 0) {
                devices[i].state = 0;
                printf("%s turned off\n", devices[i].name);
            }
        }
    } else if (cmd == CMD_TOGGLE) {
        for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
            if (strcmp(devices[i].name, arg) == 0) {
                devices[i].state = !devices[i].state;
                printf("%s %s\n", devices[i].name, devices[i].state ? "turned on" : "turned off");
            }
        }
    } else if (cmd == CMD_LIST) {
        for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
            printf("%s %s\n", devices[i].name, devices[i].state ? "on" : "off");
        }
    } else if (cmd == CMD_HELP) {
        print_help();
    } else {
        printf("Invalid command\n");
    }
}

// Main function
int main() {
    char cmd[100];
    char arg[100];

    while (1) {
        printf("> ");
        scanf("%s %s", cmd, arg);

        command parsed_cmd = parse_command(cmd);

        if (parsed_cmd == -1) {
            printf("Invalid command\n");
        } else {
            execute_command(parsed_cmd, arg);
        }
    }

    return 0;
}