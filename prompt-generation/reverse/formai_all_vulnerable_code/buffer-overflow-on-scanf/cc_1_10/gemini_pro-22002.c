//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Cyberpunk
// Neon City Smart Home Automation System v1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Smart device definitions
typedef struct {
    char *name;
    int state; // 0 for off, 1 for on
} smart_device;

// List of smart devices
smart_device devices[] = {
    { "lights", 0 },
    { "thermostat", 0 },
    { "security system", 0 },
    { "door lock", 0 },
    { "coffee maker", 0 }
};

// Function to print a list of smart devices
void print_devices() {
    printf("Available smart devices:\n");
    for (int i = 0; i < sizeof(devices) / sizeof(devices[0]); i++) {
        printf(" - %s\n", devices[i].name);
    }
}

// Function to toggle the state of a smart device
void toggle_device(char *name) {
    for (int i = 0; i < sizeof(devices) / sizeof(devices[0]); i++) {
        if (strcmp(devices[i].name, name) == 0) {
            devices[i].state = !devices[i].state;
            printf("%s is now %s.\n", name, devices[i].state ? "on" : "off");
            return;
        }
    }

    printf("Unknown device: %s\n", name);
}

// Main program
int main() {
    // Print a welcome message
    printf("Welcome to the Neon City Smart Home Automation System!\n");

    // Print a list of available smart devices
    print_devices();

    // Get user input
    char input[100];
    printf("\nEnter the name of the device you want to toggle, or type 'exit' to quit: ");
    scanf("%s", input);

    // Process user input
    while (strcmp(input, "exit") != 0) {
        toggle_device(input);

        // Get user input
        printf("\nEnter the name of the device you want to toggle, or type 'exit' to quit: ");
        scanf("%s", input);
    }

    // Print a goodbye message
    printf("Goodbye!");

    return 0;
}