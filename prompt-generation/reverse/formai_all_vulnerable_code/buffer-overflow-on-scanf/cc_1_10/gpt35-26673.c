//FormAI DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Function to turn lights on
void turnLightsOn() {
    printf("Turning lights on...\n");
}

// Function to turn lights off
void turnLightsOff() {
    printf("Turning lights off...\n");
}

int main() {
    // Declare smart home variables
    bool motionDetected = false;
    bool lightsOn = false;

    printf("Welcome to your smart home!\n");
    
    // Loop forever (or until user exit)
    while (true) {
        
        printf("Do you want to turn the lights on or off? (1 for on, 0 for off): ");
        scanf("%d", &lightsOn);

        // Check if lights are already on
        if (lightsOn && !motionDetected) {
            printf("Lights are already on!\n");
        }

        // Check if lights are already off
        if (!lightsOn) {
            printf("Lights are already off!\n");
        }

        // Turn lights on 
        if (lightsOn && motionDetected) {
            turnLightsOn();
            // Update motion detected variable
            motionDetected = false;
            // Wait for 10 seconds
            usleep(10000000);
        }

        // Turn lights off 
        if (!lightsOn && !motionDetected) {
            turnLightsOff();
            // Update motion detected variable
            motionDetected = true;
        }
    }

    return 0;
}