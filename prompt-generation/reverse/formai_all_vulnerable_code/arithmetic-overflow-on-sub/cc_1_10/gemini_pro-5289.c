//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Create a struct to represent a light
typedef struct {
    bool is_on;
    int brightness;
} light_t;

// Create an array of lights
light_t lights[MAX_LIGHTS];

// Define the main function
int main() {
    // Initialize the lights
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].is_on = false;
        lights[i].brightness = 0;
    }

    // Get the user's input
    char input[100];
    printf("Enter a command (on, off, brightness, or exit): ");
    scanf("%s", input);

    // Process the user's input
    while (strcmp(input, "exit") != 0) {
        if (strcmp(input, "on") == 0) {
            // Turn on the light
            int light_number;
            printf("Enter the light number (1-%d): ", MAX_LIGHTS);
            scanf("%d", &light_number);
            lights[light_number - 1].is_on = true;
        } else if (strcmp(input, "off") == 0) {
            // Turn off the light
            int light_number;
            printf("Enter the light number (1-%d): ", MAX_LIGHTS);
            scanf("%d", &light_number);
            lights[light_number - 1].is_on = false;
        } else if (strcmp(input, "brightness") == 0) {
            // Set the light's brightness
            int light_number;
            int brightness;
            printf("Enter the light number (1-%d): ", MAX_LIGHTS);
            scanf("%d", &light_number);
            printf("Enter the brightness (0-100): ");
            scanf("%d", &brightness);
            lights[light_number - 1].brightness = brightness;
        }

        // Get the user's input
        printf("Enter a command (on, off, brightness, or exit): ");
        scanf("%s", input);
    }

    // Exit the program
    return 0;
}