//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 20
#define MAX_PASSENGERS 15

typedef struct {
    int currentFloor;
    int destinationFloor;
    int passengerCount;
} elevator;

elevator* createElevator() {
    elevator* newElevator = (elevator*)malloc(sizeof(elevator));
    newElevator->currentFloor = 1;
    newElevator->destinationFloor = 1;
    newElevator->passengerCount = 0;
    return newElevator;
}

void moveElevator(elevator* elevator, int direction) {
    if (direction == 1) {
        elevator->currentFloor++;
    } else if (direction == -1) {
        elevator->currentFloor--;
    }
}

int checkFloor(int floor, int destinationFloor) {
    if (floor == destinationFloor) {
        return 1;
    } else {
        return 0;
    }
}

void openDoors(elevator* elevator) {
    printf("Elevator doors open on floor %d\n", elevator->currentFloor);
}

void closeDoors(elevator* elevator) {
    printf("Elevator doors close on floor %d\n", elevator->currentFloor);
}

int main() {
    elevator* myElevator = createElevator();
    int choice;
    int passengerCount = 0;

    while (1) {
        printf("Current floor: %d\n", myElevator->currentFloor);
        printf("Passenger count: %d\n", myElevator->passengerCount);
        printf("Destination floor: %d\n", myElevator->destinationFloor);

        printf("Press 1 to move up\n");
        printf("Press 2 to move down\n");
        printf("Press 3 to open doors\n");
        printf("Press 4 to close doors\n");
        printf("Press 5 to add passenger\n");
        printf("Press 6 to remove passenger\n");
        printf("Press 7 to check if at destination floor\n");
        printf("Press 8 to exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveElevator(myElevator, 1);
                break;
            case 2:
                moveElevator(myElevator, -1);
                break;
            case 3:
                openDoors(myElevator);
                break;
            case 4:
                closeDoors(myElevator);
                break;
            case 5:
                passengerCount++;
                printf("Passenger count increased to %d\n", passengerCount);
                break;
            case 6:
                passengerCount--;
                printf("Passenger count decreased to %d\n", passengerCount);
                break;
            case 7:
                if (checkFloor(myElevator->currentFloor, myElevator->destinationFloor)) {
                    printf("Elevator has reached destination floor\n");
                } else {
                    printf("Elevator has not reached destination floor\n");
                }
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}