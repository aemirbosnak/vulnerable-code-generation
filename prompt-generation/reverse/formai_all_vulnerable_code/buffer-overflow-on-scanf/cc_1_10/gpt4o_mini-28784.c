//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LENGTH 50

typedef enum {
    OFF,
    ON
} DeviceState;

typedef struct {
    char name[DEVICE_NAME_LENGTH];
    DeviceState state;
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int device_count = 0;

void addDevice(const char* name) {
    if (device_count < MAX_DEVICES) {
        strncpy(devices[device_count].name, name, DEVICE_NAME_LENGTH);
        devices[device_count].state = OFF;
        device_count++;
        printf("Device '%s' added.\n", name);
    } else {
        printf("Device list is full! Cannot add more devices.\n");
    }
}

void toggleDevice(const char* name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = (devices[i].state == ON) ? OFF : ON;
            printf("Device '%s' is now %s.\n", devices[i].name, devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void displayDevices() {
    printf("Smart Devices Status:\n");
    for (int i = 0; i < device_count; i++) {
        printf(" - %s: %s\n", devices[i].name, devices[i].state == ON ? "ON" : "OFF");
    }
}

void scheduleDevice(const char* name, int hour, int minute) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    
    if (tm_now->tm_hour == hour && tm_now->tm_min == minute) {
        toggleDevice(name);
    }
}

void runScheduler() {
    printf("Scheduler is running...\n");
    while (1) {
        displayDevices();
        sleep(60); // Check every minute
    }
}

void settingsMenu() {
    int choice;
    char name[DEVICE_NAME_LENGTH];
    while (1) {
        printf("\n--- Smart Home Automation Settings ---\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. Display Devices\n");
        printf("4. Start Scheduler\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", name);
                addDevice(name);
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
                runScheduler();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to Smart Home Automation System\n");
    settingsMenu();
    return 0;
}