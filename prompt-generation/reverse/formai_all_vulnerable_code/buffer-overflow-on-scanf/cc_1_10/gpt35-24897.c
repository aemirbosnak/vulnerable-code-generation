//FormAI DATASET v1.0 Category: Smart home automation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 5
#define MAX_NAME_LEN 20

struct Device {
    char name[MAX_NAME_LEN];
    int status; // 0 for off, 1 for on
};

struct SmartHome {
    struct Device devices[MAX_DEVICES];
    int num_devices;
};

void initSmartHome(struct SmartHome* home) {
    home->num_devices = 0;
}

void addDevice(struct SmartHome* home, char* name) {
    if (home->num_devices == MAX_DEVICES) {
        printf("Cannot add device - maximum number of devices reached.\n");
    } else {
        struct Device d;
        strncpy(d.name, name, MAX_NAME_LEN);
        d.status = 0; // device is initially off
        home->devices[home->num_devices] = d;
        home->num_devices++;
        printf("Device %s added successfully.\n", name);
    }
}

void printDevices(struct SmartHome* home) {
    printf("Current Devices:\n");
    for (int i = 0; i < home->num_devices; i++) {
        printf("%d. %s [%s]\n", i+1, home->devices[i].name, (home->devices[i].status == 0 ? "OFF" : "ON"));
    }
}

void toggleDevice(struct SmartHome* home, int index) {
    if (index >= 1 && index <= home->num_devices) {
        struct Device* d = &home->devices[index-1];
        if (d->status == 0) {
            d->status = 1;
            printf("%s turned ON.\n", d->name);
        } else {
            d->status = 0;
            printf("%s turned OFF.\n", d->name);
        }
    } else {
        printf("Invalid device index.\n");
    }
}

int main() {
    printf("Welcome to Smart Home Automation!\n");
    struct SmartHome home;
    initSmartHome(&home);
    int choice = 0;
    do {
        printf("\nPlease choose from the following options:\n");
        printf("1. Add a device.\n");
        printf("2. Toggle device.\n");
        printf("3. Show device list.\n");
        printf("4. Exit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter device name: ");
                char name[MAX_NAME_LEN];
                scanf("%s", name);
                addDevice(&home, name);
                break;
            }
            case 2: {
                printDevices(&home);
                printf("Enter device index to toggle: ");
                int index;
                scanf("%d", &index);
                toggleDevice(&home, index);
                break;
            }
            case 3: {
                printDevices(&home);
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 4);
    return 0;
}