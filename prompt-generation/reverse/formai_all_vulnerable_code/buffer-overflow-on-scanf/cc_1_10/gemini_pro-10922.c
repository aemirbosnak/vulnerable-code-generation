//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Enumerated type to represent the state of the light
typedef enum {
    OFF,
    ON
} light_state;

// Function to toggle the state of the light
void toggle_light(light_state* state) {
    *state = *state == OFF ? ON : OFF;
}

// Function to print the state of the light
void print_light_state(light_state state) {
    const char* state_string = state == OFF ? "OFF" : "ON";
    printf("Light is currently %s\n", state_string);
}

int main() {
    // Create a variable to store the state of the light
    light_state state = OFF;

    // Get the initial state of the light from the user
    printf("Enter the initial state of the light (0 for OFF, 1 for ON): ");
    int initial_state;
    scanf("%d", &initial_state);
    state = initial_state ? ON : OFF;

    // Print the initial state of the light
    print_light_state(state);

    // Get the number of commands to execute from the user
    printf("Enter the number of commands to execute: ");
    int num_commands;
    scanf("%d", &num_commands);

    // Execute the commands
    for (int i = 0; i < num_commands; i++) {
        // Get the command from the user
        printf("Enter command %d (0 to toggle, 1 to quit): ", i + 1);
        int command;
        scanf("%d", &command);

        // Execute the command
        switch (command) {
            case 0:
                toggle_light(&state);
                print_light_state(state);
                break;
            case 1:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid command. Please enter 0 to toggle or 1 to quit.\n");
                break;
        }
    }

    return 0;
}