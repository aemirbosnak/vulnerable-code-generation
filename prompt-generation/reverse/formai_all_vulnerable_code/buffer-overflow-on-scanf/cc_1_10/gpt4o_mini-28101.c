//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct {
    int currentFloor;
    int destinationFloor;
    bool isMoving;
} Elevator;

void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = 0; // Start at floor 0
    elevator->destinationFloor = 0;
    elevator->isMoving = false;
}

void displayElevatorStatus(Elevator* elevator) {
    printf("Elevator is currently at floor %d\n", elevator->currentFloor);
}

void moveElevator(Elevator* elevator) {
    if (elevator->destinationFloor == elevator->currentFloor) {
        printf("Elevator has arrived at floor %d. Thank you for riding with us!\n", elevator->currentFloor);
        return;
    }

    elevator->isMoving = true;
    while (elevator->currentFloor != elevator->destinationFloor) {
        if (elevator->destinationFloor > elevator->currentFloor) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }

        displayElevatorStatus(elevator);
        sleep(1); // Simulate waiting time for the elevator movement
    }
    elevator->isMoving = false;
}

void requestElevator(Elevator* elevator, int desiredFloor) {
    if (desiredFloor < 0 || desiredFloor >= MAX_FLOORS) {
        printf("Invalid floor request. Please choose between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    
    elevator->destinationFloor = desiredFloor;
    printf("Request received to go to floor %d! Let's make that happen!\n", desiredFloor);
    moveElevator(elevator);
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);

    int choice;
    printf("Welcome to the grateful Elevator System!\n");
    printf("Please choose your destination floor (0-%d):\n", MAX_FLOORS - 1);

    while (1) {
        printf("Enter floor number (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using our elevator! Have a great day!\n");
            break;
        }

        requestElevator(&elevator, choice);
        printf("Thank you for your patience!\n");
    }

    return 0;
}