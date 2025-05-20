//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int targetFloor;
} Elevator;

void moveElevator(Elevator *elevator, int action);
void displayStatus(Elevator elevator);
int getAction();
void chooseFloor(Elevator *elevator);
void elevatorMovement(Elevator *elevator, int floorsToMove);
void elevatorRecursive(Elevator *elevator, int floorsToMove);
void waitForUser();

int main() {
    Elevator elevator = {0, 0};
    
    printf("Welcome to the Elevator Simulation!\n");
    while (1) {
        chooseFloor(&elevator);
        moveElevator(&elevator, elevator.targetFloor);
        waitForUser();
    }
    return 0;
}

void chooseFloor(Elevator *elevator) {
    printf("\nChoose a destination floor (0 to %d): ", MAX_FLOORS - 1);
    scanf("%d", &elevator->targetFloor);
    while (elevator->targetFloor < 0 || elevator->targetFloor >= MAX_FLOORS) {
        printf("Invalid floor. Please choose a floor between 0 and %d: ", MAX_FLOORS - 1);
        scanf("%d", &elevator->targetFloor);
    }
}

void moveElevator(Elevator *elevator, int action) {
    if (elevator->currentFloor == action) {
        printf("The elevator is already on floor %d.\n", elevator->currentFloor);
        return;
    }
    
    int floorsToMove = action - elevator->currentFloor;
    elevatorRecursive(elevator, floorsToMove);
}

void elevatorRecursive(Elevator *elevator, int floorsToMove) {
    if (floorsToMove > 0) {
        elevator->currentFloor++;
        printf("Moving up to floor %d...\n", elevator->currentFloor);
        elevatorRecursive(elevator, floorsToMove - 1);
    } else if (floorsToMove < 0) {
        elevator->currentFloor--;
        printf("Moving down to floor %d...\n", elevator->currentFloor);
        elevatorRecursive(elevator, floorsToMove + 1);
    } else {
        printf("Arrived at floor %d.\n", elevator->currentFloor);
    }
}

void displayStatus(Elevator elevator) {
    printf("Current Floor: %d, Target Floor: %d\n", elevator.currentFloor, elevator.targetFloor);
}

int getAction() {
    int action;
    printf("Enter a target floor (0-%d): ", MAX_FLOORS - 1);
    scanf("%d", &action);
    return action;
}

void waitForUser() {
    char c;
    printf("Press Enter to continue...");
    while ((c = getchar()) != '\n' && c != EOF);
    getchar(); // Wait for the user to press Enter
}