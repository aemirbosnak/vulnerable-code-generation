//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define FLOOR_COUNT 10

typedef struct Elevator {
    int currentFloor;
    int targetFloor;
    bool goingUp;
    bool doorOpen;
} Elevator;

void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 0;
    elevator->targetFloor = 0;
    elevator->goingUp = true;
    elevator->doorOpen = false;
}

void requestFloor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= FLOOR_COUNT) {
        printf("Invalid floor request: %d\n", floor);
        return;
    }

    elevator->targetFloor = floor;
    elevator->goingUp = elevator->targetFloor > elevator->currentFloor;
}

void moveElevator(Elevator *elevator) {
    while (elevator->currentFloor != elevator->targetFloor) {
        if (elevator->goingUp) {
            elevator->currentFloor++;
            printf("Elevator moving up to floor %d...\n", elevator->currentFloor);
        } else {
            elevator->currentFloor--;
            printf("Elevator moving down to floor %d...\n", elevator->currentFloor);
        }
        sleep(1); // Simulate time taken to move
    }
}

void openDoor(Elevator *elevator) {
    elevator->doorOpen = true;
    printf("Ding! Doors opening at floor %d...\n", elevator->currentFloor);
    sleep(2); // Doors stay open for a while
}

void closeDoor(Elevator *elevator) {
    elevator->doorOpen = false;
    printf("Doors closing...\n");
    sleep(1); // Simulate time for doors to close
}

void simulateElevator(Elevator *elevator) {
    char command;
    int requestedFloor;

    while (true) {
        printf("Current floor: %d\n", elevator->currentFloor);
        printf("Open doors: %s\n", elevator->doorOpen ? "Yes" : "No");
        printf("Enter 'r' to request a floor (0-%d), or 'q' to quit: ", FLOOR_COUNT - 1);
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Exiting Elevator Simulator. Goodbye!\n");
            break;
        } else if (command == 'r') {
            printf("Enter target floor (0-%d): ", FLOOR_COUNT - 1);
            scanf("%d", &requestedFloor);
            requestFloor(elevator, requestedFloor);
            closeDoor(elevator);
            moveElevator(elevator);
            openDoor(elevator);
        } else {
            printf("Invalid command. Please try again!\n");
        }
    }
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    printf("Welcome to the Elevator Simulation!\n");
    simulateElevator(&elevator);
    return 0;
}