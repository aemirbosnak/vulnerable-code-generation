//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of devices
#define MAX_DEVICES 10

// Define the device structure
typedef struct {
    char name[50];
    int status;
    int port;
} device;

// Define the main function
int main() {
    // Initialize the devices
    device devices[MAX_DEVICES] = {{"Living Room Lamp", 0, 1},
                                   {"Bedroom Lamp", 0, 2},
                                   {"Kitchen Light", 0, 3},
                                   {"TV", 0, 4},
                                   {"Air Conditioner", 0, 5},
                                   {"Heater", 0, 6},
                                   {"Fan", 0, 7},
                                   {"Coffee Maker", 0, 8},
                                   {"Microwave", 0, 9},
                                   {"Oven", 0, 10}};

    // Print the device list
    printf("Device List:\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        printf("%d. %s - Port %d\n", i + 1, devices[i].name, devices[i].port);
    }

    // Loop through the main menu
    int choice;
    do {
        // Print the main menu
        printf("\nMain Menu:\n");
        printf("1. Turn device on/off\n");
        printf("2. Set device schedule\n");
        printf("3. View device status\n");
        printf("4. Exit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                // Turn device on/off
                printf("Enter the device number: ");
                scanf("%d", &choice);
                printf("Enter 1 to turn on or 0 to turn off: ");
                scanf("%d", &devices[choice - 1].status);
                break;
            case 2:
                // Set device schedule
                printf("Enter the device number: ");
                scanf("%d", &choice);
                printf("Enter the schedule (24-hour format): ");
                scanf("%s", devices[choice - 1].name);
                break;
            case 3:
                // View device status
                printf("Enter the device number: ");
                scanf("%d", &choice);
                if (devices[choice - 1].status == 1) {
                    printf("%s is on.\n", devices[choice - 1].name);
                } else {
                    printf("%s is off.\n", devices[choice - 1].name);
                }
                break;
            case 4:
                // Exit the program
                printf("Exiting program...\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice, please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}