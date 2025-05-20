//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 20

typedef enum {
    DEVICE_OFF,
    DEVICE_ON
} DeviceState;

typedef struct {
    char name[NAME_LENGTH];
    DeviceState state;
} SmartDevice;

// Function prototypes
void display_menu();
void add_device(SmartDevice *devices, int *count);
void toggle_device(SmartDevice *devices, int count);
void view_devices(SmartDevice *devices, int count);
void control_devices(SmartDevice *devices, int count);

int main() {
    SmartDevice devices[MAX_DEVICES];
    int device_count = 0;
    int choice;

    while(1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_device(devices, &device_count);
                break;
            case 2:
                toggle_device(devices, device_count);
                break;
            case 3:
                view_devices(devices, device_count);
                break;
            case 4:
                control_devices(devices, device_count);
                break;
            case 5:
                printf("Exiting smart home automation system.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n***** Smart Home Automation System *****\n");
    printf("1. Add Device\n");
    printf("2. Toggle Device\n");
    printf("3. View Devices\n");
    printf("4. Control All Devices\n");
    printf("5. Exit\n");
}

void add_device(SmartDevice *devices, int *count) {
    if (*count >= MAX_DEVICES) {
        printf("Device limit reached. Cannot add more devices.\n");
        return;
    }
    printf("Enter device name: ");
    scanf("%s", devices[*count].name);
    devices[*count].state = DEVICE_OFF;
    (*count)++;
    printf("Device '%s' added successfully.\n", devices[*count - 1].name);
}

void toggle_device(SmartDevice *devices, int count) {
    if (count == 0) {
        printf("No devices to toggle.\n");
        return;
    }
    char name[NAME_LENGTH];
    printf("Enter device name to toggle: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = (devices[i].state == DEVICE_OFF) ? DEVICE_ON : DEVICE_OFF;
            printf("Device '%s' is now %s.\n", devices[i].name, (devices[i].state == DEVICE_ON) ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void view_devices(SmartDevice *devices, int count) {
    if (count == 0) {
        printf("No devices added yet.\n");
        return;
    }
    printf("\nCurrent Devices Status:\n");
    for (int i = 0; i < count; i++) {
        printf("Device: %s, State: %s\n", devices[i].name, (devices[i].state == DEVICE_ON) ? "ON" : "OFF");
    }
}

void control_devices(SmartDevice *devices, int count) {
    if (count == 0) {
        printf("No devices to control.\n");
        return;
    }
    int command;
    printf("Enter 1 to turn ON all devices or 0 to turn OFF all devices: ");
    scanf("%d", &command);

    for (int i = 0; i < count; i++) {
        devices[i].state = (command == 1) ? DEVICE_ON : DEVICE_OFF;
        printf("Device '%s' is now %s.\n", devices[i].name, (devices[i].state == DEVICE_ON) ? "ON" : "OFF");
    }
}