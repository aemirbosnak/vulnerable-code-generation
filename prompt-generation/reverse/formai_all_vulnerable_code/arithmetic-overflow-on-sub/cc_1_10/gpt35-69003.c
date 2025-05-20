//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the number of floors and elevators
#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// Function to print the current state of the elevator system
void printElevatorState(int elevatorLocations[], bool elevatorDirection[]) {
    printf("Elevator state:\n");
    for (int i = NUM_FLOORS - 1; i >= 0; i--) {
        printf("%2d|", i+1);
        for (int j = 0; j < NUM_ELEVATORS; j++) {
            if (elevatorLocations[j] == i && elevatorDirection[j] == true) {
                printf(" V |");
            } else if (elevatorLocations[j] == i && elevatorDirection[j] == false) {
                printf(" ^ |");
            } else {
                printf("   |");
            }
        }
        printf("\n");
    }
}

int main(void) {
    
    // Initialize the elevator locations and directions
    int elevatorLocations[NUM_ELEVATORS] = {0};
    bool elevatorDirection[NUM_ELEVATORS] = {true};
    
    // Prompt the user for the initial elevator positions
    printf("Please enter the initial position of each elevator (elevator 1-3): \n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d: ", i+1);
        scanf("%d", &elevatorLocations[i]);
        elevatorLocations[i] = NUM_FLOORS - elevatorLocations[i] - 1;
    }
    
    // Loop through each tick
    for (int tick = 0; tick < 100; tick++) {
        
        // Print the current state of the elevator system
        printElevatorState(elevatorLocations, elevatorDirection);
        
        // Prompt the user for elevator requests
        printf("Enter an elevator request (floor elevator): ");
        int requestedFloor, requestedElevator;
        scanf("%d %d", &requestedFloor, &requestedElevator);
        requestedFloor = NUM_FLOORS - requestedFloor - 1;
        requestedElevator -= 1;
        
        // Move the requested elevator towards the requested floor
        int distance = requestedFloor - elevatorLocations[requestedElevator];
        if (distance > 0) {
            elevatorDirection[requestedElevator] = true;
        } else if (distance < 0) {
            elevatorDirection[requestedElevator] = false;
        }
        for (int i = 0; i < abs(distance); i++) {
            elevatorLocations[requestedElevator] += (elevatorDirection[requestedElevator] ? 1 : -1);
            printElevatorState(elevatorLocations, elevatorDirection);
        }
    }
    
    return 0;
}