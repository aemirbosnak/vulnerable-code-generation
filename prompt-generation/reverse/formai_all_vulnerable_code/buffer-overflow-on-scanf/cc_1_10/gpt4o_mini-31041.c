//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int requestedFloor;
    bool movingUp;
} Elevator;

void printElevatorStatus(Elevator elevator) {
    printf("Elevator is currently at floor %d.\n", elevator.currentFloor);
    if (elevator.requestedFloor != -1) {
        printf("Elevator will go to floor %d.\n", elevator.requestedFloor);
    }
}

void moveToFloor(Elevator *elevator) {
    if (elevator->requestedFloor == -1) {
        printf("No floor requested.\n");
        return;
    }

    if (elevator->currentFloor < elevator->requestedFloor) {
        elevator->movingUp = true;
        printf("Elevator is moving up...\n");
        while (elevator->currentFloor < elevator->requestedFloor) {
            elevator->currentFloor++;
            printElevatorStatus(*elevator);
        }
    } else {
        elevator->movingUp = false;
        printf("Elevator is moving down...\n");
        while (elevator->currentFloor > elevator->requestedFloor) {
            elevator->currentFloor--;
            printElevatorStatus(*elevator);
        }
    }
    elevator->requestedFloor = -1; // Reset the requested floor after reaching
}

int main() {
    Elevator elevator = {0, -1, true};
    int choice;

    printf("Welcome to the Elevator Simulation!\n");
    
    while (true) {
        printf("\n--- Elevator Control Panel ---\n");
        printElevatorStatus(elevator);
        printf("1. Call Elevator\n");
        printf("2. Request Floor (0 to %d)\n", MAX_FLOORS - 1);
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the simulation. Goodbye!\n");
            break;
        } else if (choice == 1) {
            printf("Elevator has been called.\n");
            continue;
        } else if (choice == 2) {
            int floor;
            printf("Enter the floor you want to go to (0 to %d): ", MAX_FLOORS - 1);
            scanf("%d", &floor);

            if (floor < 0 || floor >= MAX_FLOORS) {
                printf("Invalid floor selection.\n");
                continue;
            }

            elevator.requestedFloor = floor;
            moveToFloor(&elevator);
        } else {
            printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}