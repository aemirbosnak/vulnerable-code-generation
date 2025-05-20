//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef struct Elevator {
    int currentFloor;
    int destinationFloor;
    int passengers;
    int direction;
} Elevator;

void simulateElevator(Elevator *elevator) {
    int targetFloor;

    printf("Current floor: %d\n", elevator->currentFloor);

    printf("Enter target floor (1-10): ");
    scanf("%d", &targetFloor);

    if (targetFloor > MAX_FLOORS || targetFloor < 1) {
        printf("Invalid target floor!\n");
        return;
    }

    elevator->destinationFloor = targetFloor;
    elevator->direction = (targetFloor - elevator->currentFloor) > 0 ? 1 : -1;

    printf("Elevator moving...\n");

    // Simulate elevator movement
    for (int i = 0; i < abs(elevator->direction) * 5; i++) {
        printf(".");
        sleep(1);
    }

    elevator->currentFloor = elevator->destinationFloor;

    printf("Doors opening...\n");
    printf("Current floor: %d\n", elevator->currentFloor);
}

int main() {
    Elevator elevator;

    elevator.currentFloor = 1;
    elevator.destinationFloor = 0;
    elevator.passengers = 0;
    elevator.direction = 0;

    simulateElevator(&elevator);

    return 0;
}