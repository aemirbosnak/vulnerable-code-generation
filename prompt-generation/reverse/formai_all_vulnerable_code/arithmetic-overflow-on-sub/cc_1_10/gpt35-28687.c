//FormAI DATASET v1.0 Category: Smart home automation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the structure for our smart home device
typedef struct {
    int device_id;
    char device_name[50];
    int device_status;
} device_t;

// Function to turn on a device
void turn_on_device(device_t *device) {
    device->device_status = 1;
    printf("%s turned on.\n", device->device_name);
}

// Function to turn off a device
void turn_off_device(device_t *device) {
    device->device_status = 0;
    printf("%s turned off.\n", device->device_name);
}

int main() {
    // Create an array to hold all of our smart home devices
    device_t devices[4];

    // Populate the device array with sample devices
    devices[0] = (device_t){1, "Living Room Lights", 0};
    devices[1] = (device_t){2, "Kitchen Lights", 0};
    devices[2] = (device_t){3, "Bedroom Lights", 0};
    devices[3] = (device_t){4, "Front Door Lock", 0};

    // Define a variable to hold the user's input
    int user_choice;

    // Keep looping until the user chooses to exit
    while (1) {
        // Print out the list of devices and their statuses
        printf("Current Devices:\n");
        for (int i = 0; i < 4; i++) {
            printf("%d. %s - %s\n", devices[i].device_id, devices[i].device_name, devices[i].device_status ? "On" : "Off");
        }

        // Ask the user what they want to do
        printf("What would you like to do?\n");
        printf("1. Turn on a device\n");
        printf("2. Turn off a device\n");
        printf("3. Exit\n");

        // Get the user's input
        scanf("%d", &user_choice);

        // Handle the user's input appropriately
        switch (user_choice) {
            case 1:
                // Ask the user which device they want to turn on
                printf("Which device would you like to turn on?\n");
                for (int i = 0; i < 4; i++) {
                    printf("%d. %s\n", devices[i].device_id, devices[i].device_name);
                }
                scanf("%d", &user_choice);
                turn_on_device(&devices[user_choice - 1]);
                break;
            case 2:
                // Ask the user which device they want to turn off
                printf("Which device would you like to turn off?\n");
                for (int i = 0; i < 4; i++) {
                    printf("%d. %s\n", devices[i].device_id, devices[i].device_name);
                }
                scanf("%d", &user_choice);
                turn_off_device(&devices[user_choice - 1]);
                break;
            case 3:
                // Exit the program
                printf("Exiting program.\n");
                exit(0);
            default:
                // If the user enters an invalid input, display an error message
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}