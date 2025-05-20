//FormAI DATASET v1.0 Category: Smart home light control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of lights the house can have
#define MAX_LIGHTS 10

// Struct to hold information about a light
typedef struct {
    bool is_on;
    int brightness;
} Light;

int main() {
    // Create an array of lights
    Light lights[MAX_LIGHTS];

    // Initialize all the lights to be off with a brightness of 0
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].is_on = false;
        lights[i].brightness = 0;
    }

    // Begin the main loop
    while (true) {
        // Print the current state of all the lights
        printf("Current state of lights:\n");
        for (int i = 0; i < MAX_LIGHTS; i++) {
            printf("Light %d: %s, brightness %d\n", i + 1, lights[i].is_on ? "ON" : "OFF", lights[i].brightness);
        }

        // Prompt the user for a light to control
        printf("\nEnter the number of the light you want to control (or enter -1 to exit): ");
        int choice;
        scanf("%d", &choice);

        // Handle the user's choice
        if (choice == -1) {
            // User chose to exit, so break out of the loop
            break;
        } else if (choice > MAX_LIGHTS || choice <= 0) {
            // User entered an invalid light number
            printf("Invalid light number. Please enter a number between 1 and %d.\n", MAX_LIGHTS);
            continue;
        } else {
            // User entered a valid light number, so prompt for the action to take
            int light_index = choice - 1;
            printf("\nEnter the action you want to take for light %d:\n", choice);
            printf("1. Turn on\n");
            printf("2. Turn off\n");
            printf("3. Set brightness\n");
            printf("4. Cancel\n");
            int action;
            scanf("%d", &action);

            switch (action) {
                case 1:
                    // Turn on the light
                    lights[light_index].is_on = true;
                    printf("Light %d turned on.\n", choice);
                    break;
                case 2:
                    // Turn off the light
                    lights[light_index].is_on = false;
                    printf("Light %d turned off.\n", choice);
                    break;
                case 3:
                    // Set the brightness of the light
                    printf("Enter the brightness level (0-100): ");
                    int brightness;
                    scanf("%d", &brightness);
                    if (brightness < 0 || brightness > 100) {
                        printf("Invalid brightness level. Please enter a value between 0 and 100.\n");
                    } else {
                        lights[light_index].brightness = brightness;
                        printf("Brightness level of light %d set to %d.\n", choice, brightness);
                    }
                    break;
                case 4:
                    // Do nothing, cancel the action
                    printf("Action cancelled.\n");
                    break;
                default:
                    // Invalid action entered
                    printf("Invalid action. Please enter a number between 1 and 4.\n");
                    break;
            }
        }
    }

    return 0;
}