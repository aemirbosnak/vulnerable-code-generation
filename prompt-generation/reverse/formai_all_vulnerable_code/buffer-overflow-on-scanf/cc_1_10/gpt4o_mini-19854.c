//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int requestedFloor;
    int direction; // 1 for up, -1 for down, 0 for idle
} Elevator;

void moveElevator(Elevator *elevator) {
    if (elevator->currentFloor < elevator->requestedFloor) {
        elevator->direction = 1;
        while (elevator->currentFloor < elevator->requestedFloor) {
            sleep(1); // simulate time taken to move
            elevator->currentFloor++;
            printf("Elevator moving up to floor: %d\n", elevator->currentFloor);
        }
    } else if (elevator->currentFloor > elevator->requestedFloor) {
        elevator->direction = -1;
        while (elevator->currentFloor > elevator->requestedFloor) {
            sleep(1); // simulate time taken to move
            elevator->currentFloor--;
            printf("Elevator moving down to floor: %d\n", elevator->currentFloor);
        }
    }
    elevator->direction = 0; // reset direction to idle
}

void callElevator(Elevator *elevator, int floor) {
    if (floor < 1 || floor > MAX_FLOORS) {
        printf("Invalid floor number! Please select a floor between 1 and %d.\n", MAX_FLOORS);
        return;
    }
    elevator->requestedFloor = floor;
    printf("Elevator called to floor: %d\n", floor);
    moveElevator(elevator);
    printf("Elevator has arrived at floor: %d\n", elevator->currentFloor);
}

void printMenu() {
    printf("\nElevator Simulation Menu:\n");
    for (int i = 1; i <= MAX_FLOORS; i++) {
        printf("Press %d to call the elevator to floor %d\n", i, i);
    }
    printf("Press 0 to exit the simulation.\n");
}

int main() {
    Elevator elevator = {1, 1, 0}; // Start on floor 1
    int choice;

    printf("Welcome to the Elevator Simulation!\n");

    while (1) {
        printMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the simulation. Goodbye!\n");
            break;
        } else {
            callElevator(&elevator, choice);
        }
    }

    return 0;
}