//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int floor;
    int direction;
    int speed;
    int currentFloor;
} elevator;

void initializeElevator(elevator* elevator) {
    elevator->floor = 0;
    elevator->direction = 0;
    elevator->speed = 0;
    elevator->currentFloor = 0;
}

void moveElevator(elevator* elevator, int direction) {
    elevator->direction = direction;
    elevator->speed = 1;
}

void updateElevator(elevator* elevator, int direction, int speed) {
    elevator->speed = speed;
    elevator->direction = direction;
}

int main() {
    srand(time(0)); // Seed random number generator

    elevator elevator1;
    initializeElevator(&elevator1);

    int direction = 0;
    int speed = 1;

    while (1) {
        printf("Current floor: %d\n", elevator1.currentFloor);
        printf("Enter direction (up/down): ");
        scanf("%d", &direction);
        printf("Enter speed (1/2/3/4): ");
        scanf("%d", &speed);

        updateElevator(&elevator1, direction, speed);

        if (elevator1.currentFloor == 0 || elevator1.currentFloor == 10) {
            break;
        }
    }

    return 0;
}