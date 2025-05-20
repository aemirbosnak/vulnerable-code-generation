//FormAI DATASET v1.0 Category: Smart home automation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEVICES 10

struct device {
    int id;
    char name[20];
    bool is_on;
};

void print_devices(struct device devices[], int num_devices) {
    printf("\nID\tDEVICE NAME\t\tSTATUS\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%d\t%s\t\t", devices[i].id, devices[i].name);
        if (devices[i].is_on)
            printf("ON\n");
        else
            printf("OFF\n");
    }
    printf("----------------------------------------\n");
}

void turn_on_device(struct device devices[], int num_devices, int device_id) {
    for (int i = 0; i < num_devices; i++) {
        if (devices[i].id == device_id)
            devices[i].is_on = true;
    }
    printf("Device %d is now turned ON.\n", device_id);
}

void turn_off_device(struct device devices[], int num_devices, int device_id) {
    for (int i = 0; i < num_devices; i++) {
        if (devices[i].id == device_id)
            devices[i].is_on = false;
    }
    printf("Device %d is now turned OFF.\n", device_id);
}

int main() {
    struct device devices[MAX_DEVICES];
    int num_devices = 0;
    int choice, device_id;

    while (1) {
        printf("\n----------------------------------------\n");
        printf("SMART HOME AUTOMATION SYSTEM\n");
        printf("----------------------------------------\n");
        printf("1. Add device\n");
        printf("2. Turn ON device\n");
        printf("3. Turn OFF device\n");
        printf("4. Show devices\n");
        printf("5. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_devices == MAX_DEVICES) {
                    printf("Sorry, maximum number of devices reached.\n");
                } else {
                    struct device dev;
                    dev.id = num_devices + 1;
                    printf("Enter device name: ");
                    scanf("%s", dev.name);
                    dev.is_on = false;
                    devices[num_devices] = dev;
                    printf("Device added successfully.\n");
                    num_devices++;
                }
                break;
            case 2:
                if (num_devices == 0) {
                    printf("Sorry, no devices found.\n");
                } else {
                    printf("Enter device ID: ");
                    scanf("%d", &device_id);
                    turn_on_device(devices, num_devices, device_id);
                }
                break;
            case 3:
                if (num_devices == 0) {
                    printf("Sorry, no devices found.\n");
                } else {
                    printf("Enter device ID: ");
                    scanf("%d", &device_id);
                    turn_off_device(devices, num_devices, device_id);
                }
                break;
            case 4:
                if (num_devices == 0) {
                    printf("Sorry, no devices found.\n");
                } else {
                    print_devices(devices, num_devices);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}