//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEVICE_COUNT 3

typedef enum { OFF, ON } State;

typedef struct {
    char name[20];
    State state;
} Device;

void initializeDevices(Device devices[]) {
    strcpy(devices[0].name, "Living Room Light");
    devices[0].state = OFF;

    strcpy(devices[1].name, "Thermostat");
    devices[1].state = OFF;

    strcpy(devices[2].name, "Security Camera");
    devices[2].state = OFF;
}

void printDevices(Device devices[]) {
    printf("\nDevice Status:\n");
    for (int i = 0; i < DEVICE_COUNT; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].state == ON ? "ON" : "OFF");
    }
}

void toggleDevice(Device *device) {
    device->state = device->state == ON ? OFF : ON;
}

void controlDevice(Device devices[]) {
    int choice;
    printf("\nChoose a device to toggle:\n");
    for (int i = 0; i < DEVICE_COUNT; i++) {
        printf("%d. %s\n", i + 1, devices[i].name);
    }
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= DEVICE_COUNT) {
        toggleDevice(&devices[choice - 1]);
        printf("%s has been toggled.\n", devices[choice - 1].name);
    } else if (choice != 0) {
        printf("Invalid choice!\n");
    }
}

void scheduleDevice(Device devices[]) {
    int choice, hours, minutes;
    printf("\nSchedule a device:\n");
    for (int i = 0; i < DEVICE_COUNT; i++) {
        printf("%d. %s\n", i + 1, devices[i].name);
    }
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice > 0 && choice <= DEVICE_COUNT) {
        printf("Enter time to schedule (HH MM): ");
        scanf("%d %d", &hours, &minutes);
        printf("Scheduled %s to toggle at %02d:%02d.\n", devices[choice - 1].name, hours, minutes);
        // Note: In a real implementation, you would need sleep or 
        // a timed check system to handle this.
    } else if (choice != 0) {
        printf("Invalid choice!\n");
    }
}

int main() {
    Device devices[DEVICE_COUNT];
    initializeDevices(devices);
    int running = 1;

    while (running) {
        printDevices(devices);
        printf("\nMenu:\n");
        printf("1. Toggle Device\n");
        printf("2. Schedule Device\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                controlDevice(devices);
                break;
            case 2:
                scheduleDevice(devices);
                break;
            case 3:
                running = 0;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
        sleep(1);
    }

    return 0;
}