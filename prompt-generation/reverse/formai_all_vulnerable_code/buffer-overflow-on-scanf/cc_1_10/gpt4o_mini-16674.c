//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10
#define ELEVATOR_INIT_FLOWER 1
#define ELEVATOR_IDLE 0

typedef struct {
    int currentFloor;
    bool direction; // false for down, true for up
} Elevator;

typedef struct {
    int requestFloor;
    bool direction; // true for up, false for down.
} Request;

void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = ELEVATOR_INIT_FLOWER;
    elevator->direction = ELEVATOR_IDLE;
}

void printStatus(Elevator* elevator) {
    printf("Elevator is on floor %d, Moving %s\n", elevator->currentFloor, 
          elevator->direction ? "upward" : "downward");
}

void moveElevator(Elevator* elevator, int targetFloor) {
    if (targetFloor < 1 || targetFloor > MAX_FLOORS) {
        printf("Invalid target floor: %d\n", targetFloor);
        return;
    }

    while (elevator->currentFloor != targetFloor) {
        if (elevator->currentFloor < targetFloor) {
            elevator->direction = true;
            elevator->currentFloor++;
        } else {
            elevator->direction = false;
            elevator->currentFloor--;
        }
        printStatus(elevator);
        sleep(1); // Simulate time taken to move
    }

    printf("Elevator has arrived at floor %d\n", elevator->currentFloor);
    elevator->direction = ELEVATOR_IDLE; // Stop moving
}

void requestElevator(Elevator* elevator, int requestedFloor) {
    if (requestedFloor < 1 || requestedFloor > MAX_FLOORS) {
        printf("Floor request out of range: %d\n", requestedFloor);
        return;
    }
    printf("Elevator requested at floor %d\n", requestedFloor);
    moveElevator(elevator, requestedFloor);
}

void showMenu() {
    printf("\n=== Elevator Control System ===\n");
    printf("1. Request Elevator\n");
    printf("2. Exit\n");
    printf("==============================\n");
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);

    int choice, requestedFloor;

    srand(time(0)); // Seed for randomness

    while (true) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                requestedFloor = rand() % MAX_FLOORS + 1; // Random floor request
                requestElevator(&elevator, requestedFloor);
                break;
            case 2:
                printf("Exiting the Elevator Control System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0; // Should never reach here
}