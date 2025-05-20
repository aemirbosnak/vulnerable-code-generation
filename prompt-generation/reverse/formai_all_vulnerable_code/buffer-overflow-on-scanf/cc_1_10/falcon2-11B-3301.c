//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Structure to hold elevator state
typedef struct {
    int currentFloor;
    int nextFloor;
    int isMoving;
} ElevatorState;

// Function to initialize elevator state
void initializeElevator(ElevatorState* state) {
    state->currentFloor = 0;
    state->nextFloor = 0;
    state->isMoving = 0;
}

// Function to move elevator up/down
void moveElevator(ElevatorState* state) {
    if (state->isMoving) {
        return;
    }
    state->isMoving = 1;
    printf("Elevator is moving...\n");
}

// Function to handle user input
void handleInput(ElevatorState* state) {
    int choice;
    printf("Select floor to go to (0-5): ");
    scanf("%d", &choice);
    if (choice == 0) {
        state->nextFloor = 0;
    } else {
        if (choice < 0 || choice > 5) {
            printf("Invalid input! Please try again.\n");
            return;
        }
        state->nextFloor = choice;
    }
    printf("Floor selected: %d\n", state->nextFloor);
}

// Function to update elevator state
void updateElevatorState(ElevatorState* state) {
    if (state->nextFloor!= state->currentFloor &&!state->isMoving) {
        moveElevator(state);
    }
    if (state->nextFloor == state->currentFloor) {
        state->isMoving = 0;
    }
}

// Main function
int main() {
    ElevatorState elevatorState;
    initializeElevator(&elevatorState);
    while (1) {
        handleInput(&elevatorState);
        updateElevatorState(&elevatorState);
    }
    return 0;
}