//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 20

typedef struct {
    char name[MAX_COMMAND_LENGTH];
    bool status;
} device_t;

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    bool status;
} command_t;

int main() {
    device_t devices[MAX_DEVICES];
    command_t commands[MAX_COMMANDS];
    int num_devices = 0, num_commands = 0;

    while (true) {
        printf("Welcome to the Smart Home Automation System\n");
        printf("1. Add Device\n");
        printf("2. Remove Device\n");
        printf("3. Turn Device On\n");
        printf("4. Turn Device Off\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter device name: ");
            scanf("%s", devices[num_devices].name);
            devices[num_devices].status = false;
            num_devices++;
            break;

        case 2:
            printf("Enter device name to remove: ");
            scanf("%s", devices[num_devices - 1].name);
            devices[num_devices - 1].status = false;
            num_devices--;
            break;

        case 3:
            printf("Enter device name to turn on: ");
            scanf("%s", devices[num_devices - 1].name);
            devices[num_devices - 1].status = true;
            break;

        case 4:
            printf("Enter device name to turn off: ");
            scanf("%s", devices[num_devices - 1].name);
            devices[num_devices - 1].status = false;
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }

        if (num_devices == 0) {
            printf("No devices added\n");
        } else {
            printf("Current status of devices:\n");
            for (int i = 0; i < num_devices; i++) {
                printf("%s: %s\n", devices[i].name, devices[i].status? "On" : "Off");
            }
        }
    }

    return 0;
}