//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_FLOORS 20

bool goingUp = true, goingDown = false;
int currentFloor = 1, numberOfFloors = 0;

void simulateElevator() {
    printf("Welcome to the elevator simulator!\n");
    printf("Please enter the number of floors in the building (1-%d): ", MAX_FLOORS);
    scanf("%d", &numberOfFloors);

    int floorsInBuilding[numberOfFloors];

    for(int i = 0; i < numberOfFloors; i++) {
        floorsInBuilding[i] = i+1;
    }

    printf("\n");
    printf("The elevator is currently on the first floor.\n");

    while(true) {
        printf("The elevator is on floor %d.\n", currentFloor);
        int destinationFloor;

        if(goingUp == true) {
            destinationFloor = rand() % (numberOfFloors - currentFloor) + currentFloor + 1;
        } else {
            destinationFloor = rand() % (currentFloor - 1) + 1;
        }

        printf("The elevator is going ");

        if(goingUp == true) {
            printf("up ");
        } else {
            printf("down ");
        }

        printf("to floor %d.\n", destinationFloor);

        if(destinationFloor > currentFloor) {
            goingUp = true;
            goingDown = false;
        } else {
            goingUp = false;
            goingDown = true;
        }

        currentFloor = destinationFloor;

        if(currentFloor == numberOfFloors) {
            goingUp = false;
            goingDown = true;
        } else if(currentFloor == 1) {
            goingUp = true;
            goingDown = false;
        }

        printf("\n");

        for(int i = 0; i < numberOfFloors; i++) {
            if(currentFloor == floorsInBuilding[i]) {
                printf("Ding! The elevator has arrived at floor %d.\n", currentFloor);
                printf("\n");
                break;
            }
        }
    }
}

int main() {
    simulateElevator();
    return 0;
}