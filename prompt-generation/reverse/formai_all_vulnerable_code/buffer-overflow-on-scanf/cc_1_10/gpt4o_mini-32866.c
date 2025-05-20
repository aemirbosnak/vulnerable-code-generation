//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct Elevator {
    int currentFloor;
    int targetFloor;
    int moving; // 1 for moving, 0 for stopped
} Elevator;

void displayStatus(Elevator* elevator) {
    printf("Elevator is currently on floor: %d\n", elevator->currentFloor);
    if (elevator->moving) {
        printf("Elevator is moving to floor: %d\n", elevator->targetFloor);
    } else {
        printf("Elevator is stopped.\n");
    }
}

void moveElevator(Elevator* elevator) {
    elevator->moving = 1;
    while (elevator->currentFloor != elevator->targetFloor) {
        if (elevator->currentFloor < elevator->targetFloor) {
            elevator->currentFloor++;
        } else {
            elevator->currentFloor--;
        }
        displayStatus(elevator);
        sleep(1); // Simulate time taken to move
    }
    elevator->moving = 0;
}

void requestFloor(Elevator* elevator) {
    int requestedFloor;
    printf("Please enter the floor number (1-%d) you want to go to: ", MAX_FLOORS);
    scanf("%d", &requestedFloor);
    
    if (requestedFloor < 1 || requestedFloor > MAX_FLOORS) {
        printf("Invalid floor number. Please try again.\n");
        return;
    }
    
    elevator->targetFloor = requestedFloor;
    moveElevator(elevator);
}

int main() {
    Elevator elevator = {1, 1, 0}; // Start on the 1st floor
    int running = 1;

    printf("Welcome to the Elevator System!\n");

    while (running) {
        displayStatus(&elevator);
        requestFloor(&elevator);
        
        char choice;
        printf("Do you want to request another floor? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice != 'y') {
            running = 0;
        }
    }

    printf("Thank you for using the Elevator System!\n");
    return 0;
}