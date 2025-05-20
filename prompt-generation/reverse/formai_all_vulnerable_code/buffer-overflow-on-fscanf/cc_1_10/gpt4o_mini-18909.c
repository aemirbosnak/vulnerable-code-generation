//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LENGTH 30

typedef enum {
    OFF,
    ON
} DeviceState;

typedef struct {
    char name[DEVICE_NAME_LENGTH];
    DeviceState state;
    int temperature; // For thermostat
} SmartDevice;

SmartDevice devices[MAX_DEVICES];
int deviceCount = 0;

// Function prototypes
void addDevice(const char *name);
void toggleDevice(const char *name);
void setTemperature(const char *name, int temperature);
void displayStatus();
void simulateTimePassing(int seconds);
void loadDevices();
void saveDevices();

int main() {
    loadDevices();  // Load existing devices from disk
    int choice, temp;
    char name[DEVICE_NAME_LENGTH];

    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Add Device\n");
        printf("2. Toggle Device\n");
        printf("3. Set Temperature of Device\n");
        printf("4. Display Status of Devices\n");
        printf("5. Simulate Time Passing\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                printf("Enter device name: ");
                scanf("%s", name);
                printf("Enter desired temperature: ");
                scanf("%d", &temp);
                setTemperature(name, temp);
                break;
            case 4:
                displayStatus();
                break;
            case 5:
                printf("Enter seconds to simulate time passing: ");
                scanf("%d", &temp);
                simulateTimePassing(temp);
                break;
            case 6:
                saveDevices();  // Save before exiting
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addDevice(const char *name) {
    if (deviceCount >= MAX_DEVICES) {
        printf("Device limit reached. Cannot add more devices.\n");
        return;
    }
    strcpy(devices[deviceCount].name, name);
    devices[deviceCount].state = OFF;
    devices[deviceCount].temperature = 22; // Default temperature
    deviceCount++;
    printf("Device %s added.\n", name);
}

void toggleDevice(const char *name) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = (devices[i].state == ON) ? OFF : ON;
            printf("Device %s is now %s.\n",
                name, devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device %s not found.\n", name);
}

void setTemperature(const char *name, int temperature) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].temperature = temperature;
            printf("Temperature of device %s set to %d.\n", name, temperature);
            return;
        }
    }
    printf("Device %s not found.\n", name);
}

void displayStatus() {
    printf("\nDevice Status:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("Device Name: %s, State: %s, Temperature: %d\n",
            devices[i].name,
            devices[i].state == ON ? "ON" : "OFF",
            devices[i].temperature);
    }
}

void simulateTimePassing(int seconds) {
    printf("Simulating time passing for %d seconds...\n", seconds);
    sleep(seconds);
}

void loadDevices() {
    FILE *file = fopen("devices.txt", "r");
    if (file) {
        while (fscanf(file, "%s %d %d", devices[deviceCount].name,
                      (int *)&devices[deviceCount].state,
                      &devices[deviceCount].temperature) == 3) {
            deviceCount++;
        }
        fclose(file);
    }
}

void saveDevices() {
    FILE *file = fopen("devices.txt", "w");
    if (file) {
        for (int i = 0; i < deviceCount; i++) {
            fprintf(file, "%s %d %d\n", devices[i].name,
                    devices[i].state, devices[i].temperature);
        }
        fclose(file);
    }
}