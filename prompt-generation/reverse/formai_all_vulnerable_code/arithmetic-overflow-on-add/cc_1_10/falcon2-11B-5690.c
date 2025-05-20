//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 5
#define MAX_PASSENGERS 3

typedef struct {
    int floor;
    int passengers;
} Passenger;

typedef struct {
    int currentFloor;
    int currentPassengers;
    Passenger passengers[MAX_PASSENGERS];
    int elevatorState;
} Elevator;

void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = 0;
    elevator->currentPassengers = 0;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        elevator->passengers[i].floor = 0;
        elevator->passengers[i].passengers = 0;
    }
    elevator->elevatorState = 0;
}

void moveUp(Elevator* elevator) {
    elevator->currentFloor++;
    if (elevator->currentFloor == MAX_FLOORS) {
        elevator->currentFloor = 0;
    }
    printf("Elevator moved to floor %d\n", elevator->currentFloor);
}

void moveDown(Elevator* elevator) {
    elevator->currentFloor--;
    if (elevator->currentFloor == -1) {
        elevator->currentFloor = MAX_FLOORS - 1;
    }
    printf("Elevator moved to floor %d\n", elevator->currentFloor);
}

void addPassenger(Elevator* elevator) {
    elevator->currentPassengers++;
    if (elevator->currentPassengers > MAX_PASSENGERS) {
        printf("Elevator is full, no more passengers can be added.\n");
        return;
    }
    elevator->passengers[elevator->currentPassengers - 1].passengers++;
    printf("Passenger added to elevator.\n");
}

void removePassenger(Elevator* elevator) {
    elevator->currentPassengers--;
    elevator->passengers[elevator->currentPassengers - 1].passengers--;
    if (elevator->passengers[elevator->currentPassengers - 1].passengers == 0) {
        elevator->passengers[elevator->currentPassengers - 1].floor = 0;
    }
    printf("Passenger removed from elevator.\n");
}

void startElevator(Elevator* elevator) {
    int choice;
    while (elevator->currentPassengers < MAX_PASSENGERS) {
        printf("What would you like to do?\n");
        printf("1. Add a passenger\n");
        printf("2. Remove a passenger\n");
        printf("3. Move up\n");
        printf("4. Move down\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassenger(elevator);
                break;
            case 2:
                removePassenger(elevator);
                break;
            case 3:
                moveUp(elevator);
                break;
            case 4:
                moveDown(elevator);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    printf("Elevator simulation finished.\n");
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    startElevator(&elevator);
    return 0;
}