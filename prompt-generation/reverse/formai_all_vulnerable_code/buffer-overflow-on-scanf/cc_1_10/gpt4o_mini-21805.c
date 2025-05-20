//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 50

typedef enum { IDLE, MOVING_UP, MOVING_DOWN } ElevatorState;

typedef struct {
    int currentFloor;
    ElevatorState state;
    int requests[MAX_REQUESTS];
    int requestCount;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Ground floor
    elevator->state = IDLE;
    elevator->requestCount = 0;
}

void callElevator(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor number: %d\n", floor);
        return;
    }
    elevator->requests[elevator->requestCount++] = floor;
    printf("Elevator requested at floor %d.\n", floor);
}

void moveElevator(Elevator *elevator) {
    if (elevator->requestCount == 0) {
        elevator->state = IDLE;
        return;
    }

    int targetFloor = elevator->requests[0];
    if (elevator->currentFloor < targetFloor) {
        elevator->state = MOVING_UP;
        elevator->currentFloor++;
    } else if (elevator->currentFloor > targetFloor) {
        elevator->state = MOVING_DOWN;
        elevator->currentFloor--;
    } else {
        printf("Elevator reached floor %d.\n", targetFloor);
        elevator->state = IDLE;
        
        // Remove the served request
        for (int i = 1; i < elevator->requestCount; i++) {
            elevator->requests[i-1] = elevator->requests[i];
        }
        elevator->requestCount--;
    }
}

void displayStatus(Elevator elevator) {
    printf("Elevator is on floor %d, state: ", elevator.currentFloor);
    switch (elevator.state) {
        case IDLE: printf("IDLE\n"); break;
        case MOVING_UP: printf("MOVING UP\n"); break;
        case MOVING_DOWN: printf("MOVING DOWN\n"); break;
    }
}

void simulateElevator() {
    Elevator elevator;
    initializeElevator(&elevator);

    int choice;
    while (true) {
        displayStatus(elevator);
        printf("Enter floor number to call the elevator (0 to %d), or -1 to exit: ", MAX_FLOORS-1);
        scanf("%d", &choice);

        if (choice == -1) {
            printf("Exiting simulation.\n");
            break;
        }

        callElevator(&elevator, choice);
        while (elevator.state != IDLE) {
            moveElevator(&elevator);
            usleep(500000); // Sleep for 500 milliseconds
        }
    }
}

int main() {
    simulateElevator();
    return 0;
}