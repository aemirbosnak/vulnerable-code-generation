//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 50

typedef enum {
    LIGHT,
    THERMOSTAT,
    LOCK,
    CAMERA,
    UNKNOWN
} DeviceType;

typedef struct {
    char name[MAX_NAME_LENGTH];
    DeviceType type;
    int status; // 0 - off, 1 - on
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void addDevice(const char *name, DeviceType type) {
    if (device_count >= MAX_DEVICES) {
        printf("Device limit reached. Cannot add more devices.\n");
        return;
    }
    SmartDevice newDevice;
    strncpy(newDevice.name, name, MAX_NAME_LENGTH);
    newDevice.type = type;
    newDevice.status = 0;
    devices[device_count++] = newDevice;
    printf("Device '%s' added.\n", name);
}

void toggleDevice(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].status = !devices[i].status;
            printf("Device '%s' is now %s.\n", devices[i].name, devices[i].status ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void displayDevices() {
    printf("\nSmart Home Devices:\n");
    for (int i = 0; i < device_count; i++) {
        printf("Name: %s, Type: %d, Status: %s\n", devices[i].name, devices[i].type,
               devices[i].status ? "ON" : "OFF");
    }
    printf("\n");
}

void scheduleDevice(const char *name, int hour, int minute) {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%H:%M", timeinfo);

    int current_hour, current_minute;
    sscanf(buffer, "%d:%d", &current_hour, &current_minute);

    int hours_left = (hour - current_hour + 24) % 24;
    int minutes_left = (minute - current_minute + 60) % 60;

    int sleep_time = (hours_left * 3600) + (minutes_left * 60);
    
    if (sleep_time == 0) {
        printf("Scheduling immediate action for device '%s'.\n", name);
        toggleDevice(name);
        return;
    }

    printf("Scheduling device '%s' to toggle in %d seconds.\n", name, sleep_time);
    sleep(sleep_time);
    toggleDevice(name);
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int device_type_choice;
    int hour, minute;

    do {
        printf("\nSmart Home Automation System\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. Display Devices\n");
        printf("4. Schedule Device\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", name);
                printf("Select device type (0-LIGHT, 1-THERMOSTAT, 2-LOCK, 3-CAMERA): ");
                scanf("%d", &device_type_choice);
                addDevice(name, device_type_choice < 0 || device_type_choice > 3 ? UNKNOWN : (DeviceType)device_type_choice);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                scanf("%s", name);
                toggleDevice(name);
                break;
            case 3:
                displayDevices();
                break;
            case 4:
                printf("Enter device name to schedule: ");
                scanf("%s", name);
                printf("Enter schedule time (HH MM): ");
                scanf("%d %d", &hour, &minute);
                scheduleDevice(name, hour, minute);
                break;
            case 0:
                printf("Exiting Smart Home Automation System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}