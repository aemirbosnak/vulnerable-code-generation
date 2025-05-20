//FormAI DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include <stdio.h>

// Define macros for different rooms in the house
#define LIVING_ROOM 0
#define BEDROOM 1
#define KITCHEN 2
#define BATHROOM 3

// Define macros for different appliances in the house
#define LIGHTS 0
#define TV 1
#define OVEN 2
#define FRIDGE 3

// Define macros for the states of the appliances
#define ON 1
#define OFF 0

// Function to turn on an appliance
void turnOn(int room, int appliance) {
    printf(" Turning on appliance %d in room %d\n", appliance, room);
    // TODO: write code to turn on the appliance
}

// Function to turn off an appliance
void turnOff(int room, int appliance) {
    printf(" Turning off appliance %d in room %d\n", appliance, room);
    // TODO: write code to turn off the appliance
}

int main() {
    // Declare a 2D array for the state of all appliances in the house
    int state[4][4] = {
        {OFF, OFF, ON, OFF},
        {ON, OFF, OFF, OFF},
        {OFF, ON, OFF, OFF},
        {OFF, OFF, OFF, ON}
    };
    
    // Prompt the user for the desired action
    int room, appliance, action;
    printf("Enter the room (0 for living room, 1 for bedroom, 2 for kitchen, 3 for bathroom): ");
    scanf("%d", &room);
    printf("Enter the appliance (0 for lights, 1 for TV, 2 for oven, 3 for fridge): ");
    scanf("%d", &appliance);
    printf("Enter the action (0 for off, 1 for on): ");
    scanf("%d", &action);
    
    // Check if the desired action is already the current state of the appliance
    if (action == state[room][appliance]) {
        printf("The appliance is already in the desired state.\n");
    } else {
        // Perform the desired action
        if (action == ON) {
            turnOn(room, appliance);
        } else {
            turnOff(room, appliance);
        }
        // Update the state of the appliance
        state[room][appliance] = action;
    }
    
    return 0;
}