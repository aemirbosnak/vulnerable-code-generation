//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int status; // 0: off, 1: on
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char* name) {
    if (device_count < MAX_DEVICES) {
        strncpy(devices[device_count].name, name, NAME_LENGTH - 1);
        devices[device_count].name[NAME_LENGTH - 1] = '\0';
        devices[device_count].status = 0; // Initially off
        device_count++;
        printf("Device '%s' added.\n", name);
    } else {
        printf("Device limit reached. Can't add '%s'.\n", name);
    }
}

void toggle_device(const char* name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].status = !devices[i].status;
            printf("Device '%s' is now %s.\n", devices[i].name, devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void status_report() {
    printf("Smart Home Status Report:\n");
    for (int i = 0; i < device_count; i++) {
        printf(" - %s: %s\n", devices[i].name, devices[i].status ? "ON" : "OFF");
    }
}

void prompt_user() {
    printf("Commands:\n");
    printf(" 1. add <device_name> - Adds a new device\n");
    printf(" 2. toggle <device_name> - Toggles device status\n");
    printf(" 3. status - Displays status of all devices\n");
    printf(" 4. exit - Exits the program\n");
    printf("Enter command: ");
}

int main() {
    char command[100];
    char device_name[NAME_LENGTH];

    printf("Welcome to the Smart Home Automation System!\n");

    while (1) {
        prompt_user();
        fgets(command, sizeof(command), stdin);
        
        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "add ", 4) == 0) {
            sscanf(command + 4, "%s", device_name);
            add_device(device_name);
        } else if (strncmp(command, "toggle ", 7) == 0) {
            sscanf(command + 7, "%s", device_name);
            toggle_device(device_name);
        } else if (strcmp(command, "status") == 0) {
            status_report();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Automation System. Goodbye!\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
        usleep(500000); // to prevent rapid command processing
    }

    return 0;
}