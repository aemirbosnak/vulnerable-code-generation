//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10

typedef struct {
    char name[50];
    int is_on;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

// Function to add a new device
void add_device(char *name) {
    if (device_count < MAX_DEVICES) {
        strcpy(devices[device_count].name, name);
        devices[device_count].is_on = 0; // Initialize device as off
        device_count++;
        printf("Device '%s' added successfully.\n", name);
    } else {
        printf("Device limit reached! Cannot add more devices.\n");
    }
}

// Function to toggle device state
void toggle_device(char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].is_on = !devices[i].is_on;
            printf("Device '%s' is now %s.\n", devices[i].name, devices[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

// Function to list all devices and their states
void list_devices() {
    printf("\n--- Smart Home Device List ---\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device: '%s' - State: %s\n", devices[i].name, devices[i].is_on ? "ON" : "OFF");
    }
    printf("-------------------------------\n");
}

// Function to execute user commands
void process_command(char *command) {
    char action[50], name[50];

    if (sscanf(command, "%s %s", action, name) == 2) {
        if (strcmp(action, "add") == 0) {
            add_device(name);
        } else if (strcmp(action, "toggle") == 0) {
            toggle_device(name);
        } else {
            printf("Unknown action: '%s'. Valid actions are: add, toggle.\n", action);
        }
    } else if (strcmp(command, "list") == 0) {
        list_devices();
    } else {
        printf("Unknown command. Use 'add <device_name>', 'toggle <device_name>', or 'list'.\n");
    }
}

// Main function
int main() {
    char command[100];

    printf("Welcome to the Smart Home Automation System!\n");
    printf("You can add, toggle, and list devices.\n");
    printf("Type 'exit' to quit the program.\n");

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        
        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }

        process_command(command);
    }

    printf("Exiting the Smart Home Automation System. Goodbye!\n");
    return 0;
}