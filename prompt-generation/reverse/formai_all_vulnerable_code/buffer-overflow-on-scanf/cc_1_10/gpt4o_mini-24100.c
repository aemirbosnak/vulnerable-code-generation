//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define BUTTON_WAIT_TIME 1 // Time to simulate wait on button press

typedef struct {
    int currentFloor;
    bool isMoving;
} Elevator;

void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = 0; // Ground floor
    elevator->isMoving = false;
}

void displayStatus(Elevator elevator) {
    printf("Elevator is currently on floor %d.\n", elevator.currentFloor);
    if (elevator.isMoving) {
        printf("The elevator is moving...\n");
    } else {
        printf("The elevator is stationary.\n");
    }
}

void moveElevator(Elevator* elevator, int destinationFloor) {
    if (destinationFloor < 0 || destinationFloor >= MAX_FLOORS) {
        printf("Invalid floor requested!\n");
        return;
    }

    elevator->isMoving = true;
    while (elevator->currentFloor != destinationFloor) {
        sleep(1); // Simulate time taken to move
        elevator->currentFloor += (destinationFloor > elevator->currentFloor) ? 1 : -1;
        displayStatus(*elevator);
    }
    elevator->isMoving = false;
    printf("Elevator has arrived at floor %d.\n", elevator->currentFloor);
}

void requestFloor(Elevator* elevator) {
    int requestedFloor;

    printf("Select a floor (0 to %d): ", MAX_FLOORS - 1);
    scanf("%d", &requestedFloor);
    printf("You pressed the button for floor %d.\n", requestedFloor);
    sleep(BUTTON_WAIT_TIME); // Simulate waiting for the button press effect
    moveElevator(elevator, requestedFloor);
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    int command;

    while (true) {
        printf("\nElevator Control System\n");
        displayStatus(elevator);
        printf("1. Request floor\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                requestFloor(&elevator);
                break;
            case 2:
                printf("Exiting Elevator Control System.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}