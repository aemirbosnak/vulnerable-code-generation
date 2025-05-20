//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define BUTTON_COUNT 4

typedef struct Elevator {
    int currentFloor;
    int targetFloor;
    int direction;
    int passengers;
    int buttonPressed;
} Elevator;

Elevator elevator;

void simulate() {
    time_t tStart = time(NULL);
    while (time(NULL) - tStart < 5) {
        // Check if the elevator is at the target floor.
        if (elevator.currentFloor == elevator.targetFloor) {
            // Doors open.
            printf("Doors open on floor %d.\n", elevator.currentFloor);
            elevator.passengers = 0;
            elevator.buttonPressed = 0;
        } else {
            // Move the elevator in the direction of the target floor.
            if (elevator.direction == 1) {
                elevator.currentFloor++;
            } else if (elevator.direction == -1) {
                elevator.currentFloor--;
            }

            // Update the time.
            time_t tEnd = time(NULL);
            printf("Time elapsed: %ld seconds.\n", tEnd - tStart);
        }
    }
}

int main() {
    // Initialize the elevator.
    elevator.currentFloor = 1;
    elevator.targetFloor = 5;
    elevator.direction = 1;
    elevator.passengers = 0;
    elevator.buttonPressed = 0;

    // Simulate the elevator.
    simulate();

    return 0;
}