//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 20
#define MAX_PASSENGERS 10
#define MAX_WAIT_TIME 10

typedef struct {
    int destination;
    int waitTime;
} passenger;

typedef struct {
    int currentFloor;
    int destinationFloor;
    int waitTime;
} elevator;

passenger passengers[MAX_PASSENGERS];
elevator elevators[MAX_FLOORS];

void initializePassengers() {
    int i;
    for (i = 0; i < MAX_PASSENGERS; i++) {
        passengers[i].destination = rand() % MAX_FLOORS + 1;
        passengers[i].waitTime = rand() % MAX_WAIT_TIME + 1;
    }
}

void initializeElevators() {
    int i;
    for (i = 0; i < MAX_FLOORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].destinationFloor = 0;
        elevators[i].waitTime = 0;
    }
}

void printElevatorStatus() {
    int i;
    printf("Elevator Status:\n");
    for (i = 0; i < MAX_FLOORS; i++) {
        if (elevators[i].currentFloor!= 0) {
            printf("Elevator %d: Current Floor %d, Destination Floor %d, Wait Time %d\n", i+1, elevators[i].currentFloor, elevators[i].destinationFloor, elevators[i].waitTime);
        }
    }
}

void moveElevator(int elevatorNumber, int destinationFloor) {
    elevators[elevatorNumber-1].destinationFloor = destinationFloor;
}

void movePassenger(int passengerNumber) {
    int elevatorNumber = rand() % MAX_FLOORS;
    int waitTime = rand() % MAX_WAIT_TIME + 1;
    elevators[elevatorNumber-1].waitTime += waitTime;
    elevators[elevatorNumber-1].destinationFloor = passengers[passengerNumber-1].destination;
    passengers[passengerNumber-1].waitTime += waitTime;
}

void main() {
    srand(time(NULL));
    initializePassengers();
    initializeElevators();

    int i;
    for (i = 0; i < MAX_PASSENGERS; i++) {
        movePassenger(i+1);
    }

    while(1) {
        printElevatorStatus();
        system("clear");
        sleep(1);
    }
}