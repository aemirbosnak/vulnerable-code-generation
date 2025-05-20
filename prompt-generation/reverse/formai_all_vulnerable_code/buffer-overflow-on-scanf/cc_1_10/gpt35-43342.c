//FormAI DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_DEVICE_NAME 20

struct device {
    char name[MAX_DEVICE_NAME];
    bool status;
};

struct device devices[MAX_DEVICES];
int num_devices = 0;

void list_devices() {
    if(num_devices == 0) {
        printf("No devices available.\n");
    } else {
        printf("Devices:\n");
        for(int i=0; i<num_devices; i++) {
            printf("  %d. %s  %s\n", i+1, devices[i].name, devices[i].status ? "On" : "Off");
        }
    }
}

void add_device() {
    if(num_devices == MAX_DEVICES) {
        printf("Cannot add more devices.\n");
        return;
    }

    char name[MAX_DEVICE_NAME];
    printf("Enter device name: ");
    scanf("%s", name);

    strcpy(devices[num_devices].name, name);
    devices[num_devices].status = false;
    num_devices++;

    printf("Device added successfully.\n");
}

void switch_device(bool on) {
    int index;
    printf("Enter device index: ");
    scanf("%d", &index);

    if(index < 1 || index > num_devices) {
        printf("Invalid index.\n");
        return;
    }

    devices[index-1].status = on;

    printf("Device %s successfully.\n", on ? "turned on" : "turned off");
}

int main() {
    int choice;
    bool running = true;

    while(running) {
        printf("Smart Home Automation\n");
        printf("1. List Devices\n");
        printf("2. Add Device\n");
        printf("3. Turn On Device\n");
        printf("4. Turn Off Device\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                list_devices();
                break;

            case 2:
                add_device();
                break;

            case 3:
                switch_device(true);
                break;

            case 4:
                switch_device(false);
                break;

            case 0:
                printf("Goodbye!\n");
                running = false;
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}