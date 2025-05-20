//FormAI DATASET v1.0 Category: Smart home light control ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIGHTS 10 // Maximum number of lights in the smart home

// Structure definition for a light
typedef struct {
    int id; // Unique ID for the light
    int brightness; // Current brightness of the light (0-100)
} Light;

// Function to turn on a light
void turnOn(Light *light) {
    light->brightness = 100;
    printf("Light %d turned on!\n", light->id);
}

// Function to turn off a light
void turnOff(Light *light) {
    light->brightness = 0;
    printf("Light %d turned off!\n", light->id);
}

// Main function
int main() {
    Light lights[MAX_LIGHTS]; // Array to hold all the lights in the smart home
    int numLights = 0; // Number of lights currently in the smart home

    // Loop to add lights to the smart home
    while (numLights < MAX_LIGHTS) {
        // Prompt the user for the ID of the new light
        printf("Enter the ID of light %d (or -1 to stop adding lights): ", numLights + 1);
        int id;
        scanf("%d", &id);
        if (id == -1) {
            // User wants to stop adding lights
            break;
        }

        // Create a new light with the specified ID and a brightness of 0
        Light newLight = { id, 0 };

        // Add the new light to the array of lights and increment the counter
        lights[numLights] = newLight;
        numLights++;
    }

    // Loop to control the lights in the smart home
    while (1) {
        // Prompt the user for the ID of the light they want to control
        printf("Enter the ID of the light you want to control (or -1 to quit): ");
        int id;
        scanf("%d", &id);
        if (id == -1) {
            // User wants to quit
            break;
        }

        // Find the light with the specified ID
        Light *selectedLight = NULL;
        for (int i = 0; i < numLights; i++) {
            if (lights[i].id == id) {
                selectedLight = &lights[i];
                break;
            }
        }

        // If no light was found, prompt the user to try again
        if (selectedLight == NULL) {
            printf("Light not found. Please try again.\n");
            continue;
        }

        // Prompt the user for the action they want to take
        printf("Enter 1 to turn on the light, 2 to turn it off, or 3 to set the brightness: ");
        int action;
        scanf("%d", &action);

        // Perform the selected action
        switch (action) {
            case 1:
                turnOn(selectedLight);
                break;
            case 2:
                turnOff(selectedLight);
                break;
            case 3:
                // Prompt the user for the desired brightness level
                printf("Enter the desired brightness level (0-100): ");
                int brightness;
                scanf("%d", &brightness);

                // Clamp the brightness level to the appropriate range
                if (brightness < 0) {
                    brightness = 0;
                } else if (brightness > 100) {
                    brightness = 100;
                }

                // Set the brightness of the selected light
                selectedLight->brightness = brightness;
                printf("Light %d brightness set to %d\n", selectedLight->id, selectedLight->brightness);
                break;
            default:
                printf("Invalid action. Please try again.\n");
                break;
        }
    }

    return 0;
}