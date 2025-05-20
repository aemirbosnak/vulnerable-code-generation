//FormAI DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for the different rooms in the house
#define KITCHEN 1
#define LIVING_ROOM 2
#define BEDROOM 3

// Define constants for the different states of the lights
#define OFF 0
#define ON 1

// Declare global variables for the light states in each room
int kitchenLightState = OFF;
int livingRoomLightState = OFF;
int bedroomLightState = OFF;

// Function to print the current state of all the lights
void printLightStates() {
    printf("Kitchen Light State: %s\n", kitchenLightState == OFF ? "OFF" : "ON");
    printf("Living Room Light State: %s\n", livingRoomLightState == OFF ? "OFF" : "ON");
    printf("Bedroom Light State: %s\n", bedroomLightState == OFF ? "OFF" : "ON");
    printf("\n");
}

int main() {
    int room, state;
    bool run = true;

    // Loop until the user decides to quit
    while (run) {
        // Print the current state of all the lights
        printLightStates();

        // Prompt the user to input a room number
        printf("Enter the room number (1-Kitchen, 2-Living Room, 3-Bedroom): ");
        scanf("%d", &room);

        // Prompt the user to input the state
        printf("\nEnter the light state (0-OFF, 1-ON): ");
        scanf("%d", &state);

        // Update the light state based on the user input
        switch(room) {
            case KITCHEN:
                kitchenLightState = state;
                break;

            case LIVING_ROOM:
                livingRoomLightState = state;
                break;

            case BEDROOM:
                bedroomLightState = state;
                break;

            default:
                printf("\nInvalid room number\n");
        }

        // Prompt the user to continue or quit
        printf("\nDo you want to continue? (0-No, 1-Yes): ");
        scanf("%d", &state);

        if (state == 0) {
            run = false;
        }

        printf("\n");
    }

    return 0;
}