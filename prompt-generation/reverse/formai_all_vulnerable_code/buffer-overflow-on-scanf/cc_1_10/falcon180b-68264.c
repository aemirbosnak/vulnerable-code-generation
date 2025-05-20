//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[20];
    int status;
    int pin;
} device;

void initialize_devices() {
    device devices[MAX_DEVICES];
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {
        strcpy(devices[i].name, "Device ");
        sprintf(&devices[i].name[7], "%d", i + 1);
        devices[i].status = 0;
        devices[i].pin = i + 1;
    }
}

void print_devices(device devices[]) {
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {
        if (devices[i].status == 1) {
            printf("Device %s is ON\n", devices[i].name);
        } else {
            printf("Device %s is OFF\n", devices[i].name);
        }
    }
}

void turn_on(device devices[], int pin) {
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {
        if (devices[i].pin == pin) {
            devices[i].status = 1;
            printf("Turning on device %s\n", devices[i].name);
            break;
        }
    }
}

void turn_off(device devices[], int pin) {
    int i;
    for (i = 0; i < MAX_DEVICES; i++) {
        if (devices[i].pin == pin) {
            devices[i].status = 0;
            printf("Turning off device %s\n", devices[i].name);
            break;
        }
    }
}

int main() {
    device devices[MAX_DEVICES];
    initialize_devices(devices);
    int choice;
    while (1) {
        printf("\nSmart Home Automation\n");
        printf("1. Turn on device\n");
        printf("2. Turn off device\n");
        printf("3. Print status of devices\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter pin number of device: ");
            int pin;
            scanf("%d", &pin);
            turn_on(devices, pin);
            break;
        case 2:
            printf("Enter pin number of device: ");
            int pin1;
            scanf("%d", &pin1);
            turn_off(devices, pin1);
            break;
        case 3:
            print_devices(devices);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}