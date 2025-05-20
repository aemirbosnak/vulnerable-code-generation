//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_DEVICE_NUM 10
#define MAX_COMMAND_LENGTH 20
#define MAX_DEVICE_NAME_LENGTH 20

typedef struct {
    char name[MAX_DEVICE_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
} device_t;

device_t devices[MAX_DEVICE_NUM];

void add_device(char *name, char *command) {
    int i;
    for (i = 0; i < MAX_DEVICE_NUM; i++) {
        if (devices[i].name[0] == 0) {
            strcpy(devices[i].name, name);
            strcpy(devices[i].command, command);
            return;
        }
    }
    printf("Error: Maximum number of devices reached.\n");
}

void remove_device(char *name) {
    int i;
    for (i = 0; i < MAX_DEVICE_NUM; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            memset(devices[i].name, 0, MAX_DEVICE_NAME_LENGTH);
            memset(devices[i].command, 0, MAX_COMMAND_LENGTH);
            return;
        }
    }
    printf("Error: Device not found.\n");
}

void list_devices() {
    int i;
    for (i = 0; i < MAX_DEVICE_NUM; i++) {
        if (devices[i].name[0]!= 0) {
            printf("%s: %s\n", devices[i].name, devices[i].command);
        }
    }
}

void execute_command(char *command) {
    system(command);
}

int main() {
    int choice;
    char name[MAX_DEVICE_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Add device\n");
        printf("2. Remove device\n");
        printf("3. List devices\n");
        printf("4. Execute command\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", name);
                printf("Enter command: ");
                scanf("%s", command);
                add_device(name, command);
                break;
            case 2:
                printf("Enter device name: ");
                scanf("%s", name);
                remove_device(name);
                break;
            case 3:
                list_devices();
                break;
            case 4:
                printf("Enter command: ");
                scanf("%s", command);
                execute_command(command);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}