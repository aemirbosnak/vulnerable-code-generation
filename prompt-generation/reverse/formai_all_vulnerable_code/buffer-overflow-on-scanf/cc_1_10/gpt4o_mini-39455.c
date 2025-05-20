//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int targetFloor;
    int direction; // 1 for up, -1 for down, 0 for idle
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0; // Ground floor
    elevator->targetFloor = 0;
    elevator->direction = 0;
}

void printStatus(Elevator elevator) {
    printf("Elevator is currently on floor %d.\n", elevator.currentFloor);
    if (elevator.direction == 1) {
        printf("Elevator is going up to floor %d.\n", elevator.targetFloor);
    } else if (elevator.direction == -1) {
        printf("Elevator is going down to floor %d.\n", elevator.targetFloor);
    } else {
        printf("Elevator is idle.\n");
    }
}

void moveElevator(Elevator *elevator) {
    if (elevator->currentFloor < elevator->targetFloor) {
        elevator->direction = 1; // Going up
        for (int i = elevator->currentFloor; i < elevator->targetFloor; i++) {
            elevator->currentFloor++;
            printStatus(*elevator);
            sleep(1); // Simulate time to move
        }
    } else if (elevator->currentFloor > elevator->targetFloor) {
        elevator->direction = -1; // Going down
        for (int i = elevator->currentFloor; i > elevator->targetFloor; i--) {
            elevator->currentFloor--;
            printStatus(*elevator);
            sleep(1); // Simulate time to move
        }
    }
    elevator->direction = 0; // Stop
}

void requestElevator(Elevator *elevator, int requestedFloor) {
    if (requestedFloor < 0 || requestedFloor >= MAX_FLOORS) {
        printf("Invalid floor selected!\n");
        return;
    }
    elevator->targetFloor = requestedFloor;
    moveElevator(elevator);
}

void displayMenu() {
    printf("\nWelcome to the Elevate-it Simulator!\n");
    printf("Request the elevator to your desired floor:\n");
    for (int i = 0; i < MAX_FLOORS; i++) {
        printf("Press %d for Floor %d\n", i, i);
    }
    printf("Press %d to Exit\n", MAX_FLOORS);
}

int main() {
    Elevator elevator;
    int requestedFloor;

    initializeElevator(&elevator);

    while (1) {
        displayMenu();
        printf("Your choice: ");
        scanf("%d", &requestedFloor);

        if (requestedFloor == MAX_FLOORS) {
            printf("Exiting the Elevator Simulator. Have a great day!\n");
            break;
        }

        requestElevator(&elevator, requestedFloor);
    }

    return 0;
}