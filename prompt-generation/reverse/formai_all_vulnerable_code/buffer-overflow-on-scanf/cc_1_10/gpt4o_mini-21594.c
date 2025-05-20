//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 5
#define ELEVATOR_SERVICE_TIME 2  // Seconds to serve a request

typedef struct {
    int currentFloor;
    int targetFloor;
    bool isMovingUp;
    bool isIdle;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 1; // Elevators start at the ground floor (1)
    elevator->targetFloor = 1;
    elevator->isMovingUp = false;
    elevator->isIdle = true;
}

void moveElevator(Elevator *elevator) {
    if (elevator->currentFloor < elevator->targetFloor) {
        elevator->isMovingUp = true;
        while (elevator->currentFloor < elevator->targetFloor) {
            elevator->currentFloor++;
            printf("Elevator is moving up to floor %d\n", elevator->currentFloor);
            sleep(ELEVATOR_SERVICE_TIME);
        }
    } else if (elevator->currentFloor > elevator->targetFloor) {
        elevator->isMovingUp = false;
        while (elevator->currentFloor > elevator->targetFloor) {
            elevator->currentFloor--;
            printf("Elevator is moving down to floor %d\n", elevator->currentFloor);
            sleep(ELEVATOR_SERVICE_TIME);
        }
    }
    elevator->isIdle = true;
    printf("Elevator has arrived at floor %d\n", elevator->currentFloor);
}

void requestElevator(Elevator *elevator, int floor) {
    if (floor < 1 || floor > MAX_FLOORS) {
        printf("Invalid floor requested. Please select a floor between 1 and %d.\n", MAX_FLOORS);
        return;
    }
    elevator->targetFloor = floor;
    elevator->isIdle = false;
    printf("Elevator called to floor %d.\n", floor);
    moveElevator(elevator);
}

void displayElevatorStatus(Elevator *elevator) {
    printf("Elevator current status:\n");
    printf("Current Floor: %d\n", elevator->currentFloor);
    printf("Target Floor: %d\n", elevator->targetFloor);
    printf("Is Moving Up: %s\n", elevator->isMovingUp ? "Yes" : "No");
    printf("Is Idle: %s\n", elevator->isIdle ? "Yes" : "No");
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    int userFloor;

    while (true) {
        displayElevatorStatus(&elevator);
        printf("Select a floor to go to (1 - %d) or 0 to exit: ", MAX_FLOORS);
        scanf("%d", &userFloor);

        if (userFloor == 0) {
            printf("Exiting elevator simulation. Goodbye!\n");
            break;
        }

        requestElevator(&elevator, userFloor);
        printf("\n");
    }
    
    return 0;
}