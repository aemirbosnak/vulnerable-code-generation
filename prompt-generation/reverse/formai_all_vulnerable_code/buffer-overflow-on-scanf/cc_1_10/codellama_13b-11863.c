//Code Llama-13B DATASET v1.0 Category: Smart home light control ; Style: scientific
// Smart Home Light Control Program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_LIGHTS 5

int main() {
    // Initialize light states
    int light_states[NUM_LIGHTS] = {0};

    // Set initial light state
    light_states[0] = 1;

    // Loop until user exits
    while (1) {
        // Print light states
        printf("Light States: ");
        for (int i = 0; i < NUM_LIGHTS; i++) {
            printf("%d ", light_states[i]);
        }
        printf("\n");

        // Get user input
        char input[10];
        scanf("%s", input);

        // Parse input
        if (strcmp(input, "on") == 0) {
            // Turn on all lights
            for (int i = 0; i < NUM_LIGHTS; i++) {
                light_states[i] = 1;
            }
        } else if (strcmp(input, "off") == 0) {
            // Turn off all lights
            for (int i = 0; i < NUM_LIGHTS; i++) {
                light_states[i] = 0;
            }
        } else if (strcmp(input, "toggle") == 0) {
            // Toggle all lights
            for (int i = 0; i < NUM_LIGHTS; i++) {
                light_states[i] = !light_states[i];
            }
        } else if (strcmp(input, "exit") == 0) {
            // Exit program
            break;
        } else {
            // Invalid input
            printf("Invalid input: %s\n", input);
        }
    }

    return 0;
}