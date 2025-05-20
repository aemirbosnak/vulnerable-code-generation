//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10

typedef enum {
    OFF = 0,
    ON = 1
} DeviceState;

typedef struct {
    char name[30];
    DeviceState state;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char *name) {
    if (deviceCount < MAX_DEVICES) {
        strcpy(devices[deviceCount].name, name);
        devices[deviceCount].state = OFF;
        deviceCount++;
        printf("Device \"%s\" added successfully.\n", name);
    } else {
        printf("Cannot add more devices. Maximum limit reached!\n");
    }
}

void toggleDevice(const char *name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = !devices[i].state;
            printf("Device \"%s\" is now %s.\n", devices[i].name, devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device \"%s\" not found.\n", name);
}

void statusCheck() {
    printf("\nCurrent Status of Devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("Device \"%s\": %s\n", devices[i].name, devices[i].state == ON ? "ON" : "OFF");
    }
    printf("\n");
}

void scheduleDevice(const char *name, int hour, int minute, DeviceState state) {
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);

    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        printf("Invalid time for scheduling.\n");
        return;
    }

    printf("Scheduling device \"%s\" to turn %s at %02d:%02d.\n", name, state == ON ? "ON" : "OFF", hour, minute);

    while (1) {
        time(&t);
        tm_info = localtime(&t);
        if (tm_info->tm_hour == hour && tm_info->tm_min == minute) {
            toggleDevice(name);
            break;
        }
        sleep(30); // Check every 30 seconds
    }
}

void listDevices() {
    printf("\nList of Devices:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("%d. %s\n", i + 1, devices[i].name);
    }
}

int main() {
    int choice;
    char deviceName[30];
    
    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. Check Device Status\n");
        printf("4. Schedule Device\n");
        printf("5. List All Devices\n");
        printf("6. Exit\n");
        printf("Select an option (1-6): ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", deviceName);
                addDevice(deviceName);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                scanf("%s", deviceName);
                toggleDevice(deviceName);
                break;
            case 3:
                statusCheck();
                break;
            case 4: {
                int hour, minute, state;
                printf("Enter device name to schedule: ");
                scanf("%s", deviceName);
                printf("Enter time (hour minute): ");
                scanf("%d %d", &hour, &minute);
                printf("Enter state (1 for ON, 0 for OFF): ");
                scanf("%d", &state);
                scheduleDevice(deviceName, hour, minute, (DeviceState)state);
                break;
            }
            case 5:
                listDevices();
                break;
            case 6:
                printf("Exiting the smart home automation system.\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
        }
    }
    
    return 0;
}