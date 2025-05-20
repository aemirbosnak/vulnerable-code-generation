//FormAI DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_DEVICES 50
#define MAX_CHARS 20

//Device structure
typedef struct {
    char name[MAX_CHARS];
    int status;
} device;

//Initialize devices
void initializeDevices(device devices[]) {
    strcpy(devices[0].name, "Living Room TV");
    devices[0].status = 0;
    strcpy(devices[1].name, "Kitchen Lights");
    devices[1].status = 0;
    strcpy(devices[2].name, "Bedroom AC");
    devices[2].status = 0;
    strcpy(devices[3].name, "Bathroom Fan");
    devices[3].status = 0;
}

//Display devices status
void displayDevices(device devices[], int numDevices) {
    printf("Devices:\n");
    for (int i = 0; i < numDevices; i++) {
        printf("%d. %s: %s\n", i + 1, devices[i].name, devices[i].status ? "On" : "Off");
    }
    printf("\n");
}

//Change device status
void toggleDevice(device devices[], int numDevices, int deviceIndex) {
    if (deviceIndex < 1 || deviceIndex > numDevices) {
        printf("Invalid device number.\n");
    }
    else {
        devices[deviceIndex - 1].status = !devices[deviceIndex - 1].status;
        printf("%s is now %s.\n", devices[deviceIndex - 1].name, devices[deviceIndex - 1].status ? "On" : "Off");
    }
}

int main() {
    device devices[MAX_DEVICES];
    int numDevices = 4;

    initializeDevices(devices);

    printf("Welcome to Smart Home Automation!\n");
    displayDevices(devices, numDevices);

    int choice = 0;
    while (choice != 4) {
        printf("What would you like to do?\n");
        printf("1. View devices.\n");
        printf("2. Turn on/off a device.\n");
        printf("3. Run a routine.\n");
        printf("4. Exit.\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayDevices(devices, numDevices);
            break;
        case 2:
            printf("Which device would you like to turn on/off?\n");
            int deviceIndex;
            scanf("%d", &deviceIndex);
            toggleDevice(devices, numDevices, deviceIndex);
            break;
        case 3:
            printf("Routines not implemented yet.\n");
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
        }
    }

    return 0;
}