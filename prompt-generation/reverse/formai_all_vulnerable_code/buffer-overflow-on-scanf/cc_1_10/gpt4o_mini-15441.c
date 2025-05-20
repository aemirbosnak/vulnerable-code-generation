//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    bool movingUp;
    int requestedFloor;
} Elevator;

void initElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Start on the ground floor
    elevator->movingUp = true; // Initially, the elevator can move up
    elevator->requestedFloor = -1; // No floor requested initially
}

void requestFloor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor! Please request a floor between 0 and %d\n", MAX_FLOORS - 1);
        return;
    }
    elevator->requestedFloor = floor;
    elevator->movingUp = (floor > elevator->currentFloor);
    printf("Elevator requested to go to floor %d\n", floor);
}

void moveElevator(Elevator *elevator) {
    if (elevator->requestedFloor == -1) {
        printf("No floor has been requested.\n");
        return;
    }
    while (elevator->currentFloor != elevator->requestedFloor) {
        if (elevator->movingUp) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }
        printf("Elevator is on floor %d\n", elevator->currentFloor);
        sleep(1); // Simulate the time taken to move between floors
    }
    printf("Elevator has arrived at floor %d\n", elevator->currentFloor);
    elevator->requestedFloor = -1; // Reset the requested floor after reaching
}

void showMenu() {
    printf("\nElevator Simulation\n");
    printf("1. Request a floor\n");
    printf("2. Show current status\n");
    printf("3. Exit\n");
}

int main() {
    Elevator elevator;
    initElevator(&elevator);
    int choice, floor;

    while (true) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter floor number to request (0 to %d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                requestFloor(&elevator, floor);
                moveElevator(&elevator);
                break;
            case 2:
                printf("Current floor: %d\n", elevator.currentFloor);
                printf("Requested floor: %d\n", elevator.requestedFloor);
                printf("Moving %s\n", elevator.movingUp ? "up" : "down");
                break;
            case 3:
                printf("Exiting the simulation.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}