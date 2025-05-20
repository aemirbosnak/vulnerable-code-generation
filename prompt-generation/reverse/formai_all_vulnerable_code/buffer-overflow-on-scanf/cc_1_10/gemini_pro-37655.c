//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: rigorous
// Smart Home Automation Example in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define device types
typedef enum {
    LIGHT,
    FAN,
    AC,
    DOOR_LOCK,
    SMART_TV
} device_type;

// Define device statuses
typedef enum {
    ON,
    OFF
} device_status;

// Define device names
char *device_names[] = {
    "Light",
    "Fan",
    "AC",
    "Door Lock",
    "Smart TV"
};

// Define device status array
device_status device_status_arr[5];

// Function to print device status
void print_device_status(device_type device) {
    printf("%s is %s\n", device_names[device], device_status_arr[device] == ON ? "ON" : "OFF");
}

// Function to toggle device status
void toggle_device(device_type device) {
    device_status_arr[device] = device_status_arr[device] == ON ? OFF : ON;
}

// Function to handle user input
void handle_user_input() {
    char input[100];
    printf("Enter a command: ");
    scanf("%s", input);

    if (strcmp(input, "list") == 0) {
        // List all devices and their status
        for (device_type device = LIGHT; device < SMART_TV; device++) {
            print_device_status(device);
        }
    } else if (strcmp(input, "on") == 0) {
        // Turn on a specific device
        char device_name[100];
        printf("Enter device name: ");
        scanf("%s", device_name);

        for (device_type device = LIGHT; device < SMART_TV; device++) {
            if (strcmp(device_name, device_names[device]) == 0) {
                toggle_device(device);
                print_device_status(device);
                break;
            }
        }
    } else if (strcmp(input, "off") == 0) {
        // Turn off a specific device
        char device_name[100];
        printf("Enter device name: ");
        scanf("%s", device_name);

        for (device_type device = LIGHT; device < SMART_TV; device++) {
            if (strcmp(device_name, device_names[device]) == 0) {
                toggle_device(device);
                print_device_status(device);
                break;
            }
        }
    } else if (strcmp(input, "exit") == 0) {
        // Exit the program
        exit(0);
    } else {
        // Invalid input
        printf("Invalid input. Please enter a valid command.\n");
    }
}

int main() {
    // Initialize device status array
    for (device_type device = LIGHT; device < SMART_TV; device++) {
        device_status_arr[device] = OFF;
    }

    // Main loop
    while (true) {
        handle_user_input();
    }

    return 0;
}