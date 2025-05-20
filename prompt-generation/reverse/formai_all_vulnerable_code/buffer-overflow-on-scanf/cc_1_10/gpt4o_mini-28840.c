//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 50

typedef struct {
    char name[50];
    int status; // 0: off, 1: on
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char* name) {
    if (device_count < MAX_DEVICES) {
        strncpy(devices[device_count].name, name, 50);
        devices[device_count].status = 0; // Initialize to off
        device_count++;
        printf("Device '%s' added successfully.\n", name);
    } else {
        printf("Device list is full. Cannot add more devices.\n");
    }
}

void toggle_device(const char* name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].status = !devices[i].status; // Toggle status
            printf("Device '%s' is now %s.\n", name, devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void display_devices() {
    if (device_count == 0) {
        printf("No devices found.\n");
        return;
    }
    printf("Connected Devices:\n");
    for (int i = 0; i < device_count; i++) {
        printf("- %s: %s\n", devices[i].name, devices[i].status ? "ON" : "OFF");
    }
}

void delete_device(const char* name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            for (int j = i; j < device_count - 1; j++) {
                devices[j] = devices[j + 1]; // Shift devices left
            }
            device_count--;
            printf("Device '%s' removed successfully.\n", name);
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void command_menu() {
    printf("Smart Home Automation System\n");
    printf("1. Add Device\n");
    printf("2. Toggle Device\n");
    printf("3. Display Devices\n");
    printf("4. Delete Device\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char device_name[50];
    
    while (1) {
        command_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline character from input buffer
        
        switch (choice) {
            case 1:
                printf("Enter device name to add: ");
                fgets(device_name, sizeof(device_name), stdin);
                device_name[strcspn(device_name, "\n")] = 0; // Remove newline
                add_device(device_name);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                fgets(device_name, sizeof(device_name), stdin);
                device_name[strcspn(device_name, "\n")] = 0; // Remove newline
                toggle_device(device_name);
                break;
            case 3:
                display_devices();
                break;
            case 4:
                printf("Enter device name to delete: ");
                fgets(device_name, sizeof(device_name), stdin);
                device_name[strcspn(device_name, "\n")] = 0; // Remove newline
                delete_device(device_name);
                break;
            case 5:
                printf("Exiting Smart Home Automation System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
        sleep(1); // Adding a delay for better readability
    }
    
    return 0;
}