//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10  // Define the maximum number of floors
#define MAX_CAPACITY 5  // Define the maximum capacity of the elevator

typedef struct {
    int currentFloor;
    int targetFloor;
    int occupancy;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0;  // Start on ground floor
    elevator->targetFloor = 0;    // No target floor initially
    elevator->occupancy = 0;      // Elevator is empty
}

void displayStatus(const Elevator *elevator) {
    printf("Elevator Status:\n");
    printf("Current Floor: %d\n", elevator->currentFloor);
    printf("Target Floor: %d\n", elevator->targetFloor);
    printf("Occupancy: %d\n", elevator->occupancy);
}

void moveElevator(Elevator *elevator) {
    while (elevator->currentFloor != elevator->targetFloor) {
        printf("Moving from floor %d...\n", elevator->currentFloor);
        if (elevator->currentFloor < elevator->targetFloor) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }
        sleep(1);  // Simulate time taken to move between floors
    }
    printf("Elevator has arrived at floor %d.\n", elevator->currentFloor);
}

bool requestElevator(Elevator *elevator, int desiredFloor, int requestedOccupancy) {
    if (desiredFloor < 0 || desiredFloor >= MAX_FLOORS) {
        printf("Invalid floor selection. Please select between 0 and %d.\n", MAX_FLOORS - 1);
        return false;
    }

    if (requestedOccupancy > MAX_CAPACITY) {
        printf("Exceeded maximum capacity of %d. Please wait for next lift.\n", MAX_CAPACITY);
        return false;
    }

    elevator->occupancy = requestedOccupancy;
    elevator->targetFloor = desiredFloor;
    return true;
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    
    int desiredFloor, requestedOccupancy;
    char continueSimulation = 'y';

    while (continueSimulation == 'y') {
        displayStatus(&elevator);
        
        printf("Enter desired floor (0-%d): ", MAX_FLOORS - 1);
        scanf("%d", &desiredFloor);
        
        printf("Enter number of people requesting the lift: ");
        scanf("%d", &requestedOccupancy);
        
        if (requestElevator(&elevator, desiredFloor, requestedOccupancy)) {
            moveElevator(&elevator);
        }

        printf("Would you like to continue? (y/n): ");
        scanf(" %c", &continueSimulation);
    }
    
    printf("Elevator simulation ended.\n");
    return 0;
}