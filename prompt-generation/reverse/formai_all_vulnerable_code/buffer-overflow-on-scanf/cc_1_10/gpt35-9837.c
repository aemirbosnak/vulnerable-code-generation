//FormAI DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

// Function to turn on the lights
void turnOnLights(bool lights[]) {
    for (int i = 0; i < 4; i++) {
        lights[i] = true;
    }
}

// Function to turn off the lights
void turnOffLights(bool lights[]) {
    for (int i = 0; i < 4; i++) {
        lights[i] = false;
    }
}

int main() {
    bool lights[] = {false, false, false, false}; // state of the lights
    int choice; // variable for storing user input
    
    printf("Welcome to the Smart Home Light Control Program!\n\n");
    
    while (true) {
        printf("Please select an option:\n");
        printf("1. View current state of lights\n");
        printf("2. Turn on lights\n");
        printf("3. Turn off lights\n");
        printf("4. Exit program\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Current state of lights:\n");
                for (int i = 0; i < 4; i++) {
                    printf("Light %d: %s\n", i+1, lights[i] ? "on" : "off");
                }
                break;
            
            case 2:
                turnOnLights(lights);
                printf("Lights turned on!\n");
                break;
            
            case 3:
                turnOffLights(lights);
                printf("Lights turned off!\n");
                break;
            
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}