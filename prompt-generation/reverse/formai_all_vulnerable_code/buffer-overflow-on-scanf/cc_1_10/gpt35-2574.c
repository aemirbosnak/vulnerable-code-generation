//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

#define FLOORS 10
#define ELEVATORS 3

typedef struct {
    int currentFloor; // current floor of elevator
    bool isMoving; // is elevator moving
} Elevator;

Elevator elevators[ELEVATORS];

bool isElevatorAtFloor(int elevator, int floor) {
    return elevators[elevator].currentFloor == floor && !elevators[elevator].isMoving;
}

void moveElevator(int elevator, int floor) {
    elevators[elevator].isMoving = true;

    if (elevators[elevator].currentFloor < floor) {
        printf("Elevator %d going up...\n", elevator);
        for (int i = elevators[elevator].currentFloor + 1; i <= floor; i++) {
            printf("Elevator %d at floor %d\n", elevator, i);
        }
    } else {
        printf("Elevator %d going down...\n", elevator);
        for (int i = elevators[elevator].currentFloor - 1; i >= floor; i--) {
            printf("Elevator %d at floor %d\n", elevator, i);
        }
    }

    elevators[elevator].currentFloor = floor;
    elevators[elevator].isMoving = false;
}

int getClosestElevator(int floor) {
    int closestElevator = 0;
    int elevatorDistance = abs(elevators[0].currentFloor - floor);

    for (int i = 1; i < ELEVATORS; i++) {
        int currentElevatorDistance = abs(elevators[i].currentFloor - floor);
        if (!elevators[i].isMoving && currentElevatorDistance < elevatorDistance) {
            closestElevator = i;
            elevatorDistance = currentElevatorDistance;
        }
    }

    return closestElevator;
}

void requestElevator(int floor) {
    int closestElevator = getClosestElevator(floor);
    printf("Elevator %d has been dispatched to floor %d\n", closestElevator, floor);
    moveElevator(closestElevator, floor);
}

void printBuilding(int selectedFloor) {
    printf("\n");
    for (int i = FLOORS - 1; i >= 0; i--) {
        printf("%2d: ", i);
        for (int j = 0; j < ELEVATORS; j++) {
            if (isElevatorAtFloor(j, i)) {
                printf("[X] ");
            } else {
                printf("[ ] ");
            }
        }
        if (selectedFloor == i) {
            printf("<-- You are here\n");
        } else {
            printf("\n");
        }
    }
    printf("------------------------\n");
}

int main() {
    int currentFloor = 0;
    int selectedFloor;

    while (true) {
        printBuilding(currentFloor);
        printf("Select a floor: ");
        scanf("%d", &selectedFloor);

        if (selectedFloor == currentFloor) {
            printf("You are already at floor %d\n", currentFloor);
        } else if (selectedFloor < 0 || selectedFloor >= FLOORS) {
            printf("Invalid floor selection\n");
        } else {
            requestElevator(selectedFloor);
            currentFloor = selectedFloor;
        }
    }

    return 0;
}