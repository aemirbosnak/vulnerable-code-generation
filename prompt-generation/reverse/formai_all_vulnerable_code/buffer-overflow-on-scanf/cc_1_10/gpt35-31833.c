//FormAI DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
// This is a smart home light control program written in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define struct for light
typedef struct {
    char name[20];
    int brightness;
    bool is_on;
} Light;

// Define function to turn light on/off
void toggle_light(Light* light) {
    if (light->is_on) {
        light->is_on = false;
        light->brightness = 0;
        printf("%s turned off.\n", light->name);
    } else {
        light->is_on = true;
        light->brightness = 100;
        printf("%s turned on.\n", light->name);
    }
}

// Define function to adjust light brightness
void set_brightness(Light* light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Invalid brightness level.\n");
    } else {
        light->brightness = brightness;
        printf("Brightness level of %s set to %d.\n", light->name, brightness);
    }
}

int main() {
    // Set up two lights
    Light living_room_light = {"Living Room", 0, false};
    Light bedroom_light = {"Bedroom", 0, false};
    
    // Welcome message
    printf("Welcome to Smart Home Light Control!\n");
    
    // Main menu loop
    while (true) {
        printf("\nChoose an option:\n");
        printf("1. Turn Living Room light on/off\n");
        printf("2. Turn Bedroom light on/off\n");
        printf("3. Adjust Living Room light brightness\n");
        printf("4. Adjust Bedroom light brightness\n");
        printf("5. Quit\n");
        
        // Get user input
        int choice;
        printf("Enter choice (1-5): ");
        scanf("%d", &choice);
        
        // Handle user input
        switch (choice) {
            case 1:
                toggle_light(&living_room_light);
                break;
            case 2:
                toggle_light(&bedroom_light);
                break;
            case 3:
                printf("Enter brightness level (0-100): ");
                int living_room_brightness;
                scanf("%d", &living_room_brightness);
                set_brightness(&living_room_light, living_room_brightness);
                break;
            case 4:
                printf("Enter brightness level (0-100): ");
                int bedroom_brightness;
                scanf("%d", &bedroom_brightness);
                set_brightness(&bedroom_light, bedroom_brightness);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}