//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int targetFloor;
    int direction; // 1 for up, -1 for down, 0 for halt
} Elevator;

void printElevatorStatus(Elevator *elevator) {
    printf("Elevator is on floor: %d\n", elevator->currentFloor);
    if (elevator->direction == 1)
        printf("Elevator moving UP to floor %d\n", elevator->targetFloor);
    else if (elevator->direction == -1)
        printf("Elevator moving DOWN to floor %d\n", elevator->targetFloor);
    else
        printf("Elevator is halted at floor %d\n", elevator->currentFloor);
}

void moveElevator(Elevator *elevator) {
    while (elevator->currentFloor != elevator->targetFloor) {
        if (elevator->currentFloor < elevator->targetFloor) {
            elevator->direction = 1;
            elevator->currentFloor++;
        } else {
            elevator->direction = -1;
            elevator->currentFloor--;
        }
        printElevatorStatus(elevator);
        sleep(1); // Simulate time delay for movement
    }
    
    elevator->direction = 0; // Halt the elevator at the target floor
    printElevatorStatus(elevator);
    printf("Elevator has arrived at floor %d\n", elevator->currentFloor);
}

int main() {
    Elevator elevator = {0, 0, 0}; // Starting from ground floor
    int userFloor;

    while (1) {
        printf("Please enter the floor number you are on (0 to %d), or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &userFloor);
        
        if (userFloor == -1) {
            printf("Exiting Elevator Simulation. Goodbye!\n");
            break;
        }
        
        if (userFloor < 0 || userFloor >= MAX_FLOORS) {
            printf("Invalid floor number! Please try again.\n");
            continue;
        }

        elevator.targetFloor = userFloor;
        moveElevator(&elevator);
        
        printf("Please enter your destination floor (0 to %d): ", MAX_FLOORS - 1);
        scanf("%d", &elevator.targetFloor);
        
        if (elevator.targetFloor < 0 || elevator.targetFloor >= MAX_FLOORS) {
            printf("Invalid destination floor! Please try again.\n");
            continue;
        }

        moveElevator(&elevator);
        printf("You have reached your destination!\n");
    }

    return 0;
}