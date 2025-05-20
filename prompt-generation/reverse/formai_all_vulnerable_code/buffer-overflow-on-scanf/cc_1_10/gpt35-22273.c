//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 20
#define MAX_ELEVATORS 5

struct Elevator {
    int id;
    int currentFloor;
    int direction;
    bool busy;
    bool doorOpen;
};

struct ElevatorRequest {
    int requestedFloor;
};

struct Elevator elevator[MAX_ELEVATORS];
struct ElevatorRequest requestQueue[MAX_FLOORS];

int numberOfElevators = 1;
int numberOfFloors = 10;

void setupElevators() {
    srand(time(NULL));

    for(int i = 0; i < numberOfElevators; i++) {
        elevator[i].id = i;
        elevator[i].currentFloor = 1;
        elevator[i].direction = 0;
        elevator[i].busy = false;
        elevator[i].doorOpen = true;
    }
}

void requestElevator(int floorNumber) {
    int elevatorNumber = -1;

    for(int i = 0; i < numberOfElevators; i++) {
        if(!elevator[i].busy) {
            elevatorNumber = i;
            break;
        }
    }

    if(elevatorNumber == -1) {
        printf("\nAll elevators are busy right now. Please try again later.\n");
        return;
    }

    int distance = abs(elevator[elevatorNumber].currentFloor - floorNumber);

    for(int i = 0; i < numberOfElevators; i++) {
        if(!elevator[i].busy) {
            int newDistance = abs(elevator[i].currentFloor - floorNumber);

            if(newDistance < distance) {
                distance = newDistance;
                elevatorNumber = i;
            }
        }
    }

    elevator[elevatorNumber].busy = true;
    elevator[elevatorNumber].doorOpen = false;
    requestQueue[floorNumber].requestedFloor = elevatorNumber;
    printf("\nElevator %d has been dispatched to floor %d.\n", elevatorNumber, floorNumber);
}

void enterElevator(int elevatorNumber) {
    printf("\nYou have entered elevator %d at floor %d. Please press the button for your floor.\n",
     elevatorNumber, elevator[elevatorNumber].currentFloor);
}

void pressButton(int floorNumber) {
    int elevatorNumber = requestQueue[floorNumber].requestedFloor;
    printf("\nElevator %d is on its way to floor %d.\n",
     elevatorNumber, floorNumber);
}

void exitElevator(int elevatorNumber) {
    elevator[elevatorNumber].busy = false;
    elevator[elevatorNumber].doorOpen = true;
    printf("\nYou have reached your destination at floor %d. Elevator %d door is open. Please exit the elevator.\n",
     elevator[elevatorNumber].currentFloor, elevatorNumber);
}

int main() {
    setupElevators();

    while(1) {
        printf("\nEnter floor number to request elevator. Press 0 to exit.\n");
        int floorNumber;
        scanf("%d", &floorNumber);

        if(floorNumber == 0)
            break;

        if(floorNumber < 1 || floorNumber > numberOfFloors) {
            printf("\nInvalid floor number. Please try again.\n");
            continue;
        }

        requestElevator(floorNumber);

        printf("\nEnter elevator number to board. Press 0 to exit.\n");
        int elevatorNumber;
        scanf("%d", &elevatorNumber);

        if(elevatorNumber == 0)
            break;

        if(elevatorNumber < 1 || elevatorNumber > numberOfElevators) {
            printf("\nInvalid elevator number. Please try again.\n");
            continue;
        }

        enterElevator(elevatorNumber-1);

        printf("\nEnter floor number to travel to. Press 0 to exit.\n");
        scanf("%d", &floorNumber);

        if(floorNumber == 0)
            break;

        if(floorNumber < 1 || floorNumber > numberOfFloors) {
            printf("\nInvalid floor number. Please try again.\n");
            continue;
        }

        pressButton(floorNumber-1);

        while(elevator[elevatorNumber-1].currentFloor != floorNumber) {
            elevator[elevatorNumber-1].direction = (elevator[elevatorNumber-1].currentFloor < floorNumber) ? 1 : -1; 
            elevator[elevatorNumber-1].currentFloor += elevator[elevatorNumber-1].direction;
        }

        exitElevator(elevatorNumber-1);
    }

    return 0;
}