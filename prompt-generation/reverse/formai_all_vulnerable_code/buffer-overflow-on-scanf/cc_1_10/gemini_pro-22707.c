//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: satisfied
// Smart Home Light Control in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For boolean data types

// Define light statuses
enum light_status { OFF, ON };

// Define light structure
struct light {
    int id;
    char *name;
    enum light_status status;
};

// Initialize lights
struct light lights[] = {
    {1, "Kitchen", OFF},
    {2, "Living Room", OFF},
    {3, "Bedroom", OFF}
};

// Get the number of lights
int num_lights = sizeof(lights) / sizeof(lights[0]);

// Function to toggle light status
void toggle_light(struct light *light) {
    light->status = (light->status == OFF) ? ON : OFF;
}

// Function to print light status
void print_light_status(struct light light) {
    printf("Light %s is %s\n", light.name, (light.status == ON) ? "ON" : "OFF");
}

// Main function
int main() {
    // Display initial light statuses
    printf("Initial Light Statuses:\n");
    for (int i = 0; i < num_lights; i++) {
        print_light_status(lights[i]);
    }

    // Get light ID to toggle
    int light_id;
    printf("\nEnter the Light ID to toggle: ");
    scanf("%d", &light_id);

    // Find light with given ID
    struct light *light_to_toggle = NULL;
    for (int i = 0; i < num_lights; i++) {
        if (lights[i].id == light_id) {
            light_to_toggle = &lights[i];
            break;
        }
    }

    // Check if light was found
    if (light_to_toggle == NULL) {
        printf("Invalid Light ID!\n");
        return EXIT_FAILURE;
    }

    // Toggle light status
    toggle_light(light_to_toggle);

    // Display updated light status
    printf("\nUpdated Light Status:\n");
    print_light_status(*light_to_toggle);

    return EXIT_SUCCESS;
}