//FormAI DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for devices
#define LIGHT 1
#define FAN 2
#define TV 3
#define DOOR 4

// Define constants for states
#define OFF 0
#define ON 1

// Create a struct to represent a device
struct Device {
    int id;
    int state;
};

// Create an array to hold all devices
struct Device devices[4];

// Create a function to update the state of a device
void updateDevice(int id, int state) {
    for (int i = 0; i < 4; i++) {
        if (devices[i].id == id) {
            devices[i].state = state;
            printf("Device %d is now %s.\n", id, state == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Device %d not found.\n", id);
}

// Main function to run the smart home automation system
int main() {
    // Initialize all devices to OFF state
    for (int i = 0; i < 4; i++) {
        devices[i].id = i + 1;
        devices[i].state = OFF;
    }

    // Control loop
    bool running = true;
    while (running) {
        // Prompt user to select a device to control
        printf("Which device would you like to control?\n");
        printf("1. Light\n");
        printf("2. Fan\n");
        printf("3. TV\n");
        printf("4. Door\n");
        printf("5. Quit\n> ");

        // Read user input
        int selection;
        scanf("%d", &selection);

        // Handle user input
        switch (selection) {
            case 1:
                // Light
                printf("What would you like to do with the light?\n");
                printf("1. Turn on\n");
                printf("2. Turn off\n> ");
                int lightSelection;
                scanf("%d", &lightSelection);
                switch (lightSelection) {
                    case 1:
                        updateDevice(LIGHT, ON);
                        break;
                    case 2:
                        updateDevice(LIGHT, OFF);
                        break;
                    default:
                        printf("Invalid selection.\n");
                }
                break;
            case 2:
                // Fan
                printf("What would you like to do with the fan?\n");
                printf("1. Turn on\n");
                printf("2. Turn off\n> ");
                int fanSelection;
                scanf("%d", &fanSelection);
                switch (fanSelection) {
                    case 1:
                        updateDevice(FAN, ON);
                        break;
                    case 2:
                        updateDevice(FAN, OFF);
                        break;
                    default:
                        printf("Invalid selection.\n");
                }
                break;
            case 3:
                // TV
                printf("What would you like to do with the TV?\n");
                printf("1. Turn on\n");
                printf("2. Turn off\n> ");
                int tvSelection;
                scanf("%d", &tvSelection);
                switch (tvSelection) {
                    case 1:
                        updateDevice(TV, ON);
                        break;
                    case 2:
                        updateDevice(TV, OFF);
                        break;
                    default:
                        printf("Invalid selection.\n");
                }
                break;
            case 4:
                // Door
                printf("What would you like to do with the door?\n");
                printf("1. Open\n");
                printf("2. Close\n> ");
                int doorSelection;
                scanf("%d", &doorSelection);
                switch (doorSelection) {
                    case 1:
                        updateDevice(DOOR, ON);
                        break;
                    case 2:
                        updateDevice(DOOR, OFF);
                        break;
                    default:
                        printf("Invalid selection.\n");
                }
                break;
            case 5:
                // Quit
                printf("Goodbye!\n");
                running = false;
                break;
            default:
                printf("Invalid selection.\n");
        }
    }

    return 0;
}