//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int floor;
    int people;
} Elevator;

Elevator makeElevator(int floor, int people) {
    Elevator elevator;
    elevator.floor = floor;
    elevator.people = people;
    return elevator;
}

void moveElevator(Elevator* elevator, int direction) {
    if (direction == 0) {
        // Up
        elevator->floor = elevator->floor + 1;
    } else {
        // Down
        elevator->floor = elevator->floor - 1;
    }
}

void callElevator(Elevator* elevator, int floor) {
    elevator->people = elevator->people + 1;
    if (elevator->floor == floor) {
        printf("Elevator %d is on floor %d and has %d people.\n", elevator->floor, elevator->floor, elevator->people);
    }
}

void releaseElevator(Elevator* elevator) {
    elevator->people = elevator->people - 1;
    if (elevator->people == 0) {
        printf("Elevator %d has %d people.\n", elevator->floor, elevator->people);
    }
}

int main() {
    srand(time(0));
    Elevator elevator = makeElevator(5, 2);
    while (1) {
        int direction = rand() % 2;
        moveElevator(&elevator, direction);
        int floor = rand() % 10 + 1;
        callElevator(&elevator, floor);
        printf("Floor %d is calling the elevator.\n", floor);
        usleep(rand() % 100000);
        releaseElevator(&elevator);
        printf("Elevator %d has %d people.\n", elevator.floor, elevator.people);
        printf("Next floor: ");
        scanf("%d", &floor);
    }
    return 0;
}