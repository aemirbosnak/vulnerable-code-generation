//FormAI DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

#define MAX_DEVICES 10

typedef struct {
    char name[20];
    bool isOn;
} Device;

int main() {
    Device devices[MAX_DEVICES];
    int numDevices = 0;

    while (true) {
        printf("Enter the name of a device or 'quit': ");
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        bool deviceExists = false;
        for (int i = 0; i < numDevices; i++) {
            if (strcmp(devices[i].name, input) == 0) {
                deviceExists = true;
                printf("Device %s is already registered.\n", devices[i].name);
                break;
            }
        }

        if (!deviceExists) {
            Device device;
            strcpy(device.name, input);
            device.isOn = false;
            devices[numDevices] = device;
            numDevices++;

            printf("Device %s registered successfully.\n", device.name);
        }
    }

    printf("Your devices:\n");
    for (int i = 0; i < numDevices; i++) {
        printf("%s is %s.\n", devices[i].name, devices[i].isOn ? "on" : "off");
    }

    while (true) {
        printf("Enter the name of a device to toggle or 'quit': ");
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        bool deviceFound = false;
        for (int i = 0; i < numDevices; i++) {
            if (strcmp(devices[i].name, input) == 0) {
                deviceFound = true;
                devices[i].isOn = !devices[i].isOn;
                printf("Device %s is now %s.\n", devices[i].name, devices[i].isOn ? "on" : "off");
                break;
            }
        }

        if (!deviceFound) {
            printf("Device %s not found.\n", input);
        }
    }

    printf("Goodbye!\n");

    return 0;
}