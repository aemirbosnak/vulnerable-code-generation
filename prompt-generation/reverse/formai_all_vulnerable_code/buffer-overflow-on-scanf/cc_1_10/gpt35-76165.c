//FormAI DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 20

// Define a struct for each device
typedef struct {
    char name[MAX_NAME_LENGTH];
    int state;
} device_t;

// Initialize an array of devices
device_t devices[MAX_DEVICES];

// Method to turn on/off a device
void toggleDevice(int index) {
    if(devices[index].state == 1) {
        printf("%s turned OFF\n", devices[index].name);
        devices[index].state = 0;
    } else {
        printf("%s turned ON\n", devices[index].name);
        devices[index].state = 1;
    }
}

int main() {
    int num_devices = 0;

    // Add some sample devices
    strcpy(devices[num_devices].name, "Living Room Light");
    devices[num_devices].state = 0;
    num_devices++;

    strcpy(devices[num_devices].name, "Bedroom Light");
    devices[num_devices].state = 0;
    num_devices++;

    strcpy(devices[num_devices].name, "Kitchen Light");
    devices[num_devices].state = 0;
    num_devices++;

    // Initial prompt
    printf("Welcome to Smart Home Light Control!\n\n");
    printf("Currently, the following devices are available:\n");
    for(int i = 0; i < num_devices; i++) {
        printf("%d. %s [%s]\n", i+1, devices[i].name, (devices[i].state == 1 ? "ON" : "OFF"));
    }
    printf("\n");

    // Prompt user to choose a device to control
    printf("Which device would you like to toggle? ");
    int device_choice;
    scanf("%d", &device_choice);

    // Check if device choice is valid
    if(device_choice < 1 || device_choice > num_devices) {
        printf("Invalid device choice.\n");
        exit(0);
    }

    // Toggle the device
    toggleDevice(device_choice-1);

    // Print updated device states
    printf("\nUpdated device states:\n");
    for(int i = 0; i < num_devices; i++) {
        printf("%d. %s [%s]\n", i+1, devices[i].name, (devices[i].state == 1 ? "ON" : "OFF"));
    }

    return 0;
}