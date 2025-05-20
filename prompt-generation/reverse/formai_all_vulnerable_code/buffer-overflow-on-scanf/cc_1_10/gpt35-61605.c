//FormAI DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the states of the devices
#define DEVICE_OFF 0
#define DEVICE_ON 1

// Define the devices
#define LIGHT 0
#define BLINDS 1
#define AC 2

// Define the commands for the devices
#define COMMAND_TURN_ON 0
#define COMMAND_TURN_OFF 1
#define COMMAND_TOGGLE 2

// Define the initial state of the devices
int devices[3] = {DEVICE_OFF, DEVICE_OFF, DEVICE_OFF};

// Define the function to turn on the device
void turn_on(int device) {
    devices[device] = DEVICE_ON;
    printf("turned on device %d\n", device);
}

// Define the function to turn off the device
void turn_off(int device) {
    devices[device] = DEVICE_OFF;
    printf("turned off device %d\n", device);
}

// Define the function to toggle the device
void toggle(int device) {
    if(devices[device] == DEVICE_OFF) {
        devices[device] = DEVICE_ON;
        printf("turned on device %d\n", device);
    } else {
        devices[device] = DEVICE_OFF;
        printf("turned off device %d\n", device);
    }
}

int main() {
    int command;
    int device;
    bool running = true;
    
    printf("Smart Home Automation Program\n");
    
    while(running) {
        // Print the menu
        printf("Devices:\n");
        printf("1. Light\n");
        printf("2. Blinds\n");
        printf("3. AC\n");
        printf("4. Quit\n");
        printf("Enter device number or 4 to quit: ");
        
        // Get the user input
        scanf("%d", &device);
        
        if(device == 4) {
            // Quit the program
            running = false;
        } else if(device < 1 || device > 3) {
            // Invalid input
            printf("Invalid device number\n");
        } else {
            // Print the device commands
            printf("Commands:\n");
            printf("0. Turn on\n");
            printf("1. Turn off\n");
            printf("2. Toggle\n");
            printf("Enter command number: ");
            
            // Get the user input
            scanf("%d", &command);
            
            if(command < 0 || command > 2) {
                // Invalid input
                printf("Invalid command number\n");
            } else {
                // Execute the command
                switch(command) {
                    case COMMAND_TURN_ON:
                        turn_on(device-1);
                        break;
                    case COMMAND_TURN_OFF:
                        turn_off(device-1);
                        break;
                    case COMMAND_TOGGLE:
                        toggle(device-1);
                        break;
                }
            }
        }
    }
    
    return 0;
}