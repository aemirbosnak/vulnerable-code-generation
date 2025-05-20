//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    bool is_on;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char* name) {
    if (device_count >= MAX_DEVICES) {
        printf("Device limit reached!\n");
        return;
    }
    strncpy(devices[device_count].name, name, MAX_NAME_LENGTH);
    devices[device_count].is_on = false;
    device_count++;
    printf("Device '%s' added.\n", name);
}

void toggle_device(const char* name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].is_on = !devices[i].is_on;
            printf("Device '%s' is now %s.\n", name, devices[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void show_devices() {
    if (device_count == 0) {
        printf("No devices found.\n");
        return;
    }
    printf("Smart Home Devices:\n");
    for (int i = 0; i < device_count; i++) {
        printf(" - %s: %s\n", devices[i].name, devices[i].is_on ? "ON" : "OFF");
    }
}

void control_interface() {
    char command[100];
    char device_name[MAX_NAME_LENGTH];
    
    while (true) {
        printf("\nEnter command (add <device>, toggle <device>, list, exit): ");
        fgets(command, sizeof(command), stdin);
        
        // Remove newline character
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "add ", 4) == 0) {
            sscanf(command + 4, "%s", device_name);
            add_device(device_name);
        } else if (strncmp(command, "toggle ", 7) == 0) {
            sscanf(command + 7, "%s", device_name);
            toggle_device(device_name);
        } else if (strcmp(command, "list") == 0) {
            show_devices();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Smart Home Automation System.\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Automation System!\n");
    control_interface();
    return 0;
}