//FormAI DATASET v1.0 Category: Smart home light control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for the different light colors
#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

// Define constants for the different light states
#define LIGHT_ON 1
#define LIGHT_OFF 0

// Define a function to change the state of a light
void change_light_state(int* light, int new_state) {
    // Check if the light is already in the new state
    if (*light == new_state) {
        printf("Light is already in state %d\n", new_state);
        return;
    }
    
    // Change the light state
    *light = new_state;
    
    // Print a message indicating the new light state
    if (new_state == LIGHT_ON) {
        printf("Light turned ON\n");
    } else {
        printf("Light turned OFF\n");
    }
}

int main() {
    // Initialize the light states
    int red_light = LIGHT_OFF;
    int yellow_light = LIGHT_OFF;
    int green_light = LIGHT_OFF;
    
    // Print a welcome message
    printf("Welcome to the Smart Home Light Control System\n");
    
    // Loop to prompt the user for input
    while (true) {
        // Print the current light states
        printf("Current light state:\n");
        printf("Red Light: %s\n", red_light == LIGHT_ON ? "ON" : "OFF");
        printf("Yellow Light: %s\n", yellow_light == LIGHT_ON ? "ON" : "OFF");
        printf("Green Light: %s\n", green_light == LIGHT_ON ? "ON" : "OFF");
        
        // Prompt the user for input
        printf("Enter the light color you want to turn ON/OFF (R/Y/G) or 'exit' to quit: ");
        char input[10];
        scanf("%s", input);
        
        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the Smart Home Light Control System\n");
            break;
        }
        
        // Determine which light to change based on the user input
        int* light = NULL;
        if (strcmp(input, "R") == 0) {
            light = &red_light;
        } else if (strcmp(input, "Y") == 0) {
            light = &yellow_light;
        } else if (strcmp(input, "G") == 0) {
            light = &green_light;
        } else {
            printf("Invalid input, please enter R/Y/G or 'exit'\n");
            continue;
        }
        
        // Determine the new state of the light
        int new_state = *light == LIGHT_ON ? LIGHT_OFF : LIGHT_ON;
        
        // Change the state of the light
        change_light_state(light, new_state);
    }
    
    return 0;
}