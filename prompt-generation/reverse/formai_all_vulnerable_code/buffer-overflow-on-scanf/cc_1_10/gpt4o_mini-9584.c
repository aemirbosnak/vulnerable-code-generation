//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Constants
#define MAX_DEVICES 10
#define MAX_NAME_LEN 30

// Device states
typedef enum {
    OFF,
    ON
} State;

// Device structure
typedef struct {
    char name[MAX_NAME_LEN];
    State state;
} Device;

// Smart Home Automation System
typedef struct {
    Device devices[MAX_DEVICES];
    int count;
} SmartHome;

// Function prototypes
void initializeHome(SmartHome *home);
void addDevice(SmartHome *home, const char *name);
void toggleDevice(SmartHome *home, const char *name);
void displayDevices(SmartHome *home);
void statusReport(SmartHome *home);
void menu();

// Main function
int main() {
    SmartHome myHome;
    initializeHome(&myHome);

    int choice;
    char deviceName[MAX_NAME_LEN];

    do {
        menu();
        printf("Choose an option (0 to exit): ");
        scanf("%d", &choice);
        getchar();  // Clear newline

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                fgets(deviceName, MAX_NAME_LEN, stdin);
                deviceName[strcspn(deviceName, "\n")] = 0;  // Remove newline
                addDevice(&myHome, deviceName);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                fgets(deviceName, MAX_NAME_LEN, stdin);
                deviceName[strcspn(deviceName, "\n")] = 0;  // Remove newline
                toggleDevice(&myHome, deviceName);
                break;
            case 3:
                displayDevices(&myHome);
                break;
            case 4:
                statusReport(&myHome);
                break;
            case 0:
                printf("Exiting Smart Home Automation System. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        sleep(1); // Simulate a delay for realism
    } while (choice != 0);

    return 0;
}

// Menu display function
void menu() {
    printf("\n--- Smart Home Automation System ---\n");
    printf("1. Add Device\n");
    printf("2. Toggle Device\n");
    printf("3. Display Devices\n");
    printf("4. Status Report\n");
    printf("0. Exit\n");
}

// Initialize the smart home system
void initializeHome(SmartHome *home) {
    home->count = 0;
    printf("Welcome to your Smart Home Automation System!\n");
}

// Add a new device to the home
void addDevice(SmartHome *home, const char *name) {
    if (home->count < MAX_DEVICES) {
        strncpy(home->devices[home->count].name, name, MAX_NAME_LEN);
        home->devices[home->count].state = OFF; // New devices start off
        home->count++;
        printf("Device '%s' added successfully!\n", name);
    } else {
        printf("Device limit reached! Cannot add more devices.\n");
    }
}

// Toggle the state of a device
void toggleDevice(SmartHome *home, const char *name) {
    for (int i = 0; i < home->count; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            home->devices[i].state = (home->devices[i].state == OFF) ? ON : OFF;
            printf("Device '%s' is now %s.\n", name, home->devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

// Display all devices in the home
void displayDevices(SmartHome *home) {
    if (home->count == 0) {
        printf("No devices found in the smart home.\n");
        return;
    }
    printf("\nDevices in your Smart Home:\n");
    for (int i = 0; i < home->count; i++) {
        printf(" Device: %-20s State: %s\n", home->devices[i].name, 
               home->devices[i].state == ON ? "ON" : "OFF");
    }
}

// Generate a status report of all devices
void statusReport(SmartHome *home) {
    printf("\n--- Status Report ---\n");
    for (int i = 0; i < home->count; i++) {
        printf("Device: %s is currently %s\n", 
               home->devices[i].name, 
               home->devices[i].state == ON ? "ACTIVE" : "INACTIVE");
    }
    printf("---------------------\n");
}