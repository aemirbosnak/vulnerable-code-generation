//FormAI DATASET v1.0 Category: Smart home light control ; Style: Claude Shannon
#include <stdio.h>

// Define constants for the light bulbs
#define LIGHT_BULB_1 1
#define LIGHT_BULB_2 2
#define LIGHT_BULB_3 3

// Define constants for the light states
#define LIGHT_OFF 0
#define LIGHT_ON 1
#define LIGHT_DIM 2

int main() {
    int lightBulb1State = LIGHT_OFF;
    int lightBulb2State = LIGHT_OFF;
    int lightBulb3State = LIGHT_OFF;
    
    printf("Welcome to the Smart Home Light Control Program!\n");
    printf("Please select a light bulb to control:\n");
    printf("1. Light Bulb 1\n");
    printf("2. Light Bulb 2\n");
    printf("3. Light Bulb 3\n");
    
    int selectedLightBulb;
    scanf("%d", &selectedLightBulb);
    
    printf("Please select a state for the light bulb:\n");
    printf("0. Off\n");
    printf("1. On\n");
    printf("2. Dim\n");
    
    int selectedState;
    scanf("%d", &selectedState);
    
    // Update the selected light bulb's state based on the user's input
    switch(selectedLightBulb) {
        case LIGHT_BULB_1:
            lightBulb1State = selectedState;
            break;
        case LIGHT_BULB_2:
            lightBulb2State = selectedState;
            break;
        case LIGHT_BULB_3:
            lightBulb3State = selectedState;
            break;
        default:
            printf("Invalid light bulb selected. Please try again.\n");
            return 0;
    }
    
    // Print out the current state of all the light bulbs
    printf("Current Light State:\n");
    printf("Light Bulb 1: %d\n", lightBulb1State);
    printf("Light Bulb 2: %d\n", lightBulb2State);
    printf("Light Bulb 3: %d\n", lightBulb3State);
    
    return 0;
}