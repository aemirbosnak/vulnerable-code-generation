//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the light states
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Define the light commands
#define LIGHT_TOGGLE 0
#define LIGHT_TURN_ON 1
#define LIGHT_TURN_OFF 2

// Create a struct to represent a light
typedef struct light {
    int state;
} light;

// Create an array of lights
light lights[10];

// Initialize the lights
void init_lights() {
    for (int i = 0; i < 10; i++) {
        lights[i].state = LIGHT_OFF;
    }
}

// Toggle a light
void toggle_light(int light_number) {
    lights[light_number].state = !lights[light_number].state;
}

// Turn a light on
void turn_light_on(int light_number) {
    lights[light_number].state = LIGHT_ON;
}

// Turn a light off
void turn_light_off(int light_number) {
    lights[light_number].state = LIGHT_OFF;
}

// Print the state of the lights
void print_lights() {
    for (int i = 0; i < 10; i++) {
        printf("Light %d: %s\n", i, lights[i].state == LIGHT_ON ? "ON" : "OFF");
    }
}

// Main function
int main() {
    // Initialize the lights
    init_lights();

    // Get the user's input
    int light_number;
    int command;
    while (1) {
        printf("Enter the light number (0-9) and the command (0: toggle, 1: turn on, 2: turn off): ");
        scanf("%d %d", &light_number, &command);

        // Perform the command
        switch (command) {
            case LIGHT_TOGGLE:
                toggle_light(light_number);
                break;
            case LIGHT_TURN_ON:
                turn_light_on(light_number);
                break;
            case LIGHT_TURN_OFF:
                turn_light_off(light_number);
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        // Print the state of the lights
        print_lights();
    }

    return 0;
}