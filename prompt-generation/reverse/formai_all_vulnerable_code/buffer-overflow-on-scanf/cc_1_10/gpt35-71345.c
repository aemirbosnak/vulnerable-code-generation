//FormAI DATASET v1.0 Category: Smart home light control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure to represent each light
typedef struct {
    int lightId;
    bool isOn;
} Light;

// Declare a function to change the state of a light
void toggleLight(Light *light) {
    if (light->isOn) {
        light->isOn = false;
    } else {
        light->isOn = true;
    }
}

int main() {
    // Initialize an array of lights with initial states
    Light lights[4] = {
        {1, false},
        {2, true},
        {3, false},
        {4, true}
    };
    
    // Display the initial states of the lights
    printf("Initial States:\n");
    for (int i = 0; i < 4; i++) {
        printf("Light %d: %s\n", lights[i].lightId, lights[i].isOn ? "ON" : "OFF");
    }
    
    // Allow the user to toggle the lights
    int selection = 0;
    while (selection != 5) {
        printf("\nLight Control Menu:\n");
        printf("1. Toggle Light 1\n");
        printf("2. Toggle Light 2\n");
        printf("3. Toggle Light 3\n");
        printf("4. Toggle Light 4\n");
        printf("5. Exit\n");
        printf("Enter a selection: ");
        
        scanf("%d", &selection);
        
        switch (selection) {
            case 1:
                toggleLight(&lights[0]);
                break;
            case 2:
                toggleLight(&lights[1]);
                break;
            case 3:
                toggleLight(&lights[2]);
                break;
            case 4:
                toggleLight(&lights[3]);
                break;
            case 5:
                break;
            default:
                printf("Invalid selection.\n");
                break;
        }
        
        if (selection != 5) {
            // Display the updated states of the lights
            printf("Updated States:\n");
            for (int i = 0; i < 4; i++) {
                printf("Light %d: %s\n", lights[i].lightId, lights[i].isOn ? "ON" : "OFF");
            }
        }
    }
    
    printf("Thanks for using our Smart Home Light Control system!\n");
    return 0;
}