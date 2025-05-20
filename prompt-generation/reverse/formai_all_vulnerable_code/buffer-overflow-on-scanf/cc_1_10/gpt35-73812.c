//FormAI DATASET v1.0 Category: Smart home light control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// defining macros for light status
#define LIGHT_ON true
#define LIGHT_OFF false

// function to switch on the light
void turnOnLight() {
    printf("Turning on the light...\n");
    // logic to switch on the light
}

// function to switch off the light
void turnOffLight() {
    printf("Turning off the light...\n");
    // logic to switch off the light
}

int main() {
    bool lightStatus = LIGHT_OFF; // initially light is off
    
    printf("Welcome to Smart Home: Light Control\n");
    
    // main loop
    while (true) {
        printf("Current light status: %s\n", lightStatus ? "ON" : "OFF");
        printf("Enter 1 to turn on the light, 2 to turn off the light, or 0 to quit: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Goodbye!");
                return 0;
            case 1:
                if (lightStatus == LIGHT_OFF) {
                    turnOnLight();
                    lightStatus = LIGHT_ON;
                } else {
                    printf("Light is already on!\n");
                }
                break;
            case 2:
                if (lightStatus == LIGHT_ON) {
                    turnOffLight();
                    lightStatus = LIGHT_OFF;
                } else {
                    printf("Light is already off!\n");
                }
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        
        printf("\n");
    }
}