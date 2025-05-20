//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 20
#define MAX_PASSENGERS 10

typedef struct {
    int floor;
    int destination;
} Passenger;

typedef struct {
    int currentFloor;
    int direction;
    Passenger passengers[MAX_PASSENGERS];
    int numPassengers;
} Elevator;

void initializePassengers(Elevator* elevator) {
    int i;
    for (i = 0; i < MAX_PASSENGERS; i++) {
        elevator->passengers[i].floor = rand() % MAX_FLOORS;
        elevator->passengers[i].destination = rand() % MAX_FLOORS;
    }
    elevator->numPassengers = rand() % MAX_PASSENGERS;
}

void printElevator(Elevator* elevator) {
    int i;
    printf("Elevator at floor %d, going %s:\n", elevator->currentFloor, (elevator->direction == 1)? "up" : "down");
    for (i = 0; i < elevator->numPassengers; i++) {
        printf("  Passenger %d going to floor %d\n", i+1, elevator->passengers[i].destination);
    }
}

void moveElevator(Elevator* elevator) {
    if (elevator->direction == 1) {
        elevator->currentFloor++;
    } else {
        elevator->currentFloor--;
    }
    if (elevator->currentFloor == elevator->passengers[0].destination) {
        elevator->passengers[0].floor = elevator->currentFloor;
        elevator->numPassengers--;
        if (elevator->numPassengers == 0) {
            elevator->direction = (elevator->direction == 1)? -1 : 1;
        }
    }
}

int main() {
    srand(time(NULL));
    Elevator elevator;
    initializePassengers(&elevator);
    while (elevator.numPassengers > 0) {
        printElevator(&elevator);
        moveElevator(&elevator);
    }
    return 0;
}