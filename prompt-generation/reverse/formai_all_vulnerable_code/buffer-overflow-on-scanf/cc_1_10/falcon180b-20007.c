//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[20];
    int status;
    int power;
} Device;

Device devices[MAX_DEVICES];

void discoverDevices() {
    printf("Discovering devices...\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        strcpy(devices[i].name, "Device ");
        sprintf(&devices[i].name[7], "%d", i + 1);
        devices[i].status = -1;
        devices[i].power = 0;
    }
}

void updateDeviceStatus(int deviceId, int status) {
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (devices[i].status == -1 && strcmp(devices[i].name, "Device ") == 0) {
            devices[i].status = deviceId;
            strcat(devices[i].name, &devices[i].status);
            break;
        }
    }
}

void turnOnOffDevice(int deviceId, int power) {
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (devices[i].status == deviceId) {
            devices[i].power = power;
            if (power == 1) {
                printf("Turning on device %s...\n", devices[i].name);
            } else {
                printf("Turning off device %s...\n", devices[i].name);
            }
            break;
        }
    }
}

int main() {
    discoverDevices();
    int choice;
    while (1) {
        printf("1. Discover devices\n2. Turn on/off device\n3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            discoverDevices();
        } else if (choice == 2) {
            int deviceId, power;
            printf("Enter device ID: ");
            scanf("%d", &deviceId);
            printf("Enter power (0 or 1): ");
            scanf("%d", &power);
            turnOnOffDevice(deviceId, power);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}