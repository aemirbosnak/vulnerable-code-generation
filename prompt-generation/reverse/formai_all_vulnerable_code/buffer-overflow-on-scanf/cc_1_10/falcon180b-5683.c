//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 10
#define MAX_DEVICES 20

struct device {
    char name[30];
    char type[20];
    char status;
};

struct command {
    char action[20];
    char target[30];
};

void execute_command(struct command cmd, struct device devices[]) {
    int i = 0;
    while (i < MAX_DEVICES) {
        if (strcmp(devices[i].name, cmd.target) == 0) {
            if (strcmp(cmd.action, "on") == 0) {
                devices[i].status = 1;
                printf("Turning on %s\n", cmd.target);
            } else if (strcmp(cmd.action, "off") == 0) {
                devices[i].status = 0;
                printf("Turning off %s\n", cmd.target);
            } else if (strcmp(cmd.action, "status") == 0) {
                printf("The status of %s is: %d\n", cmd.target, devices[i].status);
            } else {
                printf("Invalid action for %s\n", cmd.target);
            }
            break;
        }
        i++;
    }
}

int main() {
    int num_devices = 0;
    struct device devices[MAX_DEVICES];
    struct command commands[MAX_COMMANDS];

    printf("Enter the number of devices: ");
    scanf("%d", &num_devices);

    for (int i = 0; i < num_devices; i++) {
        printf("Enter device name: ");
        scanf("%s", devices[i].name);
        printf("Enter device type: ");
        scanf("%s", devices[i].type);
        printf("Enter device status (0 or 1): ");
        scanf("%d", &devices[i].status);
    }

    int num_commands = 0;
    printf("Enter the number of commands: ");
    scanf("%d", &num_commands);

    for (int i = 0; i < num_commands; i++) {
        printf("Enter command action: ");
        scanf("%s", commands[i].action);
        printf("Enter command target: ");
        scanf("%s", commands[i].target);
    }

    for (int i = 0; i < num_commands; i++) {
        execute_command(commands[i], devices);
    }

    return 0;
}