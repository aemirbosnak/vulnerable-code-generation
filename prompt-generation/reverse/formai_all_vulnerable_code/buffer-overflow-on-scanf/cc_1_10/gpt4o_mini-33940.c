//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOORS 10

typedef struct {
    int currentFloor;
    int destinationFloor;
    int direction; // 1 for up, -1 for down, 0 for idle
} Elevator;

void printElevatorStatus(Elevator *elev) {
    printf("Elevator is currently on floor %d.\n", elev->currentFloor);
    if (elev->direction == 1) {
        printf("Elevator is moving up to floor %d.\n", elev->destinationFloor);
    } else if (elev->direction == -1) {
        printf("Elevator is moving down to floor %d.\n", elev->destinationFloor);
    } else {
        printf("Elevator is idle.\n");
    }
}

void moveElevator(Elevator *elev) {
    while (elev->currentFloor != elev->destinationFloor) {
        if (elev->currentFloor < elev->destinationFloor) {
            elev->currentFloor++;
            elev->direction = 1;
        } else {
            elev->currentFloor--;
            elev->direction = -1;
        }
        printElevatorStatus(elev);
        sleep(1);
    }
    elev->direction = 0; // Set direction to idle
    printf("Elevator has arrived at floor %d. Doors opening...\n", elev->currentFloor);
    sleep(2);
    printf("Doors closing...\n");
}

void summonElevator(Elevator *elev) {
    int floor;
    printf("Which floor do you want to go to (0-%d)? ", MAX_FLOORS - 1);
    scanf("%d", &floor);

    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor selection. Please try again.\n");
        summonElevator(elev);
        return;
    }

    elev->destinationFloor = floor;
    moveElevator(elev);
}

int main() {
    Elevator elev = {0, 0, 0}; // Initialize the elevator at floor 0, idle

    printf("Welcome to the Elevator Simulation!\n");

    while (1) {
        printElevatorStatus(&elev);
        printf("Do you want to summon the elevator to a floor? (1 for Yes, 0 for No): ");
        int input;
        scanf("%d", &input);

        if (input == 1) {
            summonElevator(&elev);
        } else {
            printf("Thank you for using the elevator. Exiting...\n");
            break;
        }
    }

    return 0;
}