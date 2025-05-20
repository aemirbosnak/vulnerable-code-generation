//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

// Define a struct for each light in the smart home system
typedef struct {
    int light_id;
    bool is_on;
    int brightness; // brightness range 0-100
} Light;

// Define a function to turn on/off a specific light
void toggle_light(Light* light) {
    light->is_on = !light->is_on;
}

// Define a function to set brightness of a specific light
void set_brightness(Light* light, int brightness) {
    light->brightness = brightness;
}

// Main function
int main() {
    Light lights[MAX_LIGHTS];

    // Initialize all lights to off and brightness 0
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].light_id = i;
        lights[i].is_on = false;
        lights[i].brightness = 0;
    }

    // User interface loop
    while (true) {
        int menu_choice;
        printf("\n\nSMART HOME LIGHT CONTROL\n");
        printf("1. Toggle light on/off\n");
        printf("2. Set light brightness\n");
        printf("3. Print current light status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        // Handle user choice
        switch (menu_choice) {
            case 1: { // Toggle light
                int light_id;
                printf("Enter light id (0-%d): ", MAX_LIGHTS - 1);
                scanf("%d", &light_id);
                if (light_id < 0 || light_id >= MAX_LIGHTS) {
                    printf("Invalid light id!\n");
                    break;
                }
                toggle_light(&lights[light_id]);
                printf("Light %d is now %s.\n", light_id, lights[light_id].is_on ? "on" : "off");
                break;
            }
            case 2: { // Set brightness
                int light_id, brightness;
                printf("Enter light id (0-%d): ", MAX_LIGHTS - 1);
                scanf("%d", &light_id);
                if (light_id < 0 || light_id >= MAX_LIGHTS) {
                    printf("Invalid light id!\n");
                    break;
                }
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                if (brightness < 0 || brightness > 100) {
                    printf("Invalid brightness value!\n");
                    break;
                }
                set_brightness(&lights[light_id], brightness);
                printf("Brightness of light %d set to %d.\n", light_id, brightness);
                break;
            }
            case 3: { // Print current light status
                printf("Current light status:\n");
                for (int i = 0; i < MAX_LIGHTS; i++) {
                    printf("Light %d is %s and has brightness %d.\n", 
                        lights[i].light_id, lights[i].is_on ? "on" : "off", lights[i].brightness);
                }
                break;
            }
            case 4: // Exit program
                printf("Exiting program...\n");
                exit(0);
            default: // Invalid menu choice
                printf("Invalid menu choice, please try again.\n");
        }
    }
    return 0;
}