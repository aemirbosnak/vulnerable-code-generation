//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_COMMANDS 50

typedef struct {
    char name[50];
    char type[50];
    char location[50];
} Device;

typedef struct {
    char command[50];
    int device_index;
} Command;

int num_devices = 0;
Device devices[MAX_DEVICES];
int num_commands = 0;
Command commands[MAX_COMMANDS];

void add_device() {
    num_devices++;
    printf("Enter device name: ");
    scanf("%s", devices[num_devices-1].name);
    printf("Enter device type: ");
    scanf("%s", devices[num_devices-1].type);
    printf("Enter device location: ");
    scanf("%s", devices[num_devices-1].location);
}

void add_command() {
    num_commands++;
    printf("Enter command: ");
    scanf("%s", commands[num_commands-1].command);
    printf("Enter device index: ");
    scanf("%d", &commands[num_commands-1].device_index);
}

void execute_command(int index) {
    if (index >= 0 && index < num_devices) {
        printf("Executing command for device %s...\n", devices[index].name);
    } else {
        printf("Invalid device index.\n");
    }
}

int main() {
    printf("Welcome to the Smart Home Automation System!\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add device\n");
        printf("2. Add command\n");
        printf("3. Execute command\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_device();
                break;
            case 2:
                add_command();
                break;
            case 3:
                printf("Enter command index: ");
                scanf("%d", &index);
                execute_command(index);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}