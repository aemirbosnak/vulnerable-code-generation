//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEVICES 10

typedef struct {
    char name[20];
    int status;
} Device;

int main() {
    int num_devices;
    Device devices[MAX_DEVICES];

    printf("Welcome to your Smart Home!\n");
    printf("How many devices do you have? ");
    scanf("%d", &num_devices);

    for (int i = 0; i < num_devices; i++) {
        printf("Enter the name of device %d: ", i+1);
        scanf("%s", devices[i].name);
        devices[i].status = 0;
    }

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Turn on/off a device\n");
        printf("2. Check status of all devices\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the device: ");
                scanf("%s", devices[0].name);
                printf("Enter 1 to turn on or 0 to turn off: ");
                scanf("%d", &devices[0].status);
                break;
            case 2:
                for (int i = 0; i < num_devices; i++) {
                    printf("%s: %s\n", devices[i].name, devices[i].status? "On" : "Off");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}