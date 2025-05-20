//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Smart Home Device struct
typedef struct {
    char name[50];
    int status;
    int power;
} Device;

// Initialize devices
void initDevices(Device *devices, int numDevices) {
    for (int i = 0; i < numDevices; i++) {
        strcpy(devices[i].name, "Device ");
        sprintf(&devices[i].name[7], "%d", i + 1);
        devices[i].status = 0;
        devices[i].power = 0;
    }
}

// Print device status
void printDevices(Device *devices, int numDevices) {
    for (int i = 0; i < numDevices; i++) {
        printf("%s: Status - %d, Power - %d\n", devices[i].name, devices[i].status, devices[i].power);
    }
}

// Set device status
void setDeviceStatus(Device *devices, int numDevices, int deviceNum, int status) {
    devices[deviceNum - 1].status = status;
}

// Set device power
void setDevicePower(Device *devices, int numDevices, int deviceNum, int power) {
    devices[deviceNum - 1].power = power;
}

// Main function
int main() {
    int numDevices;
    printf("Enter number of devices: ");
    scanf("%d", &numDevices);

    Device *devices = (Device *)malloc(numDevices * sizeof(Device));
    initDevices(devices, numDevices);

    int choice;
    do {
        printf("\nSmart Home Automation\n");
        printf("1. Print device status\n");
        printf("2. Set device status\n");
        printf("3. Set device power\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printDevices(devices, numDevices);
                break;
            case 2:
                printf("Enter device number: ");
                scanf("%d", &choice);
                printf("Enter status (0 or 1): ");
                scanf("%d", &choice);
                setDeviceStatus(devices, numDevices, choice, choice);
                break;
            case 3:
                printf("Enter device number: ");
                scanf("%d", &choice);
                printf("Enter power (0 or 1): ");
                scanf("%d", &choice);
                setDevicePower(devices, numDevices, choice, choice);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    free(devices);
    return 0;
}