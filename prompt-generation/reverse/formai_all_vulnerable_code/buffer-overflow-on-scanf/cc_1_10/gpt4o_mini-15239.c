//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 30

typedef enum {
    LIGHT,
    THERMOSTAT,
    DOOR,
    CAMERA
} DeviceType;

typedef struct {
    char name[MAX_NAME_LENGTH];
    DeviceType type;
    int state; // 0 for off, 1 for on
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char *name, DeviceType type) {
    if (device_count >= MAX_DEVICES) {
        printf("Device limit reached. Cannot add more devices.\n");
        return;
    }
    strcpy(devices[device_count].name, name);
    devices[device_count].type = type;
    devices[device_count].state = 0; // Start with the device off
    device_count++;
    printf("Device '%s' added successfully.\n", name);
}

void toggle_device(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = !devices[i].state; // Toggle the state
            printf("Device '%s' is now %s.\n", devices[i].name, devices[i].state ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void set_temperature(int temp) {
    printf("Thermostat set to %d degrees Celsius.\n", temp);
    // Here, you can include logic to check for actual current temperature
    // and optimize heating/cooling as required
}

void lock_door() {
    printf("The door has been locked.\n");
}

void unlock_door() {
    printf("The door has been unlocked.\n");
}

void view_device_status() {
    printf("Smart Home Device Status:\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device Name: %s, Type: %d, State: %s\n", devices[i].name,
               devices[i].type, devices[i].state ? "ON" : "OFF");
    }
}

void main_menu() {
    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. Set Thermostat Temperature\n");
        printf("4. Lock Door\n");
        printf("5. Unlock Door\n");
        printf("6. View Device Status\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                int type;
                printf("Enter device name: ");
                scanf("%s", name);
                printf("Enter device type (0: LIGHT, 1: THERMOSTAT, 2: DOOR, 3: CAMERA): ");
                scanf("%d", &type);
                add_device(name, (DeviceType)type);
                break;
            }
            case 2: {
                char name[MAX_NAME_LENGTH];
                printf("Enter device name to toggle: ");
                scanf("%s", name);
                toggle_device(name);
                break;
            }
            case 3: {
                int temp;
                printf("Enter desired temperature: ");
                scanf("%d", &temp);
                set_temperature(temp);
                break;
            }
            case 4:
                lock_door();
                break;
            case 5:
                unlock_door();
                break;
            case 6:
                view_device_status();
                break;
            case 7:
                printf("Exiting Smart Home Automation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1); // To slow down the loop for better user experience
    }
}

int main() {
    main_menu();
    return 0;
}