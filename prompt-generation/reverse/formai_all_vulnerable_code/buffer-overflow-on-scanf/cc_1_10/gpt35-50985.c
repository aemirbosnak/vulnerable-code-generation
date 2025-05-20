//FormAI DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for the light and switch
#define LIGHT_OFF 0
#define LIGHT_ON 1
#define SWITCH_OFF 0
#define SWITCH_ON 1

int main()
{
    // Initialize the light and switch state
    int light_state = LIGHT_OFF;
    int switch_state = SWITCH_OFF;
    
    // Print initial status message
    printf("Smart Home Light Control\n");
    printf("-------------------------\n");
    printf("Light is currently %s\n", (light_state == LIGHT_ON) ? "On" : "Off");
    printf("Switch is currently %s\n", (switch_state == SWITCH_ON) ? "On" : "Off");
    printf("\n");
    
    // Loop continuously to simulate real-time light control
    while (true)
    {
        // Prompt user to toggle the switch state
        printf("Type 'on' to turn the switch on, or 'off' to turn it off: ");
        char input[10];
        scanf("%s", input);
        
        if (strcmp(input, "on") == 0)
        {
            switch_state = SWITCH_ON;
        }
        else if (strcmp(input, "off") == 0)
        {
            switch_state = SWITCH_OFF;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        
        // Update the light state based on the switch state
        if (switch_state == SWITCH_ON)
        {
            light_state = LIGHT_ON;
        }
        else
        {
            light_state = LIGHT_OFF;
        }
        
        // Print the updated status message
        printf("\n");
        printf("Light is now %s\n", (light_state == LIGHT_ON) ? "On" : "Off");
        printf("Switch is now %s\n", (switch_state == SWITCH_ON) ? "On" : "Off");
        printf("\n");
    }
    
    return 0;
}