//FormAI DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global variables
int current_light_intensity = 50; // A value that represents the current light intensity (0-100)
bool is_bulb_on = true; // A value that represents whether the light bulb is on or off

// Function to increase the light intensity by 10
void increase_light_intensity() {
    if (current_light_intensity + 10 <= 100) {
        current_light_intensity += 10;
        printf("Light intensity has been increased to %d%%\n", current_light_intensity);
    } else {
        printf("Light intensity is already at maximum.\n");
    }
}

// Function to decrease the light intensity by 10
void decrease_light_intensity() {
    if (current_light_intensity - 10 >= 0) {
        current_light_intensity -= 10;
        printf("Light intensity has been decreased to %d%%\n", current_light_intensity);
    } else {
        printf("Light intensity is already at minimum.\n");
    }
}

// Function to turn on the light bulb
void turn_on_light() {
    if (!is_bulb_on) {
        is_bulb_on = true;
        printf("The light bulb has been turned on.\n");
    } else {
        printf("The light is already on.\n");
    }
}

// Function to turn off the light bulb
void turn_off_light() {
    if (is_bulb_on) {
        is_bulb_on = false;
        printf("The light bulb has been turned off.\n");
    } else {
        printf("The light is already off.\n");
    }
}

// Main function
int main() {
    // Print welcome message
    printf("Welcome to Smart Home Light Control System.\n");

    // Start an infinite loop to receive user input
    while (true) {
        // Print current status
        printf("Current light intensity: %d%%\n", current_light_intensity);
        printf("Light bulb is %s.\n", is_bulb_on ? "on" : "off");

        // Print menu
        printf("\nPlease select an option:\n");
        printf("1. Increase light intensity\n");
        printf("2. Decrease light intensity\n");
        printf("3. Turn on the light bulb\n");
        printf("4. Turn off the light bulb\n");
        printf("5. Exit\n");

        // Receive user input
        int option;
        printf("Your option: ");
        scanf("%d", &option);

        // Process user input
        switch (option) {
            case 1:
                increase_light_intensity();
                break;
            case 2:
                decrease_light_intensity();
                break;
            case 3:
                turn_on_light();
                break;
            case 4:
                turn_off_light();
                break;
            case 5:
                // Exit the program
                printf("Thank you for using Smart Home Light Control System.\n");
                exit(0);
            default:
                printf("Invalid option selected. Please try again.\n");
        }
    }
    return 0;
}