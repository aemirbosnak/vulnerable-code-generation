//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef enum {
    IDLE,
    MOVING_UP,
    MOVING_DOWN
} ElevatorState;

typedef struct {
    int currentFloor;
    ElevatorState state;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0;  // Start on the ground floor
    elevator->state = IDLE;
}

void displayMenu() {
    printf("Elevator Simulation Menu:\n");
    printf("0: Exit\n");
    for (int i = 1; i <= MAX_FLOORS; i++) {
        printf("%d: Go to Floor %d\n", i, i);
    }
}

void moveElevator(Elevator *elevator, int requestedFloor) {
    if (requestedFloor < 0 || requestedFloor > MAX_FLOORS) {
        printf("Invalid floor number!\n");
        return;
    }

    if (elevator->currentFloor < requestedFloor) {
        elevator->state = MOVING_UP;
        while (elevator->currentFloor < requestedFloor) {
            printf("Elevator is on floor %d\n", elevator->currentFloor);
            sleep(1);
            elevator->currentFloor++;
        }
    } else if (elevator->currentFloor > requestedFloor) {
        elevator->state = MOVING_DOWN;
        while (elevator->currentFloor > requestedFloor) {
            printf("Elevator is on floor %d\n", elevator->currentFloor);
            sleep(1);
            elevator->currentFloor--;
        }
    }

    printf("Elevator has arrived at floor %d\n", elevator->currentFloor);
    elevator->state = IDLE;
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    
    int requestedFloor;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &requestedFloor);

        if (requestedFloor == 0) {
            printf("Exiting the elevator simulation. Goodbye!\n");
            break;
        }

        if (requestedFloor > 0 && requestedFloor <= MAX_FLOORS) {
            moveElevator(&elevator, requestedFloor);
        } else {
            printf("Please select a valid floor (0-%d).\n", MAX_FLOORS);
        }
    }

    return 0;
}