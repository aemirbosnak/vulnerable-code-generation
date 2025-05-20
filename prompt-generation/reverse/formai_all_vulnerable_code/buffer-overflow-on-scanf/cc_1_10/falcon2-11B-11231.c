//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Device {
    char name[20];
    int status;
    int brightness;
    int temperature;
};

struct Device devices[3] = {
    {"Lamp", 0, 50, 20},
    {"Thermostat", 1, 100, 75},
    {"Lock", 2, 75, 30}
};

void initializeDevices() {
    for (int i = 0; i < 3; i++) {
        devices[i].status = 0;
        devices[i].brightness = 0;
        devices[i].temperature = 0;
    }
}

void updateDevices(int index) {
    if (index >= 0 && index < 3) {
        devices[index].status = 1;
    }
}

void printDevices() {
    for (int i = 0; i < 3; i++) {
        printf("Device %d: %s, Status: %d, Brightness: %d, Temperature: %d\n", i+1, devices[i].name, devices[i].status, devices[i].brightness, devices[i].temperature);
    }
}

int main() {
    initializeDevices();
    int index;
    while (1) {
        printf("Select a device to control:\n");
        printf("1. Lamp\n");
        printf("2. Thermostat\n");
        printf("3. Lock\n");
        printf("4. Exit\n");
        scanf("%d", &index);
        switch (index) {
            case 1:
                updateDevices(0);
                break;
            case 2:
                updateDevices(1);
                break;
            case 3:
                updateDevices(2);
                break;
            case 4:
                break;
            default:
                printf("Invalid input. Try again.\n");
        }
        printDevices();
        sleep(1);
    }
    return 0;
}