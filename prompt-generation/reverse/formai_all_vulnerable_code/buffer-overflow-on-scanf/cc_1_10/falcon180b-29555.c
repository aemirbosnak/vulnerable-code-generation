//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[50];
    int state;
} device_t;

device_t devices[MAX_DEVICES];

int main() {
    int num_devices = 0;

    while (num_devices < MAX_DEVICES) {
        printf("Enter device name: ");
        scanf("%s", devices[num_devices].name);
        printf("Enter device state (0 for off, 1 for on): ");
        scanf("%d", &devices[num_devices].state);
        num_devices++;
    }

    char command[50];
    while (1) {
        printf("Enter command (on/off/status): ");
        scanf("%s", command);

        if (strcmp(command, "on") == 0) {
            int device_index;
            printf("Enter device index: ");
            scanf("%d", &device_index);
            devices[device_index].state = 1;
            printf("%s turned on.\n", devices[device_index].name);
        } else if (strcmp(command, "off") == 0) {
            int device_index;
            printf("Enter device index: ");
            scanf("%d", &device_index);
            devices[device_index].state = 0;
            printf("%s turned off.\n", devices[device_index].name);
        } else if (strcmp(command, "status") == 0) {
            int device_index;
            printf("Enter device index: ");
            scanf("%d", &device_index);
            if (devices[device_index].state == 1) {
                printf("%s is on.\n", devices[device_index].name);
            } else {
                printf("%s is off.\n", devices[device_index].name);
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}