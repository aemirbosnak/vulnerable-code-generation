//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int direction; // 1 for up, -1 for down, 0 for idle
} Elevator;

void displayElevatorStatus(Elevator *elevator) {
    printf("\nCurrent Floor: %d", elevator->currentFloor);
    if (elevator->direction == 1) {
        printf(" [Going Up]\n");
    } else if (elevator->direction == -1) {
        printf(" [Going Down]\n");
    } else {
        printf(" [Idle]\n");
    }
}

void moveElevator(Elevator *elevator, int targetFloor) {
    printf("Elevator is moving...\n");
    // Move the elevator step by step
    while (elevator->currentFloor != targetFloor) {
        if (targetFloor > elevator->currentFloor) {
            elevator->direction = 1;
            elevator->currentFloor++;
        } else {
            elevator->direction = -1;
            elevator->currentFloor--;
        }
        displayElevatorStatus(elevator);
        sleep(1); // Simulate time taken to move to the next floor
    }
    elevator->direction = 0; // Set to idle when target is reached
    printf("Ding! You've arrived at floor %d!\n", targetFloor);
    sleep(1);
}

int main() {
    Elevator elevator = {1, 0}; // Start on the first floor
    int targetFloor;
    
    printf("🎉 Welcome to the Cheerful Elevator Simulation! 🎉\n");
    printf("This building has %d floors! 🚪\n", MAX_FLOORS);
    
    while (1) {
        printf("\nPlease select a floor (1-%d) or 0 to exit: ", MAX_FLOORS);
        scanf("%d", &targetFloor);

        if (targetFloor == 0) {
            printf("Thank you for using the Cheerful Elevator! Bye-bye! 👋\n");
            exit(0);
        } else if (targetFloor < 1 || targetFloor > MAX_FLOORS) {
            printf("Oops! That's not a valid floor. Please try again! 😊\n");
            continue;
        }

        if (targetFloor == elevator.currentFloor) {
            printf("You are already on floor %d! No need to move! 😄\n", targetFloor);
        } else {
            moveElevator(&elevator, targetFloor);
        }
    }
    
    return 0;
}