//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[30];
    int is_on;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char* name) {
    if (device_count >= MAX_DEVICES) {
        printf("Maximum number of devices reached!\n");
        return;
    }
    strcpy(devices[device_count].name, name);
    devices[device_count].is_on = 0; // Initially off
    device_count++;
    printf("Device '%s' added successfully!\n", name);
}

void toggle_device(const char* name) {
    for(int i = 0; i < device_count; i++) {
        if(strcmp(devices[i].name, name) == 0) {
            devices[i].is_on = !devices[i].is_on; // Toggle state
            printf("%s is now %s!\n", devices[i].name, devices[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

void list_devices() {
    printf("\nSmart Home Devices:\n");
    for(int i = 0; i < device_count; i++) {
        printf("- %s: %s\n", devices[i].name, devices[i].is_on ? "ON" : "OFF");
    }
    printf("\n");
}

int main() {
    char command[50], device_name[30];
    printf("Welcome to Smart Home Automation System!\n");

    while (1) {
        printf("Enter command (add, toggle, list, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter device name to add: ");
            scanf("%s", device_name);
            add_device(device_name);
        } else if (strcmp(command, "toggle") == 0) {
            printf("Enter device name to toggle: ");
            scanf("%s", device_name);
            toggle_device(device_name);
        } else if (strcmp(command, "list") == 0) {
            list_devices();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Automation System. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}