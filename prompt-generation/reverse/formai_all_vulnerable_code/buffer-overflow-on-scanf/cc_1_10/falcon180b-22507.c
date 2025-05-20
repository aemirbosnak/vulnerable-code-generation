//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_DEVICES 5

// Device states
enum {
    OFF = 0,
    ON = 1
};

// Device structure
typedef struct {
    char name[20];
    int state;
} Device;

// Function prototypes
void init_devices(Device* devices);
void print_devices(Device* devices);
void toggle_device(Device* devices, int index);

int main() {
    Device devices[NUM_DEVICES];

    init_devices(devices);

    while (true) {
        printf("Current device states:\n");
        print_devices(devices);

        int choice;
        printf("Enter the index of the device you want to toggle (0-4): ");
        scanf("%d", &choice);

        toggle_device(devices, choice);
    }

    return 0;
}

void init_devices(Device* devices) {
    for (int i = 0; i < NUM_DEVICES; i++) {
        sprintf(devices[i].name, "Device %d", i + 1);
        devices[i].state = OFF;
    }
}

void print_devices(Device* devices) {
    for (int i = 0; i < NUM_DEVICES; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].state == ON? "ON" : "OFF");
    }
}

void toggle_device(Device* devices, int index) {
    if (index >= 0 && index < NUM_DEVICES) {
        devices[index].state = devices[index].state == ON? OFF : ON;
        printf("Toggled device %s to %s\n", devices[index].name, devices[index].state == ON? "ON" : "OFF");
    } else {
        printf("Invalid device index\n");
    }
}