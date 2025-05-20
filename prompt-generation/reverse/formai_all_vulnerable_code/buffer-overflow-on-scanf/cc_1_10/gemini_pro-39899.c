//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the states of a light
typedef enum {
    OFF,
    ON
} light_state;

// Define a light structure
typedef struct {
    char name[20];
    light_state state;
} light;

// Create an array of lights
light lights[MAX_LIGHTS];

// Get the number of lights from the user
int get_num_lights() {
    int num_lights;
    printf("How many lights do you want to control? ");
    scanf("%d", &num_lights);
    return num_lights;
}

// Get the name of a light from the user
void get_light_name(char *name) {
    printf("Enter the name of the light: ");
    scanf("%s", name);
}

// Turn a light on
void turn_on_light(light *light) {
    light->state = ON;
}

// Turn a light off
void turn_off_light(light *light) {
    light->state = OFF;
}

// Toggle the state of a light
void toggle_light(light *light) {
    light->state = (light->state == ON) ? OFF : ON;
}

// Get the state of a light
light_state get_light_state(light *light) {
    return light->state;
}

// Print the state of a light
void print_light_state(light *light) {
    printf("%s is %s\n", light->name, (light->state == ON) ? "on" : "off");
}

// Main function
int main() {
    // Get the number of lights
    int num_lights = get_num_lights();

    // Initialize the lights
    for (int i = 0; i < num_lights; i++) {
        get_light_name(lights[i].name);
        lights[i].state = OFF;
    }

    // Main loop
    while (true) {
        // Get the user's input
        char command[20];
        printf("Enter a command (on, off, toggle, or quit): ");
        scanf("%s", command);

        // Process the user's input
        if (strcmp(command, "on") == 0) {
            // Get the name of the light to turn on
            char name[20];
            get_light_name(name);

            // Find the light
            light *light = NULL;
            for (int i = 0; i < num_lights; i++) {
                if (strcmp(lights[i].name, name) == 0) {
                    light = &lights[i];
                    break;
                }
            }

            // Turn on the light
            if (light != NULL) {
                turn_on_light(light);
            } else {
                printf("Light not found\n");
            }
        } else if (strcmp(command, "off") == 0) {
            // Get the name of the light to turn off
            char name[20];
            get_light_name(name);

            // Find the light
            light *light = NULL;
            for (int i = 0; i < num_lights; i++) {
                if (strcmp(lights[i].name, name) == 0) {
                    light = &lights[i];
                    break;
                }
            }

            // Turn off the light
            if (light != NULL) {
                turn_off_light(light);
            } else {
                printf("Light not found\n");
            }
        } else if (strcmp(command, "toggle") == 0) {
            // Get the name of the light to toggle
            char name[20];
            get_light_name(name);

            // Find the light
            light *light = NULL;
            for (int i = 0; i < num_lights; i++) {
                if (strcmp(lights[i].name, name) == 0) {
                    light = &lights[i];
                    break;
                }
            }

            // Toggle the light
            if (light != NULL) {
                toggle_light(light);
            } else {
                printf("Light not found\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            // Exit the program
            break;
        } else {
            // Invalid command
            printf("Invalid command\n");
        }

        // Print the state of all lights
        for (int i = 0; i < num_lights; i++) {
            print_light_state(&lights[i]);
        }
    }

    return 0;
}