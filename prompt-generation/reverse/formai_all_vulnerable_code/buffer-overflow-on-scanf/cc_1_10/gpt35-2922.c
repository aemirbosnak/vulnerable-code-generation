//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Device {
    char name[20];
    bool status;
};

void printDevice(struct Device device) {
    printf("%s is currently %s\n", device.name, device.status ? "ON" : "OFF");
}

int main() {
    struct Device devices[3] = { {"Light", false}, {"Fan", false}, {"TV", false} };
    int choice, deviceChoice;
    bool powerOn = true;

    while (powerOn) {
        printf("Select an option:\n");
        printf("1. Turn on a device\n");
        printf("2. Turn off a device\n");
        printf("3. View all devices\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Which device would you like to turn on?\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. %s\n", i+1, devices[i].name);
                }
                printf("Enter device number: ");
                scanf("%d", &deviceChoice);
                printf("\n");

                if (deviceChoice < 1 || deviceChoice > 3) {
                    printf("Invalid device choice, please try again\n\n");
                } else if (devices[deviceChoice-1].status == true) {
                    printf("Device is already on, please try again\n\n");
                } else {
                    devices[deviceChoice-1].status = true;
                    printf("%s has been turned on\n\n", devices[deviceChoice-1].name);
                }
                break;

            case 2:
                printf("Which device would you like to turn off?\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. %s\n", i+1, devices[i].name);
                }
                printf("Enter device number: ");
                scanf("%d", &deviceChoice);
                printf("\n");

                if (deviceChoice < 1 || deviceChoice > 3) {
                    printf("Invalid device choice, please try again\n\n");
                } else if (devices[deviceChoice-1].status == false) {
                    printf("Device is already off, please try again\n\n");
                } else {
                    devices[deviceChoice-1].status = false;
                    printf("%s has been turned off\n\n", devices[deviceChoice-1].name);
                }
                break;

            case 3:
                printf("Device status:\n");
                for (int i = 0; i < 3; i++) {
                    printDevice(devices[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Exiting program, thank you for using!\n");
                powerOn = false;
                break;

            default:
                printf("Invalid option, please try again\n\n");
                break;
        }
    }

    return 0;
}