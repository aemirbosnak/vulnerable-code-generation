//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the light states
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Define the light commands
#define LIGHT_TOGGLE 0
#define LIGHT_ON 1
#define LIGHT_OFF 2

// Define the light status
typedef struct {
    int state;
    char *name;
} light_status;

// Create an array of light statuses
light_status lights[] = {
    {LIGHT_OFF, "Living Room"},
    {LIGHT_OFF, "Kitchen"},
    {LIGHT_OFF, "Bedroom"},
    {LIGHT_OFF, "Bathroom"}
};

// Get the number of lights
int num_lights = sizeof(lights) / sizeof(lights[0]);

// Get the index of a light by name
int get_light_index(char *name) {
    for (int i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Toggle the state of a light
void toggle_light(char *name) {
    int index = get_light_index(name);
    if (index == -1) {
        printf("Error: Light %s not found\n", name);
        return;
    }
    lights[index].state = !lights[index].state;
    printf("Light %s is now %s\n", name, lights[index].state ? "ON" : "OFF");
}

// Turn a light on
void turn_light_on(char *name) {
    int index = get_light_index(name);
    if (index == -1) {
        printf("Error: Light %s not found\n", name);
        return;
    }
    lights[index].state = LIGHT_ON;
    printf("Light %s is now ON\n", name);
}

// Turn a light off
void turn_light_off(char *name) {
    int index = get_light_index(name);
    if (index == -1) {
        printf("Error: Light %s not found\n", name);
        return;
    }
    lights[index].state = LIGHT_OFF;
    printf("Light %s is now OFF\n", name);
}

// Print the status of all lights
void print_light_status() {
    for (int i = 0; i < num_lights; i++) {
        printf("Light %s is %s\n", lights[i].name, lights[i].state ? "ON" : "OFF");
    }
}

// Main function
int main() {
    // Get the command
    char command[10];
    printf("Enter a command (toggle, on, off): ");
    scanf("%s", command);

    // Get the light name
    char name[20];
    printf("Enter the light name: ");
    scanf("%s", name);

    // Execute the command
    if (strcmp(command, "toggle") == 0) {
        toggle_light(name);
    } else if (strcmp(command, "on") == 0) {
        turn_light_on(name);
    } else if (strcmp(command, "off") == 0) {
        turn_light_off(name);
    } else {
        printf("Error: Unknown command %s\n", command);
    }

    // Print the status of all lights
    print_light_status();

    return 0;
}