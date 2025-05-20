//FormAI DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define constant values to represent the states of the lights
#define OFF 0
#define ON 1

// Define the number of lights in the smart home
#define NUM_OF_LIGHTS 3

// Define the maximum brightness level for each light
#define MAX_BRIGHTNESS 5

// Define a structure to represent each light in the smart home
struct Light {
    int state; // 0 = OFF, 1 = ON
    int brightness; // 0 = dim, 1-5 = increasing brightness
};

// Declare a function to print the status of all lights in the smart home
void printStatus(struct Light lights[]);

int main() {
    // Create an array of struct Light to represent the lights in the smart home
    struct Light lights[NUM_OF_LIGHTS];

    // Initialize the state and brightness of each light
    for (int i = 0; i < NUM_OF_LIGHTS; i++) {
        lights[i].state = OFF;
        lights[i].brightness = 0;
    }

    // Show the initial status of the lights in the smart home
    printf("Welcome to the smart home light control system!\n");
    printStatus(lights);

    // Enter a loop to accept user input to control the lights
    while (1) {
        // Show the available options to the user
        printf("What would you like to do?\n");
        printf("1. Turn on/off a light\n");
        printf("2. Adjust the brightness of a light\n");
        printf("3. Quit\n");

        // Accept user input to select an option
        int option;
        scanf("%d", &option);

        if (option == 1) {
            // Turn on/off a light
            printf("Which light would you like to turn on/off (1-%d)?\n", NUM_OF_LIGHTS);
            int lightIndex;
            scanf("%d", &lightIndex);

            // Validate the user input
            if (lightIndex < 1 || lightIndex > NUM_OF_LIGHTS) {
                printf("Invalid input! Please enter a number between 1 and %d\n", NUM_OF_LIGHTS);
                continue;
            }

            // Toggle the state of the selected light
            struct Light *light = &lights[lightIndex-1];
            if (light->state == ON) {
                light->state = OFF;
            } else {
                light->state = ON;
            }

            // Show the updated status of the lights in the smart home
            printStatus(lights);

        } else if (option == 2) {
            // Adjust the brightness of a light
            printf("Which light would you like to adjust the brightness of (1-%d)?\n", NUM_OF_LIGHTS);
            int lightIndex;
            scanf("%d", &lightIndex);

            // Validate the user input
            if (lightIndex < 1 || lightIndex > NUM_OF_LIGHTS) {
                printf("Invalid input! Please enter a number between 1 and %d\n", NUM_OF_LIGHTS);
                continue;
            }

            // Prompt the user for the new brightness level
            printf("Enter the new brightness level of the selected light (0-%d):\n", MAX_BRIGHTNESS);
            int newBrightness;
            scanf("%d", &newBrightness);

            // Validate the user input
            if (newBrightness < 0 || newBrightness > MAX_BRIGHTNESS) {
                printf("Invalid input! Please enter a number between 0 and %d\n", MAX_BRIGHTNESS);
                continue;
            }

            // Set the new brightness level of the selected light
            struct Light *light = &lights[lightIndex-1];
            light->brightness = newBrightness;

            // Show the updated status of the lights in the smart home
            printStatus(lights);

        } else if (option == 3) {
            // Quit the program
            printf("Quitting the smart home light control system...\n");
            break;

        } else {
            // Invalid option selected
            printf("Invalid option! Please select a valid option (1-3)\n");
        }
    }

    return 0;
}

// Implementation of the printStatus function
void printStatus(struct Light lights[]) {
    printf("Current status of the lights in the smart home:\n");
    for (int i = 0; i < NUM_OF_LIGHTS; i++) {
        printf("Light %d ", i+1);
        if (lights[i].state == OFF) {
            printf("is OFF\n");
        } else {
            printf("is ON with brightness level %d\n", lights[i].brightness);
        }
    }
    printf("\n");
}