//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10
#define NAME_LEN 50

typedef enum {
    OFF,
    ON
} State;

typedef struct {
    char name[NAME_LEN];
    State state;
    int value; // For devices that have adjustable values (like brightness or temperature)
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

void addDevice(const char *name) {
    if (device_count < MAX_DEVICES) {
        strcpy(devices[device_count].name, name);
        devices[device_count].state = OFF;
        devices[device_count].value = 0; // Default value for devices
        device_count++;
        printf("Device '%s' added successfully.\n", name);
    } else {
        printf("Device limit reached. Can't add more devices.\n");
    }
}

void toggleDevice(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = (devices[i].state == OFF) ? ON : OFF;
            printf("Device '%s' is now %s.\n", name, devices[i].state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void setDeviceValue(const char *name, int value) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].value = value;
            printf("Device '%s' value set to %d.\n", name, value);
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void printDevices() {
    printf("Current devices status:\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device: %s, State: %s, Value: %d\n",
               devices[i].name,
               devices[i].state == ON ? "ON" : "OFF",
               devices[i].value);
    }
}

void printMenu() {
    printf("\nSmart Home Automation System\n");
    printf("1. Add Device\n");
    printf("2. Toggle Device\n");
    printf("3. Set Device Value\n");
    printf("4. Print All Devices\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    char name[NAME_LEN];
    int value;

    printf("Welcome to the Smart Home Automation System!\n");

    while (1) {
        printMenu();
        scanf("%d", &option);
        getchar(); // Consume the newline character
        
        switch (option) {
            case 1:
                printf("Enter device name to add: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                addDevice(name);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                toggleDevice(name);
                break;
            case 3:
                printf("Enter device name to set value: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                printf("Enter new value: ");
                scanf("%d", &value);
                setDeviceValue(name, value);
                break;
            case 4:
                printDevices();
                break;
            case 5:
                printf("Exiting Smart Home Automation System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}