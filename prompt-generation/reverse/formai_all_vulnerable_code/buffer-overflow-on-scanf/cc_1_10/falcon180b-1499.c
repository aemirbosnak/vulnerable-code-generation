//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the structure for a light
typedef struct {
    int id;
    char name[20];
    bool on;
} Light;

// Initialize an array of lights
Light lights[MAX_LIGHTS];

// Initialize the number of lights
int num_lights = 0;

// Function to add a new light
void add_light() {
    if (num_lights == MAX_LIGHTS) {
        printf("Maximum number of lights reached.\n");
        return;
    }

    printf("Enter the ID of the light (1-9): ");
    scanf("%d", &lights[num_lights].id);

    printf("Enter the name of the light (up to 20 characters): ");
    scanf("%s", lights[num_lights].name);

    lights[num_lights].on = false;
    num_lights++;
}

// Function to turn a light on or off
void toggle_light(int id) {
    for (int i = 0; i < num_lights; i++) {
        if (lights[i].id == id) {
            lights[i].on =!lights[i].on;
            printf("Light %d (%s) is now %s.\n", id, lights[i].name, lights[i].on? "on" : "off");
            return;
        }
    }

    printf("Light with ID %d not found.\n", id);
}

// Function to turn all lights on or off
void toggle_all_lights(bool on) {
    for (int i = 0; i < num_lights; i++) {
        lights[i].on = on;
    }

    printf("All lights are now %s.\n", on? "on" : "off");
}

// Function to print the status of all lights
void print_light_status() {
    printf("Light Status:\n");
    for (int i = 0; i < num_lights; i++) {
        printf("%d. %s - %s\n", lights[i].id, lights[i].name, lights[i].on? "on" : "off");
    }
}

int main() {
    printf("Smart Home Light Control System\n");

    // Add some lights
    add_light();
    add_light();

    // Turn on/off some lights
    toggle_light(1);
    toggle_light(2);

    // Print the status of all lights
    print_light_status();

    // Turn all lights on/off
    toggle_all_lights(true);
    toggle_all_lights(false);

    return 0;
}