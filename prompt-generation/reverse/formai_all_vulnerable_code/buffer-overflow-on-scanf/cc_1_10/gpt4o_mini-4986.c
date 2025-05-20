//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct Elevator {
    int currentFloor;
    int targetFloor;
    bool movingUp;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Ground floor
    elevator->targetFloor = 0;
    elevator->movingUp = false;
}

void requestFloor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor! Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
        return;
    }
    elevator->targetFloor = floor;
    elevator->movingUp = (floor > elevator->currentFloor);
}

void moveElevator(Elevator *elevator) {
    while (elevator->currentFloor != elevator->targetFloor) {
        if (elevator->movingUp) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }
        printf("Elevator is on floor %d\n", elevator->currentFloor);
        sleep(1); // Simulating time taken to move between floors
    }
    printf("Elevator has arrived at floor %d\n", elevator->currentFloor);
}

void printMenu() {
    printf("\n--------- Elevator Simulation ---------\n");
    printf("1. Request Elevator to Floor\n");
    printf("2. Exit\n");
    printf("--------------------------------------\n");
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    
    while (true) {
        printMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int requestedFloor;
            printf("Enter the floor number you wish to go to (0 - %d): ", MAX_FLOORS - 1);
            scanf("%d", &requestedFloor);
            requestFloor(&elevator, requestedFloor);
            moveElevator(&elevator);
        } else if (choice == 2) {
            printf("Exiting the elevator simulation. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}