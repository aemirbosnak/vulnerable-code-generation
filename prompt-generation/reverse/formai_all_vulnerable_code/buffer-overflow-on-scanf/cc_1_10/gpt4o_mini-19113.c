//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define ELEVATOR_IDLE 0
#define ELEVATOR_UP 1
#define ELEVATOR_DOWN 2

typedef struct {
    int currentFloor;
    int targetFloor;
    int direction;
} Elevator;

// Function to initialize the elevator
void initElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Start on ground floor
    elevator->targetFloor = -1; // No target initially
    elevator->direction = ELEVATOR_IDLE;
}

// Function to display the elevator's current status
void displayStatus(Elevator *elevator) {
    printf("Elevator is currently on floor %d.\n", elevator->currentFloor);
    if (elevator->targetFloor != -1) {
        printf("Target floor: %d\n", elevator->targetFloor);
        printf("Direction: %s\n", (elevator->direction == ELEVATOR_UP) ? "UP" : "DOWN");
    } else {
        printf("Elevator is idle.\n");
    }
}

// Function to move the elevator
void moveElevator(Elevator *elevator) {
    if (elevator->targetFloor == -1) {
        return; // No target floor to move to
    }

    while (elevator->currentFloor != elevator->targetFloor) {
        // Move elevator up or down
        if (elevator->currentFloor < elevator->targetFloor) {
            elevator->direction = ELEVATOR_UP;
            elevator->currentFloor++;
            printf("Elevator moving up to floor %d...\n", elevator->currentFloor);
        } else {
            elevator->direction = ELEVATOR_DOWN;
            elevator->currentFloor--;
            printf("Elevator moving down to floor %d...\n", elevator->currentFloor);
        }
        sleep(1); // Delay to simulate time taken to move
    }
    
    // Reached the target floor
    printf("Elevator reached floor %d.\n", elevator->currentFloor);
    elevator->targetFloor = -1; // Reset target
    elevator->direction = ELEVATOR_IDLE; // Reset direction
}

// Function to request the elevator to a specific floor
void requestElevator(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request! Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    
    elevator->targetFloor = floor;
    printf("Elevator requested to floor %d.\n", floor);
    displayStatus(elevator);
    moveElevator(elevator);
}

int main() {
    Elevator myElevator;
    initElevator(&myElevator);
    int floorChoice;

    while (1) {
        printf("\n=== Elevator Simulation ===\n");
        displayStatus(&myElevator);
        printf("Enter the floor you want to go to (0 to %d) or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &floorChoice);

        if (floorChoice == -1) {
            printf("Exiting elevator simulation. Goodbye!\n");
            break;
        }

        requestElevator(&myElevator, floorChoice);
    }

    return 0;
}