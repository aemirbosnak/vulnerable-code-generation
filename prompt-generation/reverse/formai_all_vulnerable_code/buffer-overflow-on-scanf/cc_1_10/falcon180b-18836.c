//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_SIZE 50
#define MAX_DEVICE_NAME_SIZE 20

typedef struct {
    char *name;
    char *command;
} Device;

int num_devices = 0;
Device devices[MAX_COMMANDS];

void add_device(char *name, char *command) {
    if (num_devices >= MAX_COMMANDS) {
        printf("Error: Maximum number of devices reached.\n");
        return;
    }

    devices[num_devices].name = strdup(name);
    devices[num_devices].command = strdup(command);

    num_devices++;
}

int execute_command(char *command) {
    int i;
    for (i = 0; i < num_devices; i++) {
        if (strcmp(command, devices[i].command) == 0) {
            system(devices[i].command);
            return 1;
        }
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_SIZE];
    char device_name[MAX_DEVICE_NAME_SIZE];
    int i;

    printf("Welcome to the Smart Home Automation System!\n");

    while (1) {
        printf("Enter a device name: ");
        scanf("%s", device_name);

        printf("Enter a command for '%s': ", device_name);
        scanf("%s", input);

        add_device(device_name, input);
    }

    return 0;
}