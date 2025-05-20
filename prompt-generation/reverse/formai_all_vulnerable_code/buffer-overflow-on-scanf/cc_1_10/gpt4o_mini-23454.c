//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[30];
    int status; // 0 = off, 1 = on
} Device;

void toggle_device(Device *device) {
    device->status = !device->status;
    printf("%s is now %s.\n", device->name, device->status ? "ON" : "OFF");
}

void display_devices(Device devices[], int device_count) {
    printf("\nCurrent Status of Devices:\n");
    for (int i = 0; i < device_count; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].status ? "ON" : "OFF");
    }
}

void control_device(Device devices[], int device_count) {
    int choice;
    printf("\nChoose a device to toggle:\n");
    for (int i = 0; i < device_count; i++) {
        printf("%d. %s\n", i + 1, devices[i].name);
    }
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice > 0 && choice <= device_count) {
        toggle_device(&devices[choice - 1]);
    } else {
        printf("Invalid choice!\n");
    }
}

void set_temperature() {
    int temperature;
    printf("\nEnter the desired temperature: ");
    scanf("%d", &temperature);
    printf("Thermostat set to %d degrees.\n", temperature);
}

void lock_door() {
    char command[10];
    printf("\nType 'lock' to lock the door: ");
    scanf("%s", command);
    if (strcmp(command, "lock") == 0) {
        printf("The door is now locked.\n");
    } else {
        printf("Invalid command!\n");
    }
}

int main() {
    Device devices[MAX_DEVICES] = {
        {"Living Room Light", 0},
        {"Kitchen Light", 0},
        {"Bedroom Light", 0},
        {"Bathroom Light", 0},
        {"Garage Door", 0},
        {"Security System", 0},
        {"Thermostat", 1}, // default on
        {"Front Door Lock", 0},
        {"Garden Water Sprinkler", 0},
        {"TV", 0}
    };

    int choice;
    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Control Devices\n");
        printf("2. Set Thermostat\n");
        printf("3. Lock Front Door\n");
        printf("4. Display Device Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                control_device(devices, MAX_DEVICES);
                break;
            case 2:
                set_temperature();
                break;
            case 3:
                lock_door();
                break;
            case 4:
                display_devices(devices, MAX_DEVICES);
                break;
            case 5:
                printf("Exiting Smart Home Automation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}