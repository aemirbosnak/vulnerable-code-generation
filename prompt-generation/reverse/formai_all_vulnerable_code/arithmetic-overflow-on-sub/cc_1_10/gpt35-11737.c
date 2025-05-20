//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure of Smart Home Devices
struct SmartHomeDevice {
    char name[50];
    int powerConsumption;
    int status;
};

// Function to Turn on/off Smart Home Devices
void switchDevice(struct SmartHomeDevice* device) {
    if (device->status == 0) {
        printf("\n%s turned on.", device->name);
        device->status = 1;
    } else {
        printf("\n%s turned off.", device->name);
        device->status = 0;
    }
}

int main() {
    int numOfDevices = 3;

    // Creating 3 Smart Home Devices
    struct SmartHomeDevice devices[numOfDevices];
    strcpy(devices[0].name, "Bulb");
    devices[0].powerConsumption = 10;
    devices[0].status = 0;
    
    strcpy(devices[1].name, "Fan");
    devices[1].powerConsumption = 20;
    devices[1].status = 0;

    strcpy(devices[2].name, "AC");
    devices[2].powerConsumption = 100;
    devices[2].status = 0;

    // User Input Handling
    while (1) {
        printf("\n\nSmart Home Devices:\n");
        for (int i = 0; i < numOfDevices; i++) {
            printf("%d. %s (%d watt)", i+1, devices[i].name, devices[i].powerConsumption);
            if (devices[i].status == 1) {
                printf(" (On)\n");
            } else {
                printf(" (Off)\n");
            }
        }

        printf("\nSelect the device to switch on/off (Enter 0 to exit): ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice > numOfDevices) {
            printf("\nInvalid input. Try Again!");
            continue;
        }

        // Switching of Device
        switchDevice(&devices[choice-1]);
    }
    return 0;
}