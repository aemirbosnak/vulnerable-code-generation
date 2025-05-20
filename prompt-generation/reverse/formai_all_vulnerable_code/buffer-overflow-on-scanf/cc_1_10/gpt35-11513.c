//FormAI DATASET v1.0 Category: Smart home automation ; Style: scalable
#include <stdio.h>

// Define macros for pin numbers
#define LIGHT_PIN 1
#define FAN_PIN 2

// Define function to control lights
void controlLights(int value) {
    if(value == 1) {
        printf("Turning lights on\n");
        // code to turn lights on
    }
    else {
        printf("Turning lights off\n");
        // code to turn lights off
    }
}

// Define function to control fans
void controlFans(int value) {
    if(value == 1) {
        printf("Turning fans on\n");
        // code to turn fans on
    }
    else {
        printf("Turning fans off\n");
        // code to turn fans off
    }
}

int main() {
    int lightValue = 0; // 0: Lights off, 1: Lights on
    int fanValue = 0; // 0: Fans off, 1: Fans on
    
    // Continuously read input from user
    while(1) {
        printf("Enter command: ");
        char command;
        scanf(" %c", &command);
        
        switch(command) {
            case 'l':
                lightValue = !lightValue; // Toggle light value
                controlLights(lightValue);
                break;
            case 'f':
                fanValue = !fanValue; // Toggle fan value
                controlFans(fanValue);
                break;
            default:
                printf("Invalid command\n");
        }
    }

    return 0;
}