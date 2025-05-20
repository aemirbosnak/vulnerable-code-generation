//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define FLOOR_TIME 2 // time in seconds to move between floors

typedef struct {
    int currentFloor;
    int requestedFloor;
    int direction; // 1 = up, -1 = down, 0 = idle
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0;
    elevator->requestedFloor = -1; // no request
    elevator->direction = 0; // idle
}

void displayElevatorStatus(Elevator elevator) {
    printf("Elevator is currently on floor %d\n", elevator.currentFloor);
    if (elevator.requestedFloor != -1) {
        if (elevator.direction == 1) {
            printf("Going up to floor %d\n", elevator.requestedFloor);
        } else if (elevator.direction == -1) {
            printf("Going down to floor %d\n", elevator.requestedFloor);
        }
    } else {
        printf("Waiting for a request...\n");
    }
}

void requestElevator(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request: %d\n", floor);
        return;
    }
    elevator->requestedFloor = floor;
    elevator->direction = (elevator->currentFloor < floor) ? 1 : -1;
}

void moveElevator(Elevator *elevator) {
    while (elevator->currentFloor != elevator->requestedFloor) {
        displayElevatorStatus(*elevator);
        sleep(FLOOR_TIME);
        if (elevator->direction == 1) {
            elevator->currentFloor++;
        } else if (elevator->direction == -1) {
            elevator->currentFloor--;
        }
    }
    printf("Elevator has arrived at floor %d\n", elevator->currentFloor);
    elevator->requestedFloor = -1; // reset request
    elevator->direction = 0; // idle
}

void showMenu() {
    printf("Elevator Simulation Menu:\n");
    printf("1. Request Elevator to a Floor\n");
    printf("2. Exit Simulation\n");
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);

    int choice, floor;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the floor number (0 to %d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                requestElevator(&elevator, floor);
                moveElevator(&elevator);
                break;
            case 2:
                printf("Exiting Elevator Simulation. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}