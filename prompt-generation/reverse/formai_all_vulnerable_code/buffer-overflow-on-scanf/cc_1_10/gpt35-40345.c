//FormAI DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants to represent rooms
#define KITCHEN 1
#define LIVING_ROOM 2
#define BEDROOM 3

// Define constants to represent light states
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Define a global variable to keep track of the overall light state
bool lightState = false;

// Define a function to turn on the light
void turnOnLight(int room) {
    printf("Turning on light in room %d\n", room);
    lightState = true;
}

// Define a function to turn off the light
void turnOffLight(int room) {
    printf("Turning off light in room %d\n", room);
    lightState = false;
}

// Define a function to toggle the light
void toggleLight(int room) {
    if (lightState) {
        turnOffLight(room);
    } else {
        turnOnLight(room);
    }
}

int main() {
    // Initialize all lights in each room to off
    int kitchenLightState = LIGHT_OFF;
    int livingRoomLightState = LIGHT_OFF;
    int bedroomLightState = LIGHT_OFF;
    
    // Loop until the user decides to quit
    while(true) {
        // Print out the current light state in each room
        printf("Current Light State:\n");
        printf("Kitchen: %d\n", kitchenLightState);
        printf("Living Room: %d\n", livingRoomLightState);
        printf("Bedroom: %d\n", bedroomLightState);
        
        // Print out the available commands
        printf("Available Commands:\n");
        printf("1. Toggle Light\n");
        printf("2. Quit\n");
        
        // Get the user's command choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Handle the user's command choice
        switch(choice) {
            case 1: {
                // Get the user's desired room to change the light state for
                int roomChoice;
                printf("Which room would you like to toggle the light for? (Enter 1 for Kitchen, 2 for Living Room, 3 for Bedroom): ");
                scanf("%d", &roomChoice);
                
                // Determine which room was chosen and toggle the light state for that room
                switch(roomChoice) {
                    case KITCHEN: {
                        toggleLight(KITCHEN);
                        kitchenLightState = lightState;
                        break;
                    }
                    case LIVING_ROOM: {
                        toggleLight(LIVING_ROOM);
                        livingRoomLightState = lightState;
                        break;
                    }
                    case BEDROOM: {
                        toggleLight(BEDROOM);
                        bedroomLightState = lightState;
                        break;
                    }
                    default: {
                        printf("Invalid room choice.\n");
                        break;
                    }
                }
                break;
            }
            case 2: {
                // Quit the program
                printf("Goodbye!\n");
                return 0;
            }
            default: {
                // Display an error message for an invalid command choice
                printf("Invalid command choice.\n");
                break;
            }
        }
    }
}